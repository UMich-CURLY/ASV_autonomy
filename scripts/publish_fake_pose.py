#!/usr/bin/env python3

import math

import rclpy
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node


def quaternion_from_yaw(yaw: float):
    half = yaw * 0.5
    return (0.0, 0.0, math.sin(half), math.cos(half))


class FakePosePublisher(Node):
    def __init__(self):
        super().__init__("fake_pose_publisher")

        self.declare_parameter("pose_topic", "/gt_pose")
        self.declare_parameter("frame_id", "odom")
        self.declare_parameter("rate_hz", 20.0)
        self.declare_parameter("mode", "stationary")
        self.declare_parameter("x", 0.0)
        self.declare_parameter("y", 0.0)
        self.declare_parameter("z", 0.0)
        self.declare_parameter("yaw", 0.0)
        self.declare_parameter("radius", 2.0)
        self.declare_parameter("linear_speed", 0.25)
        self.declare_parameter("yaw_follow_path", True)

        self.pose_topic = self.get_parameter("pose_topic").value
        self.frame_id = self.get_parameter("frame_id").value
        self.rate_hz = float(self.get_parameter("rate_hz").value)
        self.mode = self.get_parameter("mode").value
        self.x0 = float(self.get_parameter("x").value)
        self.y0 = float(self.get_parameter("y").value)
        self.z0 = float(self.get_parameter("z").value)
        self.yaw0 = float(self.get_parameter("yaw").value)
        self.radius = float(self.get_parameter("radius").value)
        self.linear_speed = float(self.get_parameter("linear_speed").value)
        self.yaw_follow_path = bool(self.get_parameter("yaw_follow_path").value)

        self.publisher = self.create_publisher(PoseStamped, self.pose_topic, 10)
        self.start_time = self.get_clock().now()

        period = 1.0 / max(self.rate_hz, 1e-3)
        self.timer = self.create_timer(period, self.publish_pose)

        self.get_logger().info(
            f"Publishing fake poses on {self.pose_topic} in {self.mode} mode at {self.rate_hz:.1f} Hz"
        )

    def publish_pose(self):
        elapsed = (self.get_clock().now() - self.start_time).nanoseconds * 1e-9

        x = self.x0
        y = self.y0
        z = self.z0
        yaw = self.yaw0

        if self.mode == "circle":
            angular_speed = self.linear_speed / max(self.radius, 1e-6)
            theta = angular_speed * elapsed
            x = self.x0 + self.radius * math.cos(theta)
            y = self.y0 + self.radius * math.sin(theta)
            if self.yaw_follow_path:
                yaw = theta + math.pi * 0.5
        elif self.mode == "line":
            x = self.x0 + self.linear_speed * elapsed

        qx, qy, qz, qw = quaternion_from_yaw(yaw)

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id
        msg.pose.position.x = x
        msg.pose.position.y = y
        msg.pose.position.z = z
        msg.pose.orientation.x = qx
        msg.pose.orientation.y = qy
        msg.pose.orientation.z = qz
        msg.pose.orientation.w = qw

        self.publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = FakePosePublisher()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
