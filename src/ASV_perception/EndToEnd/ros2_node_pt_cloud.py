import torch
from Segmentation.utils import *
from utils import *
import time
import queue
import threading
import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, HistoryPolicy, QoSProfile, ReliabilityPolicy
import ros2_numpy
from builtin_interfaces.msg import Time as TimeMsg
from sensor_msgs.msg import PointCloud2, Image, PointField, CameraInfo
from geometry_msgs.msg import PoseStamped
from visualization_msgs.msg import MarkerArray
from message_filters import ApproximateTimeSynchronizer, Subscriber
import numpy as np
from cv_bridge import CvBridge
import cv2
import struct  # Needed for proper color packing
from dataclasses import dataclass
from config_utils import CONFIG_ENV_VAR, load_model_params
from geometry import GeometryError, LidarCameraProjector
from transform_math import quaternion_matrix

@dataclass
class QueuedObservation:
    frame_index: int
    raw_point_count: int
    visible_point_count: int
    stamp: TimeMsg
    lidar_frame_id: str
    lidar_pose: np.ndarray
    lidar: np.ndarray
    projected_pixels: np.ndarray
    cv_image: np.ndarray
    frame_start_perf: float
    enqueue_perf: float
    stage_timings_ms: dict


class LidarPosesSubscriber(Node):

    def __init__(
        self,
        pc_topic,
        pose_topic,
        img_topic,
        camera_info_topic,
        expected_lidar_frame,
        expected_camera_frame,
        sync_queue_size,
        sync_slop_sec,
        max_pose_skew_sec,
        tf_timeout_sec,
        model_params,
        dev,
        dtype,
        voxel_sizes,
        color,
        publish=False,
    ):
        super().__init__('lidar_poses_image_subscriber')

        self.get_logger().info("Initializing the node!")
        self.publish = publish
        self.bridge = CvBridge()
        self.expected_lidar_frame = expected_lidar_frame
        self.expected_camera_frame = expected_camera_frame
        self.max_pose_skew_sec = float(max_pose_skew_sec)
        self.projector = LidarCameraProjector(self, tf_timeout_sec=tf_timeout_sec)
        self._last_camera_info_warning = 0.0
        self._last_frame_warning = 0.0
        self._last_tf_warning = 0.0
        self._last_pose_warning = 0.0
        self._last_runtime_warning = 0.0
        self._runtime_ready = False
        self._runtime_initializing = False
        self._runtime_error = None
        self.model_params = model_params
        self._frame_index = 0

        debug_config = dict(self.model_params.get("debug", {}))
        filtered_lidar_debug = dict(debug_config.get("filtered_lidar", {}))
        timing_config = dict(debug_config.get("timing", {}))

        self._filtered_lidar_debug_enabled = bool(filtered_lidar_debug.get("enabled", False))
        self._filtered_lidar_log_every_n_frames = max(
            int(filtered_lidar_debug.get("log_every_n_frames", 10)), 1
        )
        self._filtered_lidar_transient_enabled = bool(
            filtered_lidar_debug.get("publish_transient_local_copy", False)
        )
        self._filtered_lidar_transient_topic = str(
            filtered_lidar_debug.get("transient_topic", "/filtered_lidar_debug")
        )
        self._filtered_lidar_overlay_enabled = bool(
            filtered_lidar_debug.get("publish_overlay", False)
        )
        self._filtered_lidar_overlay_topic = str(
            filtered_lidar_debug.get("overlay_topic", "/filtered_lidar_overlay")
        )
        self._filtered_lidar_overlay_stride = max(
            int(filtered_lidar_debug.get("overlay_point_stride", 8)), 1
        )
        self._filtered_lidar_overlay_radius = max(
            int(filtered_lidar_debug.get("overlay_radius_px", 2)), 1
        )

        self._timing_enabled = bool(timing_config.get("enabled", False))
        self._timing_log_every_n_frames = max(
            int(timing_config.get("log_every_n_frames", 10)), 1
        )
        async_config = dict(debug_config.get("async_processing", {}))
        self._async_enabled = bool(async_config.get("enabled", False))
        self._async_queue_size = max(int(async_config.get("queue_size", 1)), 1)
        self._async_drop_oldest_when_full = bool(
            async_config.get("drop_oldest_when_full", True)
        )
        self._observation_queue = queue.Queue(maxsize=self._async_queue_size)
        self._worker_stop = threading.Event()
        self._worker_thread = None
        self._dropped_observation_count = 0
        self._last_queue_warning = 0.0

        # Publishers
        self.map_pub = self.create_publisher(MarkerArray, 'SemMap_global', 10)
        self.var_pub = self.create_publisher(MarkerArray, 'VarMap_global', 10)
        self.lidar_pub = self.create_publisher(PointCloud2, 'filtered_lidar', 10)
        self.lidar_debug_pub = None
        self.overlay_pub = None
        self.next_map = MarkerArray()
        self.var_map = MarkerArray()
        self.pc_pub = self.create_publisher(PointCloud2, 'semantic_map', 10)

        if self._filtered_lidar_transient_enabled:
            transient_qos = QoSProfile(
                history=HistoryPolicy.KEEP_LAST,
                depth=1,
                reliability=ReliabilityPolicy.RELIABLE,
                durability=DurabilityPolicy.TRANSIENT_LOCAL,
            )
            self.lidar_debug_pub = self.create_publisher(
                PointCloud2,
                self._filtered_lidar_transient_topic,
                transient_qos,
            )

        if self._filtered_lidar_overlay_enabled:
            self.overlay_pub = self.create_publisher(Image, self._filtered_lidar_overlay_topic, 1)

        self.global_cloud = None  # To store the accumulated point cloud
        self.initialize_global_grid()  # Initialize world with default points


        # Message Filters
        self.pc_sub = Subscriber(self, PointCloud2, pc_topic)
        self.pose_sub = Subscriber(self, PoseStamped, pose_topic)
        self.img_sub = Subscriber(self, Image, img_topic)  # New Image Subscriber

        self.camera_info_sub = self.create_subscription(
            CameraInfo,
            camera_info_topic,
            self._camera_info_callback,
            10,
        )

        self.ts = ApproximateTimeSynchronizer(
            [self.pc_sub, self.pose_sub, self.img_sub],
            int(sync_queue_size),
            float(sync_slop_sec),
        )
        self.ts.registerCallback(self.callback)

        # Other initialization
        self.lidar = None
        self.seg_input = None
        self.inv = None
        self.lidar_pose = None
        self.e2e_net = None
        self.dev = dev
        self.dtype = dtype
        self.voxel_sizes = voxel_sizes
        self.color = color
        self.get_logger().info(
            "Subscribed to pointcloud topic: %s, pose topic: %s, image topic: %s, camera info topic: %s"
            % (pc_topic, pose_topic, img_topic, camera_info_topic)
        )
        self.get_logger().info(
            "Loaded perception config '%s' from %s."
            % (
                self.model_params.get("config_name", "unknown"),
                self.model_params.get("config_path", "unknown"),
            )
        )
        self.get_logger().info(
            "Perception node is up; runtime models will initialize asynchronously on first startup."
        )
        if self._filtered_lidar_debug_enabled:
            self.get_logger().info(
                "Filtered LiDAR debug is enabled%s%s."
                % (
                    f"; transient copy on {self._filtered_lidar_transient_topic}"
                    if self.lidar_debug_pub is not None else "",
                    f"; overlay on {self._filtered_lidar_overlay_topic}"
                    if self.overlay_pub is not None else "",
                )
            )
        if self._timing_enabled:
            self.get_logger().info(
                "Per-stage timing logs are enabled every %d frame(s)."
                % self._timing_log_every_n_frames
            )
        if self._async_enabled:
            self.get_logger().info(
                "Async perception processing is enabled with queue_size=%d%s."
                % (
                    self._async_queue_size,
                    " (drop oldest on overflow)"
                    if self._async_drop_oldest_when_full else
                    " (drop newest on overflow)",
                )
            )
            self._worker_thread = threading.Thread(
                target=self._segmentation_worker,
                name="perception_async_worker",
                daemon=True,
            )
            self._worker_thread.start()
        self._startup_timer = self.create_timer(0.1, self._initialize_runtime_once)

    def _build_xyzi_pointcloud(self, points_xyzi, stamp, frame_id):
        msg = PointCloud2()
        msg.header.stamp = stamp
        msg.header.frame_id = frame_id
        msg.height = 1
        msg.width = int(points_xyzi.shape[0])
        msg.is_bigendian = False
        msg.is_dense = False
        msg.fields = [
            PointField(name="x", offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name="y", offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name="z", offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name="intensity", offset=12, datatype=PointField.FLOAT32, count=1),
        ]
        msg.point_step = 16
        msg.row_step = msg.point_step * msg.width
        msg.data = np.asarray(points_xyzi, dtype=np.float32).tobytes()
        return msg

    def _publish_filtered_lidar(self, points_xyzi, stamp, frame_id):
        msg = self._build_xyzi_pointcloud(points_xyzi, stamp, frame_id)
        self.lidar_pub.publish(msg)
        if self.lidar_debug_pub is not None:
            self.lidar_debug_pub.publish(msg)

    def _publish_filtered_lidar_overlay(self, image_bgr, projected_pixels, depths, stamp, frame_id, raw_point_count):
        if self.overlay_pub is None:
            return

        overlay = image_bgr.copy()
        if projected_pixels.size > 0:
            sampled_pixels = projected_pixels[::self._filtered_lidar_overlay_stride]
            sampled_depths = depths[::self._filtered_lidar_overlay_stride]

            depth_min = float(np.min(sampled_depths))
            depth_max = float(np.max(sampled_depths))
            depth_span = max(depth_max - depth_min, 1e-6)
            normalized = ((sampled_depths - depth_min) / depth_span * 255.0).astype(np.uint8)
            color_lookup = cv2.applyColorMap(255 - normalized.reshape(-1, 1), cv2.COLORMAP_JET)

            for (u, v), color in zip(sampled_pixels, color_lookup.reshape(-1, 3)):
                cv2.circle(
                    overlay,
                    (int(u), int(v)),
                    self._filtered_lidar_overlay_radius,
                    tuple(int(channel) for channel in color.tolist()),
                    -1,
                )

        visible_count = int(projected_pixels.shape[0])
        visibility_ratio = float(visible_count) / float(max(raw_point_count, 1))
        cv2.putText(
            overlay,
            f"raw:{raw_point_count} visible:{visible_count} ({visibility_ratio:.1%})",
            (16, 32),
            cv2.FONT_HERSHEY_SIMPLEX,
            0.8,
            (255, 255, 255),
            2,
            cv2.LINE_AA,
        )

        overlay_msg = self.bridge.cv2_to_imgmsg(overlay, encoding="bgr8")
        overlay_msg.header.stamp = stamp
        overlay_msg.header.frame_id = frame_id
        self.overlay_pub.publish(overlay_msg)

    def _maybe_log_filtered_lidar_debug(self, raw_point_count, projection, lidar_frame, image_frame):
        if not self._filtered_lidar_debug_enabled:
            return
        if self._frame_index % self._filtered_lidar_log_every_n_frames != 0:
            return

        visible_count = int(projection.valid_indices.shape[0])
        visibility_ratio = float(visible_count) / float(max(raw_point_count, 1))
        if visible_count > 0:
            depth_min = float(np.min(projection.depths))
            depth_max = float(np.max(projection.depths))
            depth_mean = float(np.mean(projection.depths))
            depth_summary = (
                f" depth[m]=min:{depth_min:.2f} mean:{depth_mean:.2f} max:{depth_max:.2f}"
            )
        else:
            depth_summary = ""

        self.get_logger().info(
            "Filtered LiDAR frame %d: raw=%d visible=%d (%.1f%%) lidar_frame=%s image_frame=%s%s"
            % (
                self._frame_index,
                raw_point_count,
                visible_count,
                visibility_ratio * 100.0,
                lidar_frame,
                image_frame,
                depth_summary,
            )
        )

    def _maybe_log_stage_timing(
        self,
        frame_index,
        stage_timings_ms,
        raw_point_count,
        visible_point_count,
        labeled_point_count,
    ):
        if not self._timing_enabled:
            return
        if frame_index % self._timing_log_every_n_frames != 0:
            return

        summary_parts = []
        ordered_keys = [
            ("decode_ms", "decode"),
            ("projection_ms", "projection"),
            ("queue_wait_ms", "queue_wait"),
            ("segmentation_ms", "segmentation"),
            ("map_update_ms", "map_update"),
            ("propagation_ms", "propagation"),
            ("lidar_transform_ms", "lidar_transform"),
            ("label_tensor_ms", "label_tensor"),
            ("bki_update_ms", "bki"),
            ("publish_ms", "publish"),
            ("total_ms", "total"),
        ]
        for key, label in ordered_keys:
            value = stage_timings_ms.get(key)
            if value is not None:
                summary_parts.append(f"{label}={value:.1f}")

        self.get_logger().info(
            "Frame %d timing [ms]: %s | raw=%d visible=%d labeled=%d"
            % (
                frame_index,
                ", ".join(summary_parts),
                raw_point_count,
                visible_point_count,
                labeled_point_count,
            )
        )

    @staticmethod
    def _copy_stamp(stamp):
        stamp_copy = TimeMsg()
        stamp_copy.sec = int(stamp.sec)
        stamp_copy.nanosec = int(stamp.nanosec)
        return stamp_copy

    def _publish_semantic_outputs(self, marker, stamp):
        if marker is None or len(marker.points) == 0:
            self._warn_throttled(
                "_last_runtime_warning",
                "Semantic map update produced no occupied voxels to publish yet.",
            )
            return

        marker.header.stamp = stamp
        marker_array = MarkerArray()
        marker_array.markers.append(marker)
        self.map_pub.publish(marker_array)

        points = []
        rgb_colors = []

        for point, color in zip(marker.points, marker.colors):
            points.append([point.x, point.y, point.z])

            r = int(color.r * 255)
            g = int(color.g * 255)
            b = int(color.b * 255)
            rgb_packed = struct.unpack('f', struct.pack('I', (r << 16) | (g << 8) | b))[0]
            rgb_colors.append(rgb_packed)

        cloud_points = np.array(points, dtype=np.float32)
        cloud_colors = np.array(rgb_colors, dtype=np.float32).reshape(-1, 1)
        pc2_data = np.hstack((cloud_points, cloud_colors))

        pc2_msg = PointCloud2()
        pc2_msg.header.stamp = stamp
        pc2_msg.header.frame_id = "map"
        pc2_msg.fields = [
            PointField(name="x", offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name="y", offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name="z", offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name="rgb", offset=12, datatype=PointField.FLOAT32, count=1),
        ]
        pc2_msg.width = cloud_points.shape[0]
        pc2_msg.height = 1
        pc2_msg.is_dense = False
        pc2_msg.point_step = 16
        pc2_msg.row_step = pc2_msg.point_step * pc2_msg.width
        pc2_msg.data = pc2_data.tobytes()
        self.pc_pub.publish(pc2_msg)
    
    def initialize_global_grid(self, grid_size=50, step=1.0, default_color=(128, 128, 128)):
        """ Initializes the global map with a uniform grid of points. """
        x_range = np.arange(-grid_size, grid_size, step)
        y_range = np.arange(-grid_size, grid_size, step)
        z_range = np.arange(-5, 5, step)  # Example: 10m vertical height

        grid_x, grid_y, grid_z = np.meshgrid(x_range, y_range, z_range, indexing="ij")
        points = np.column_stack((grid_x.ravel(), grid_y.ravel(), grid_z.ravel()))

        # Assign initial color (e.g., gray)
        r, g, b = default_color
        rgb_packed = struct.unpack('f', struct.pack('I', (r << 16) | (g << 8) | b))[0]
        colors = np.full((points.shape[0], 1), rgb_packed, dtype=np.float32)

        # Store in global cloud
        self.global_cloud = np.hstack((points, colors))
        self.get_logger().info(
            f"Initialized global grid with {self.global_cloud.shape[0]} points."
        )

        # Publish once
        self.publish_global_pointcloud()

    def publish_global_pointcloud(self):
        """ Publishes the global point cloud. """
        if self.global_cloud is None:
            return

        # Create PointCloud2 message
        pc2_msg = PointCloud2()
        pc2_msg.header.stamp = self.get_clock().now().to_msg()
        pc2_msg.header.frame_id = "map"

        # Define PointCloud2 fields
        pc2_msg.fields = [
            PointField(name="x", offset=0, datatype=PointField.FLOAT32, count=1),
            PointField(name="y", offset=4, datatype=PointField.FLOAT32, count=1),
            PointField(name="z", offset=8, datatype=PointField.FLOAT32, count=1),
            PointField(name="rgb", offset=12, datatype=PointField.FLOAT32, count=1)
        ]

        # Set cloud size
        pc2_msg.width = self.global_cloud.shape[0]
        pc2_msg.height = 1
        pc2_msg.is_dense = False
        pc2_msg.point_step = 16
        pc2_msg.row_step = pc2_msg.point_step * pc2_msg.width
        pc2_msg.data = self.global_cloud.tobytes()

        # Publish global point cloud
        self.pc_pub.publish(pc2_msg)

    def _camera_info_callback(self, camera_info_msg):
        try:
            self.projector.update_camera_info(camera_info_msg)
        except GeometryError as exc:
            self._warn_throttled(
                "_last_camera_info_warning",
                f"CameraInfo is invalid: {exc}",
            )

    def _warn_throttled(self, attr_name, message, period_sec=5.0):
        now = time.monotonic()
        if now - getattr(self, attr_name) >= period_sec:
            self.get_logger().warn(message)
            setattr(self, attr_name, now)

    def _stage_timestamp(self):
        if self._timing_enabled and self.dev == 'cuda' and torch.cuda.is_available():
            torch.cuda.synchronize()
        return time.perf_counter()

    def _initialize_runtime_once(self):
        if self._startup_timer is not None:
            self._startup_timer.cancel()
            self._startup_timer = None
        if self._runtime_ready or self._runtime_initializing:
            return

        self._runtime_initializing = True
        start_t = time.time()
        self.get_logger().info("Starting perception runtime initialization.")
        try:
            self.e2e_net = load_model(self.model_params, self.dev, logger=self.get_logger())
            self.e2e_net.measure_timings = self._timing_enabled
            self.get_logger().info("Preloading Grounded-SAM2 segmentation models.")
            initialize_segmentation_models(self.model_params, logger=self.get_logger())
            self._runtime_ready = True
            self._runtime_error = None
            self.get_logger().info(
                f"Perception runtime initialization completed in {time.time() - start_t:.2f}s."
            )
        except Exception as exc:
            self._runtime_error = str(exc)
            self.get_logger().error(f"Perception runtime initialization failed: {exc}")
        finally:
            self._runtime_initializing = False

    @staticmethod
    def _stamp_to_seconds(stamp):
        return float(stamp.sec) + float(stamp.nanosec) * 1e-9

    def _validate_message_contract(self, pc_msg, pose_msg, img_msg):
        if self._runtime_error is not None:
            self._warn_throttled(
                "_last_runtime_warning",
                f"Perception runtime is unavailable: {self._runtime_error}",
            )
            return False

        if not self._runtime_ready:
            self._warn_throttled(
                "_last_runtime_warning",
                "Perception runtime is still loading models; skipping inference until startup finishes.",
            )
            return False

        if not self.projector.ready():
            self._warn_throttled(
                "_last_camera_info_warning",
                "Perception is waiting for CameraInfo before it can project LiDAR into the image.",
            )
            return False

        if not pc_msg.header.frame_id:
            self._warn_throttled(
                "_last_frame_warning",
                "PointCloud2 frame_id is empty; skipping inference.",
            )
            return False

        if self.expected_lidar_frame and pc_msg.header.frame_id != self.expected_lidar_frame:
            self._warn_throttled(
                "_last_frame_warning",
                f"PointCloud2 frame_id '{pc_msg.header.frame_id}' did not match expected '{self.expected_lidar_frame}'.",
            )
            return False

        if not img_msg.header.frame_id:
            self._warn_throttled(
                "_last_frame_warning",
                "Image frame_id is empty; skipping inference.",
            )
            return False

        if self.expected_camera_frame and img_msg.header.frame_id != self.expected_camera_frame:
            self._warn_throttled(
                "_last_frame_warning",
                f"Image frame_id '{img_msg.header.frame_id}' did not match expected '{self.expected_camera_frame}'.",
            )
            return False

        pose_stamp = self._stamp_to_seconds(pose_msg.header.stamp)
        pc_stamp = self._stamp_to_seconds(pc_msg.header.stamp)
        img_stamp = self._stamp_to_seconds(img_msg.header.stamp)
        max_skew = max(abs(pose_stamp - pc_stamp), abs(pose_stamp - img_stamp))
        if max_skew > self.max_pose_skew_sec:
            self._warn_throttled(
                "_last_pose_warning",
                f"Skipping inference because pose skew {max_skew:.3f}s exceeded {self.max_pose_skew_sec:.3f}s.",
            )
            return False

        return True

    def _enqueue_observation(self, observation):
        if not self._async_enabled:
            self._process_observation(observation)
            return

        if self._observation_queue.full():
            if self._async_drop_oldest_when_full:
                try:
                    self._observation_queue.get_nowait()
                    self._dropped_observation_count += 1
                    self._warn_throttled(
                        "_last_queue_warning",
                        "Perception async queue overflowed; dropping the oldest pending semantic frame.",
                        period_sec=2.0,
                    )
                except queue.Empty:
                    pass
            else:
                self._dropped_observation_count += 1
                self._warn_throttled(
                    "_last_queue_warning",
                    "Perception async queue overflowed; dropping the newest semantic frame.",
                    period_sec=2.0,
                )
                return

        try:
            self._observation_queue.put_nowait(observation)
        except queue.Full:
            self._dropped_observation_count += 1
            self._warn_throttled(
                "_last_queue_warning",
                "Perception async queue remained full after overflow handling; dropping a semantic frame.",
                period_sec=2.0,
            )

    def _segmentation_worker(self):
        while not self._worker_stop.is_set() or not self._observation_queue.empty():
            try:
                observation = self._observation_queue.get(timeout=0.1)
            except queue.Empty:
                continue

            try:
                self._process_observation(observation)
            except Exception as exc:
                self.get_logger().error(
                    f"Async perception worker failed on frame {observation.frame_index}: {exc}"
                )

    def _process_observation(self, observation):
        with torch.no_grad():
            segmentation_start = self._stage_timestamp()
            _, _, point_labels = generate_point_labels(
                observation.lidar,
                self.model_params,
                observation.cv_image,
                projected_pixels=observation.projected_pixels,
                logger=self.get_logger(),
            )
            segmentation_end = self._stage_timestamp()

            input_data = [
                torch.tensor(observation.lidar_pose).to(self.dev).type(self.dtype),
                torch.tensor(observation.lidar).to(self.dev).type(self.dtype),
                point_labels,
                None,
            ]

            map_update_start = self._stage_timestamp()
            self.e2e_net(input_data)
            map_update_end = self._stage_timestamp()

            publish_start = self._stage_timestamp()
            if self.publish:
                marker = publish_local_map(
                    self.e2e_net.grid,
                    self.e2e_net.convbki_net.centroids,
                    self.voxel_sizes,
                    self.color,
                    None,
                    self.e2e_net.propagation_net.translation,
                )
                self._publish_semantic_outputs(marker, observation.stamp)

                self.var_map = publish_var_map(
                    self.e2e_net.grid,
                    self.e2e_net.convbki_net.centroids,
                    self.voxel_sizes,
                    self.color,
                    self.var_map,
                    self.e2e_net.propagation_net.translation,
                )
                self.var_pub.publish(self.var_map)
            publish_end = self._stage_timestamp()

        labeled_point_count = int(np.count_nonzero(np.sum(point_labels, axis=1) > 0))
        queue_wait_ms = (segmentation_start - observation.enqueue_perf) * 1000.0
        stage_timings_ms = dict(observation.stage_timings_ms)
        stage_timings_ms["queue_wait_ms"] = max(queue_wait_ms, 0.0)
        stage_timings_ms["segmentation_ms"] = (segmentation_end - segmentation_start) * 1000.0
        stage_timings_ms["publish_ms"] = (publish_end - publish_start) * 1000.0
        stage_timings_ms["total_ms"] = (publish_end - observation.frame_start_perf) * 1000.0
        stage_timings_ms.update(getattr(self.e2e_net, "last_stage_timings_ms", {}))
        stage_timings_ms["map_update_ms"] = (map_update_end - map_update_start) * 1000.0
        self._maybe_log_stage_timing(
            frame_index=observation.frame_index,
            stage_timings_ms=stage_timings_ms,
            raw_point_count=observation.raw_point_count,
            visible_point_count=observation.visible_point_count,
            labeled_point_count=labeled_point_count,
        )

    def callback(self, pc_msg, pose_msg, img_msg):
        if not self._validate_message_contract(pc_msg, pose_msg, img_msg):
            return
        self._frame_index += 1
        frame_start = time.perf_counter()

        # Convert PointCloud2 msg to numpy array
        lidar_pc = ros2_numpy.point_cloud2.point_cloud2_to_array(pc_msg)

        # Extract 'xyz' and 'intensity' fields
        xyz = lidar_pc['xyz']  # (N, 3) array
        intensity = np.asarray(lidar_pc['intensity']).reshape(-1)

        # Initialize a new array to hold XYZ + intensity data
        lidar_raw = np.zeros((xyz.shape[0], 4), dtype=np.float32)
        lidar_raw[:, :3] = xyz  # Populate XYZ
        lidar_raw[:, 3] = intensity  # Populate intensity

        # Convert Image message to OpenCV format
        cv_image = np.array(
            self.bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8"),
            copy=True,
        )
        decode_end = time.perf_counter()

        try:
            projection_start = time.perf_counter()
            projection = self.projector.project_points(
                lidar_raw[:, :3],
                source_frame=pc_msg.header.frame_id,
                target_frame=self.expected_camera_frame or self.projector.camera_frame or img_msg.header.frame_id,
            )
            projection_end = time.perf_counter()
        except GeometryError as exc:
            self._warn_throttled(
                "_last_tf_warning",
                f"Skipping inference because LiDAR/image geometry is not ready: {exc}",
            )
            return

        # Check if projected pixels are empty
        if projection.pixels.shape[0] == 0:
            self.get_logger().warn("No valid LiDAR points in camera FOV. Skipping this callback.")
            return  # Exit early and wait for the next callback

        # Apply the same filtering to lidar
        self.lidar = np.array(lidar_raw[projection.valid_indices], copy=True)  # Only keep LiDAR points in the image frame
        self._publish_filtered_lidar(self.lidar, pc_msg.header.stamp, pc_msg.header.frame_id)
        self._maybe_log_filtered_lidar_debug(
            raw_point_count=lidar_raw.shape[0],
            projection=projection,
            lidar_frame=pc_msg.header.frame_id,
            image_frame=img_msg.header.frame_id,
        )
        self._publish_filtered_lidar_overlay(
            cv_image,
            projection.pixels,
            projection.depths,
            img_msg.header.stamp,
            img_msg.header.frame_id,
            raw_point_count=lidar_raw.shape[0],
        )

        # Extract pose from PoseStamped message
        pose_t = np.array([pose_msg.pose.position.x, pose_msg.pose.position.y, pose_msg.pose.position.z])
        pose_quat = np.array([pose_msg.pose.orientation.x, pose_msg.pose.orientation.y, 
                            pose_msg.pose.orientation.z, pose_msg.pose.orientation.w])
        self.lidar_pose = quaternion_matrix(pose_quat)
        self.lidar_pose[:3, 3] = pose_t

        observation = QueuedObservation(
            frame_index=self._frame_index,
            raw_point_count=int(lidar_raw.shape[0]),
            visible_point_count=int(self.lidar.shape[0]),
            stamp=self._copy_stamp(pc_msg.header.stamp),
            lidar_frame_id=str(pc_msg.header.frame_id),
            lidar_pose=np.array(self.lidar_pose, copy=True),
            lidar=np.array(self.lidar, copy=True),
            projected_pixels=np.array(projection.pixels, copy=True),
            cv_image=np.array(cv_image, copy=True),
            frame_start_perf=frame_start,
            enqueue_perf=time.perf_counter(),
            stage_timings_ms={
                "decode_ms": (decode_end - frame_start) * 1000.0,
                "projection_ms": (projection_end - projection_start) * 1000.0,
            },
        )
        self._enqueue_observation(observation)

    def destroy_node(self):
        if self._startup_timer is not None:
            self._startup_timer.cancel()
            self._startup_timer = None
        self._worker_stop.set()
        if self._worker_thread is not None and self._worker_thread.is_alive():
            self._worker_thread.join(timeout=2.0)
        super().destroy_node()


def main():
    model_params = load_model_params()

    dev = 'cuda' if torch.cuda.is_available() else 'cpu'
    dtype = torch.float32

    # Initialize ROS2 node
    rclpy.init()
    node = LidarPosesSubscriber(
        pc_topic=model_params["pc_topic"],
        pose_topic=model_params["pose_topic"],
        img_topic=model_params["img_topic"],  # Added Image Topic
        camera_info_topic=model_params["camera_info_topic"],
        expected_lidar_frame=model_params["expected_lidar_frame"],
        expected_camera_frame=model_params["expected_camera_frame"],
        sync_queue_size=model_params["sync_queue_size"],
        sync_slop_sec=model_params["sync_slop_sec"],
        max_pose_skew_sec=model_params["max_pose_skew_sec"],
        tf_timeout_sec=model_params["tf_timeout_sec"],
        model_params=model_params,
        dev=dev,
        dtype=dtype,
        voxel_sizes=model_params["voxel_sizes"],
        color=model_params["colors"],
        publish=model_params["publish"]
    )

    node.get_logger().info(
        f"Override the active perception config with the {CONFIG_ENV_VAR} environment variable."
    )

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
