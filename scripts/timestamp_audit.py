#!/usr/bin/env python3

import csv
import json
import math
import os
import time
from collections import defaultdict, deque
from dataclasses import dataclass, field
from datetime import datetime
from functools import partial
from typing import Deque, Dict, List, Optional

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, qos_profile_sensor_data
from rosidl_runtime_py.utilities import get_message


DEFAULT_OUTPUT_ROOT = "/opt/asv/logs/timestamp_audit"


@dataclass
class SampleRecord:
    sequence: int
    header_ns: Optional[int]
    receipt_ros_ns: int
    receipt_wall_ns: int


@dataclass
class SourceState:
    name: str
    topic: str
    msg_type: str
    qos_name: str
    samples: Deque[SampleRecord] = field(default_factory=deque)
    total_messages: int = 0
    total_headerless_messages: int = 0
    warned_headerless: bool = False


@dataclass(frozen=True)
class PairConfig:
    name: str
    lhs: str
    rhs: str
    trigger: str
    mode: str
    max_delta_ms: float


@dataclass
class PairState:
    config: PairConfig
    total_matches: int = 0
    total_misses: int = 0


def stamp_to_ns(stamp) -> Optional[int]:
    if stamp is None:
        return None
    if not hasattr(stamp, "sec") or not hasattr(stamp, "nanosec"):
        return None
    return int(stamp.sec) * 1_000_000_000 + int(stamp.nanosec)


def percentile(sorted_values: List[float], fraction: float) -> float:
    if not sorted_values:
        return float("nan")
    if len(sorted_values) == 1:
        return sorted_values[0]
    index = (len(sorted_values) - 1) * fraction
    lower = math.floor(index)
    upper = math.ceil(index)
    if lower == upper:
        return sorted_values[lower]
    weight = index - lower
    return sorted_values[lower] * (1.0 - weight) + sorted_values[upper] * weight


def summarize(values: Deque[float]) -> Optional[Dict[str, float]]:
    if not values:
        return None
    ordered = sorted(values)
    count = len(ordered)
    mean = sum(ordered) / count
    if count > 1:
        variance = sum((value - mean) ** 2 for value in ordered) / count
    else:
        variance = 0.0
    return {
        "count": float(count),
        "mean": mean,
        "std": math.sqrt(variance),
        "p50": percentile(ordered, 0.50),
        "p95": percentile(ordered, 0.95),
        "max_abs": max(abs(value) for value in ordered),
        "min": ordered[0],
        "max": ordered[-1],
    }


