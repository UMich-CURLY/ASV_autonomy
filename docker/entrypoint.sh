#!/bin/bash
set -e

source /opt/ros/humble/setup.bash

if [ -f /opt/asv/src/ASV_localization/ROS2/drift_ros2/install/setup.bash ]; then
    source /opt/asv/src/ASV_localization/ROS2/drift_ros2/install/setup.bash
fi

exec "$@"
