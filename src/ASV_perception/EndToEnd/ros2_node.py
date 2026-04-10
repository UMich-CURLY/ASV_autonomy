"""
Legacy compatibility wrapper for the old ROS2 perception entrypoint.

The active online point-cloud + semantic-map node now lives in
`ros2_node_pt_cloud.py`. Keep this file so older scripts still resolve,
but forward execution to the maintained implementation instead of carrying
two divergent copies of the same node.
"""

from ros2_node_pt_cloud import LidarPosesSubscriber, main as _active_main


def main():
    print(
        "ros2_node.py is a legacy compatibility wrapper; "
        "forwarding to ros2_node_pt_cloud.py."
    )
    _active_main()


if __name__ == "__main__":
    main()