class TimestampAuditNode(Node):
    def __init__(self):
        super().__init__("timestamp_audit")

        self._declare_parameters()

        self.output_dir = self.get_parameter("output_dir").value or self._default_output_dir()
        self.history_size = max(10, int(self.get_parameter("history_size").value))
        self.summary_window_size = max(10, int(self.get_parameter("summary_window_size").value))
        self.summary_period_sec = max(1.0, float(self.get_parameter("summary_period_sec").value))
        self.general_pair_window_ms = max(1.0, float(self.get_parameter("general_pair_window_ms").value))
        self.command_pair_window_ms = max(1.0, float(self.get_parameter("command_pair_window_ms").value))

        os.makedirs(self.output_dir, exist_ok=True)
        self._open_output_files()

        self.sources: Dict[str, SourceState] = {}
        self._audit_subscriptions = []
        self.metric_windows: Dict[str, Deque[float]] = defaultdict(lambda: deque(maxlen=self.summary_window_size))
        self.metric_totals: Dict[str, int] = defaultdict(int)
        self.pair_states: Dict[str, PairState] = {}
        self.pairs_by_trigger: Dict[str, List[PairState]] = defaultdict(list)

        self._configure_sources()
        self._configure_pairs()
        self._write_config_snapshot()

        self.summary_timer = self.create_timer(self.summary_period_sec, self._emit_summary)

        self.get_logger().info(
            f"Timestamp audit is writing logs to {self.output_dir}. "
            "Receipt timestamps are subscriber callback times on this node."
        )

    def _declare_parameters(self):
        self.declare_parameter("output_dir", "")
        self.declare_parameter("history_size", 2000)
        self.declare_parameter("summary_window_size", 500)
        self.declare_parameter("summary_period_sec", 5.0)
        self.declare_parameter("general_pair_window_ms", 250.0)
        self.declare_parameter("command_pair_window_ms", 2000.0)

        self.declare_parameter("lidar_topic", "/sensors/lidar/points")
        self.declare_parameter("lidar_msg_type", "sensor_msgs/msg/PointCloud2")
        self.declare_parameter("camera_topic", "/sensors/camera/color/image_raw")
        self.declare_parameter("camera_msg_type", "sensor_msgs/msg/Image")
        self.declare_parameter("pose_topic", "/gt_pose")
        self.declare_parameter("pose_msg_type", "geometry_msgs/msg/PoseStamped")
        self.declare_parameter("imu_topic", "/vectornav/imu")
        self.declare_parameter("imu_msg_type", "sensor_msgs/msg/Imu")
        self.declare_parameter("state_twist_topic", "/wamv/inekf_odom_correction/twist")
        self.declare_parameter("state_twist_msg_type", "geometry_msgs/msg/TwistStamped")
        self.declare_parameter("command_topic", "")
        self.declare_parameter("command_msg_type", "geometry_msgs/msg/TwistStamped")

    def _default_output_dir(self) -> str:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        return os.path.join(DEFAULT_OUTPUT_ROOT, timestamp)

    def _open_output_files(self):
        topic_latency_path = os.path.join(self.output_dir, "topic_latency.csv")
        pair_skew_path = os.path.join(self.output_dir, "pair_skew.csv")

        self.topic_latency_file = open(topic_latency_path, "w", newline="", buffering=1)
        self.pair_skew_file = open(pair_skew_path, "w", newline="", buffering=1)

        self.topic_latency_writer = csv.DictWriter(
            self.topic_latency_file,
            fieldnames=[
                "source",
                "topic",
                "msg_type",
                "sequence",
                "header_ns",
                "receipt_ros_ns",
                "receipt_wall_ns",
                "receipt_ros_minus_header_ms",
            ],
        )
        self.pair_skew_writer = csv.DictWriter(
            self.pair_skew_file,
            fieldnames=[
                "pair_name",
                "trigger_source",
                "lhs_source",
                "rhs_source",
                "lhs_header_ns",
                "rhs_header_ns",
                "lhs_receipt_ros_ns",
                "rhs_receipt_ros_ns",
                "header_delta_ms",
                "receipt_delta_ms",
                "mode",
            ],
        )

        self.topic_latency_writer.writeheader()
        self.pair_skew_writer.writeheader()

    def _configure_sources(self):
        source_specs = [
            ("lidar", self.get_parameter("lidar_topic").value, self.get_parameter("lidar_msg_type").value, "sensor_data"),
            ("camera", self.get_parameter("camera_topic").value, self.get_parameter("camera_msg_type").value, "default"),
            ("pose", self.get_parameter("pose_topic").value, self.get_parameter("pose_msg_type").value, "default"),
            ("imu", self.get_parameter("imu_topic").value, self.get_parameter("imu_msg_type").value, "sensor_data"),
            (
                "state_twist",
                self.get_parameter("state_twist_topic").value,
                self.get_parameter("state_twist_msg_type").value,
                "default",
            ),
            ("command", self.get_parameter("command_topic").value, self.get_parameter("command_msg_type").value, "default"),
        ]

        for name, topic, msg_type, qos_name in source_specs:
            topic = str(topic).strip()
            msg_type = str(msg_type).strip()
            if not topic:
                continue

            msg_cls = get_message(msg_type)
            source = SourceState(name=name, topic=topic, msg_type=msg_type, qos_name=qos_name)
            self.sources[name] = source

            subscription = self.create_subscription(
                msg_cls,
                topic,
                partial(self._handle_message, name),
                self._resolve_qos(qos_name),
            )
            self._audit_subscriptions.append(subscription)

            self.get_logger().info(f"Auditing {name}: {topic} [{msg_type}] using QoS={qos_name}")

    def _configure_pairs(self):
        pair_configs: List[PairConfig] = []

        if "camera" in self.sources and "lidar" in self.sources:
            pair_configs.append(
                PairConfig(
                    name="camera_vs_lidar",
                    lhs="camera",
                    rhs="lidar",
                    trigger="lidar",
                    mode="nearest",
                    max_delta_ms=self.general_pair_window_ms,
                )
            )
        if "pose" in self.sources and "lidar" in self.sources:
            pair_configs.append(
                PairConfig(
                    name="pose_vs_lidar",
                    lhs="pose",
                    rhs="lidar",
                    trigger="lidar",
                    mode="nearest",
                    max_delta_ms=self.general_pair_window_ms,
                )
            )
        if "imu" in self.sources and "lidar" in self.sources:
            pair_configs.append(
                PairConfig(
                    name="imu_vs_lidar",
                    lhs="imu",
                    rhs="lidar",
                    trigger="lidar",
                    mode="nearest",
                    max_delta_ms=self.general_pair_window_ms,
                )
            )
        if "command" in self.sources and "state_twist" in self.sources:
            pair_configs.append(
                PairConfig(
                    name="command_vs_state_twist",
                    lhs="command",
                    rhs="state_twist",
                    trigger="state_twist",
                    mode="latest_before",
                    max_delta_ms=self.command_pair_window_ms,
                )
            )

        for config in pair_configs:
            state = PairState(config=config)
            self.pair_states[config.name] = state
            self.pairs_by_trigger[config.trigger].append(state)
            self.metric_windows[config.name] = deque(maxlen=self.summary_window_size)

        if self.pair_states:
            pair_names = ", ".join(sorted(self.pair_states))
            self.get_logger().info(f"Enabled pairwise skew metrics: {pair_names}")
        else:
            self.get_logger().warn("No pairwise skew metrics are enabled with the current topic set.")

    def _write_config_snapshot(self):
        config_path = os.path.join(self.output_dir, "config.json")
        config = {
            "created_wall_time_iso": datetime.now().isoformat(),
            "created_wall_time_ns": time.time_ns(),
            "output_dir": self.output_dir,
            "history_size": self.history_size,
            "summary_window_size": self.summary_window_size,
            "summary_period_sec": self.summary_period_sec,
            "general_pair_window_ms": self.general_pair_window_ms,
            "command_pair_window_ms": self.command_pair_window_ms,
            "sources": {
                name: {
                    "topic": source.topic,
                    "msg_type": source.msg_type,
                    "qos_name": source.qos_name,
                }
                for name, source in self.sources.items()
            },
            "pairs": {
                name: {
                    "lhs": state.config.lhs,
                    "rhs": state.config.rhs,
                    "trigger": state.config.trigger,
                    "mode": state.config.mode,
                    "max_delta_ms": state.config.max_delta_ms,
                }
                for name, state in self.pair_states.items()
            },
            "notes": {
                "receipt_ros_ns": "Subscriber callback receipt time on this node, using the node ROS clock.",
                "receipt_wall_ns": "Subscriber callback receipt time on this node, using wall clock time.time_ns().",
                "bag_receive_time": "Not measured directly here. If rosbag2 records on the same Jetson, its receive time should be close to receipt_ros_ns but not identical.",
            },
        }
        with open(config_path, "w", encoding="utf-8") as config_file:
            json.dump(config, config_file, indent=2, sort_keys=True)

    def _resolve_qos(self, qos_name: str):
        if qos_name == "sensor_data":
            return qos_profile_sensor_data
        return QoSProfile(depth=100)

    def _handle_message(self, source_name: str, msg):
        source = self.sources[source_name]
        source.total_messages += 1

        receipt_ros_ns = self.get_clock().now().nanoseconds
        receipt_wall_ns = time.time_ns()

        header = getattr(msg, "header", None)
        header_ns = stamp_to_ns(getattr(header, "stamp", None))

        if header_ns is None:
            source.total_headerless_messages += 1
            if not source.warned_headerless:
                self.get_logger().warn(
                    f"Source '{source_name}' on topic {source.topic} does not expose a ROS header stamp. "
                    "Header-based skew metrics for this source will be skipped."
                )
                source.warned_headerless = True

        sample = SampleRecord(
            sequence=source.total_messages,
            header_ns=header_ns,
            receipt_ros_ns=receipt_ros_ns,
            receipt_wall_ns=receipt_wall_ns,
        )

        if header_ns is not None:
            source.samples.append(sample)
            if len(source.samples) > self.history_size:
                source.samples.popleft()

            latency_ms = (receipt_ros_ns - header_ns) / 1_000_000.0
            self._record_metric(f"{source_name}_receipt_minus_header_ms", latency_ms)
            latency_value = f"{latency_ms:.6f}"
        else:
            latency_value = ""

        self.topic_latency_writer.writerow(
            {
                "source": source_name,
                "topic": source.topic,
                "msg_type": source.msg_type,
                "sequence": source.total_messages,
                "header_ns": "" if header_ns is None else header_ns,
                "receipt_ros_ns": receipt_ros_ns,
                "receipt_wall_ns": receipt_wall_ns,
                "receipt_ros_minus_header_ms": latency_value,
            }
        )

        if header_ns is None:
            return

        for pair_state in self.pairs_by_trigger.get(source_name, []):
            self._record_pair_skew(pair_state, sample)

    def _record_metric(self, metric_name: str, value_ms: float):
        self.metric_windows[metric_name].append(value_ms)
        self.metric_totals[metric_name] += 1

    def _record_pair_skew(self, pair_state: PairState, trigger_sample: SampleRecord):
        config = pair_state.config
        if config.trigger == config.lhs:
            lhs_sample = trigger_sample
            rhs_sample = self._match_other_sample(config.mode, self.sources[config.rhs].samples, lhs_sample.header_ns)
        else:
            rhs_sample = trigger_sample
            lhs_sample = self._match_other_sample(config.mode, self.sources[config.lhs].samples, rhs_sample.header_ns)

        if lhs_sample is None or rhs_sample is None:
            pair_state.total_misses += 1
            return

        header_delta_ms = (lhs_sample.header_ns - rhs_sample.header_ns) / 1_000_000.0
        if abs(header_delta_ms) > config.max_delta_ms:
            pair_state.total_misses += 1
            return

        receipt_delta_ms = (lhs_sample.receipt_ros_ns - rhs_sample.receipt_ros_ns) / 1_000_000.0
        pair_state.total_matches += 1
        self._record_metric(config.name, header_delta_ms)

        self.pair_skew_writer.writerow(
            {
                "pair_name": config.name,
                "trigger_source": config.trigger,
                "lhs_source": config.lhs,
                "rhs_source": config.rhs,
                "lhs_header_ns": lhs_sample.header_ns,
                "rhs_header_ns": rhs_sample.header_ns,
                "lhs_receipt_ros_ns": lhs_sample.receipt_ros_ns,
                "rhs_receipt_ros_ns": rhs_sample.receipt_ros_ns,
                "header_delta_ms": f"{header_delta_ms:.6f}",
                "receipt_delta_ms": f"{receipt_delta_ms:.6f}",
                "mode": config.mode,
            }
        )

    def _match_other_sample(self, mode: str, samples: Deque[SampleRecord], target_header_ns: Optional[int]) -> Optional[SampleRecord]:
        if target_header_ns is None:
            return None

        candidates = [sample for sample in samples if sample.header_ns is not None]
        if not candidates:
            return None

        if mode == "latest_before":
            for sample in reversed(candidates):
                if sample.header_ns <= target_header_ns:
                    return sample
            return None

        return min(candidates, key=lambda sample: abs(sample.header_ns - target_header_ns))

    def _emit_summary(self):
        latency_metrics = []
        skew_metrics = []

        for metric_name, values in sorted(self.metric_windows.items()):
            stats = summarize(values)
            if stats is None:
                continue

            total = self.metric_totals[metric_name]
            line = (
                f"{metric_name}: recent_n={int(stats['count'])} total_n={total} "
                f"mean={stats['mean']:.2f} p50={stats['p50']:.2f} p95={stats['p95']:.2f} "
                f"max_abs={stats['max_abs']:.2f} std={stats['std']:.2f}"
            )
            if metric_name.endswith("_receipt_minus_header_ms"):
                latency_metrics.append(line)
            else:
                skew_metrics.append(line)

        if latency_metrics:
            self.get_logger().info("Receipt minus header [ms]\n  " + "\n  ".join(latency_metrics))

        if skew_metrics:
            self.get_logger().info("Pairwise header skew [ms]\n  " + "\n  ".join(skew_metrics))

        misses = []
        for pair_name, pair_state in sorted(self.pair_states.items()):
            if pair_state.total_misses == 0 and pair_state.total_matches == 0:
                continue
            misses.append(
                f"{pair_name}: matches={pair_state.total_matches} misses={pair_state.total_misses} "
                f"mode={pair_state.config.mode} window_ms={pair_state.config.max_delta_ms:.1f}"
            )

        if misses:
            self.get_logger().info("Pair matching status\n  " + "\n  ".join(misses))

    def destroy_node(self):
        try:
            if hasattr(self, "summary_timer"):
                self.summary_timer.cancel()
            if hasattr(self, "topic_latency_file"):
                self.topic_latency_file.close()
            if hasattr(self, "pair_skew_file"):
                self.pair_skew_file.close()
        finally:
            super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TimestampAuditNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
