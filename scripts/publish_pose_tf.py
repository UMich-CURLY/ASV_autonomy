#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TransformStamped
from tf2_ros import TransformBroadcaster


class PoseToTF(Node):
    def __init__(self):
        super().__init__("pose_to_tf_broadcaster")

        self.declare_parameter("pose_topic", "/gt_pose")
        self.declare_parameter("parent_frame", "odom")
        self.declare_parameter("child_frame", "base_link")

        self.pose_topic = self.get_parameter("pose_topic").value
        self.parent_frame = self.get_parameter("parent_frame").value
        self.child_frame = self.get_parameter("child_frame").value

        self.tf_broadcaster = TransformBroadcaster(self)
        self.pose_sub = self.create_subscription(PoseStamped,
                                                 self.pose_topic,
                                                 self.pose_callback,
                                                 10,)

        self.get_logger().info(f"Broadcasting {self.parent_frame} -> {self.child_frame} from {self.pose_topic}")

    def pose_callback(self, msg: PoseStamped):
        transform = TransformStamped()
        transform.header.stamp = msg.header.stamp
        transform.header.frame_id = self.parent_frame
        transform.child_frame_id = self.child_frame

        transform.transform.translation.x = msg.pose.position.x
        transform.transform.translation.y = msg.pose.position.y
        transform.transform.translation.z = msg.pose.position.z
        transform.transform.rotation = msg.pose.orientation

        self.tf_broadcaster.sendTransform(transform)


def main(args=None):
    rclpy.init(args=args)
    node = PoseToTF()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
