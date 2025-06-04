#!/bin/bash

# --- General settings ---
echo "Launching ASV Sensor Suite..."

# Helper: open in new terminal tab or window
launch_in_terminal() {
    gnome-terminal -- bash -c "$1; exec bash"
}

# --- Camera ---
launch_in_terminal "
echo 'Starting Realsense Camera...'
source /home/asv/asv_sensorsuite/ros2_ws/install/local_setup.bash
ros2 launch realsense2_camera rs_launch.py rgb_camera.color_profile:=1280x720x15
"

# --- LIDAR ---
launch_in_terminal "
echo 'Starting Robosense Lidar...'
conda activate robosense
cd /home/asv/lidar_ws
source install/setup.bash
ros2 launch rslidar_sdk start.py
"

# --- IMU ---
launch_in_terminal "
echo 'Starting IMU...'
conda activate asv_sensor
cd /home/asv/asv_sensorsuite/vectornav
source install/setup.bash
echo 'curlylab' | sudo -S chmod -R 777 /dev/ttyUSB0
ros2 launch vectornav vectornav.launch.py
"



# --- GPS ---
launch_in_terminal "
echo 'Starting GPS...'
conda activate gps_ws
cd /home/asv/septentrio_gnss_driver_ros2-release
ros2 launch septentrio_gnss_driver rover.launch.py
"

echo "All sensor nodes are launching in new terminals."

# --- Static Transform: map -> map_lidar ---
launch_in_terminal "
echo 'Publishing static transform from map to map_lidar...'
source /home/asv/asv_sensorsuite/ros2_ws/install/local_setup.bash
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0.4363 0 map map_lidar
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map_lidar rslidar
"

# --- Static Transform: map_lidar -> rslidar ---
launch_in_terminal "
echo 'Publishing static transform from map_lidar to rslidar...'
source /home/asv/asv_sensorsuite/ros2_ws/install/local_setup.bash
ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map_lidar rslidar
"

