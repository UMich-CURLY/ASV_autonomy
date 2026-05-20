#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

set +u
source /opt/ros/humble/setup.bash
set -u
cd "${SCRIPT_DIR}/ROS2"
colcon build --symlink-install \
  --packages-select drift_ros2 \
  --cmake-args -DPython3_EXECUTABLE=/usr/bin/python3
