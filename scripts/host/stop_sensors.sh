#!/bin/bash
set -e

PIDS="$(pgrep -f '/home/.*/realsense2_camera_node|/home/.*/vectornav/install/vectornav/lib/vectornav/vectornav|/home/.*/vectornav/install/vectornav/lib/vectornav/vn_sensor_msgs|/home/.*/rslidar_sdk_node|/opt/ros/.*/bin/ros2 launch realsense2_camera rs_launch.py|/opt/ros/.*/bin/ros2 run vectornav vectornav|/opt/ros/.*/bin/ros2 run vectornav vn_sensor_msgs|/opt/ros/.*/bin/ros2 run rslidar_sdk rslidar_sdk_node' || true)"

if [ -z "${PIDS}" ]; then
  exit 0
fi

echo "Stopping existing host sensor processes: ${PIDS}" >&2
kill ${PIDS} >/dev/null 2>&1 || true
sleep 2

REMAINING="$(pgrep -f '/home/.*/realsense2_camera_node|/home/.*/vectornav/install/vectornav/lib/vectornav/vectornav|/home/.*/vectornav/install/vectornav/lib/vectornav/vn_sensor_msgs|/home/.*/rslidar_sdk_node|/opt/ros/.*/bin/ros2 launch realsense2_camera rs_launch.py|/opt/ros/.*/bin/ros2 run vectornav vectornav|/opt/ros/.*/bin/ros2 run vectornav vn_sensor_msgs|/opt/ros/.*/bin/ros2 run rslidar_sdk rslidar_sdk_node' || true)"
if [ -n "${REMAINING}" ]; then
  echo "Force stopping remaining host sensor processes: ${REMAINING}" >&2
  kill -9 ${REMAINING} >/dev/null 2>&1 || true
fi
