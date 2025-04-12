#!/bin/bash
source ~/miniconda3/etc/profile.d/conda.sh
conda activate asv_autonomy
source /home/asv/ASV_autonomy/drift/ROS2/drift_ros2/install/setup.bash
ros2 run drift_ros2 wamv_gps_ros2
python /home/asv/ASV_autonomy/drift/ROS2/drift_ros2/pose_imu_twist_fuser.py

