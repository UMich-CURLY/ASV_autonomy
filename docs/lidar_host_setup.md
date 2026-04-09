# Blueboat LiDAR Host Setup

This guide captures the clean host-side setup for the RoboSense RS-HELIOS-16P in the current Blueboat architecture.

For the full Jetson host/container deployment split, also see:
- [`jetson_deployment.md`](/home/asv/asv_autonomy/docs/jetson_deployment.md)

For the clean Docker container + GPU perception install flow, also see:
- [`prepare_jetson_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_jetson_container.sh)

At this stage:
- the LiDAR driver runs on the Jetson host
- autonomy stays in Docker
- the robot description publishes `base_link -> lidar_link`
- the LiDAR driver should publish `/sensors/lidar/points` with `frame_id: lidar_link`

## Architecture

Treat the LiDAR as a network sensor, not as a USB serial device.

Because the RoboSense is connected through an Ethernet-to-USB-C adapter, Linux sees it as a network interface. The important host-side concerns are:
- stable NIC identity
- correct static IP on that NIC
- live UDP traffic on the MSOP/DIFOP ports

This is the same pattern the GPS will likely use if it appears as a USB Ethernet gadget.

## One-Time Host Build

Recommended workspace:
- `~/lidar`

Build steps:

```bash
mkdir -p ~/lidar/src
cd ~/lidar/src
git clone --recurse-submodules https://github.com/RoboSense-LiDAR/rslidar_sdk.git
git clone https://github.com/RoboSense-LiDAR/rslidar_msg.git

cd ~/lidar
source /opt/ros/humble/setup.bash
source /home/asv/asv_autonomy/scripts/host/setup_ros.sh
sudo apt-get install -y libyaml-cpp-dev libpcap-dev
rosdep update
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
```

## Repo-Owned LiDAR Config

Blueboat LiDAR config:
- [`config/lidar/blueboat_config.yaml`](/home/asv/asv_autonomy/config/lidar/blueboat_config.yaml)

Important settings:
- `lidar_type: RSHELIOS_16P`
- `use_lidar_clock: false`
- `ros_frame_id: lidar_link`
- `ros_send_point_cloud_topic: /sensors/lidar/points`

## Host Launcher

LiDAR-only bringup:

```bash
cd /home/asv/asv_autonomy
./scripts/host/start_lidar.sh
```

This script:
- sources the shared ROS environment
- finds the LiDAR workspace
- loads the repo-owned config
- starts `rslidar_sdk_node` with `config_path:=...`

If your workspace is not at `~/lidar`, override it:

```bash
LIDAR_WS=/path/to/lidar_ws ./scripts/host/start_lidar.sh
```

## Combined Host Sensor Bringup

LiDAR is currently opt-in in the shared bringup script.

Start IMU + camera + LiDAR:

```bash
cd /home/asv/asv_autonomy
START_LIDAR=true ./scripts/host/start_sensors.sh
```

The shared cleanup script also knows how to stop stale LiDAR processes:
- [`scripts/host/stop_sensors.sh`](/home/asv/asv_autonomy/scripts/host/stop_sensors.sh)

## Network Checklist

Before launching the driver, verify the host sees the LiDAR NIC:

```bash
ip -br link
nmcli device status
```

Best practice:
- keep the same USB-C Ethernet adapter dedicated to the LiDAR
- label that adapter physically
- bind the NetworkManager connection to that adapter's MAC address
- give it a static IPv4 address on the LiDAR subnet
- set `ipv4.never-default yes` so it does not steal the host's default route

If you keep the same adapter, the host-side setup stays stable even if you unplug and replug it between field days.

Current known-good Blueboat LiDAR network:
- LiDAR IP: `192.168.1.200`
- Jetson LiDAR NIC IP: `192.168.1.102/24`
- Jetson LiDAR NIC: `enx00e04c781ddd`
- NetworkManager connection name: `rslidar`

Current known-good NetworkManager setup:

```bash
nmcli con mod rslidar connection.interface-name enx00e04c781ddd
nmcli con mod rslidar ipv4.method manual
nmcli con mod rslidar ipv4.addresses "192.168.1.102/24"
nmcli con mod rslidar ipv4.never-default yes
nmcli con mod rslidar ipv6.method disabled
nmcli con mod rslidar connection.autoconnect yes
nmcli con down rslidar || true
nmcli con up rslidar
```

## Packet Checks

If the driver shows `ERRCODE_MSOPTIMEOUT`, it means ROS is fine but no LiDAR UDP data is reaching the host.

Check packet arrival:

```bash
sudo tcpdump -ni <lidar_iface> udp port 6699 or udp port 7788
```

If you see nothing:
- make sure the LiDAR is powered on
- make sure the LiDAR NIC is on the right subnet
- confirm the LiDAR is sending on the expected ports

Current known-good packet signature:
- source IP `192.168.1.200`
- destination IP `192.168.1.102`
- MSOP port `6699`
- DIFOP port `7788`

## ROS Checks

After the driver is up:

```bash
cd /home/asv/asv_autonomy
source ./scripts/host/setup_ros.sh
source ~/lidar/install/setup.bash

ros2 topic list | grep lidar
ros2 topic echo /sensors/lidar/points --once
ros2 topic hz /sensors/lidar/points
ros2 run tf2_ros tf2_echo base_link lidar_link
```

Expected result:
- `/sensors/lidar/points` exists
- the point cloud header uses `frame_id: lidar_link`
- `base_link -> lidar_link` resolves from the Xacro

Current known-good message shape:
- topic: `/sensors/lidar/points`
- `header.frame_id: lidar_link`
- organized cloud with `height: 1800`, `width: 16`

## Integration Notes

Current Xacro mount:
- [`urdf/blueboat.xacro`](/home/asv/asv_autonomy/urdf/blueboat.xacro#L116)

Current active hardware perception config:
- [`src/ASV_perception/EndToEnd/Configs/blueboat_real.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/Configs/blueboat_real.yaml#L1)

Localization does not currently consume LiDAR directly:
- [`src/ASV_localization/ROS2/drift_ros2/config/wamv_gpsimu_ros2/ros_comm.yaml`](/home/asv/asv_autonomy/src/ASV_localization/ROS2/drift_ros2/config/wamv_gpsimu_ros2/ros_comm.yaml#L1)

## Perception Debug Outputs

When online perception is running, the current active node exposes a few useful LiDAR-camera debug surfaces:
- `/filtered_lidar`: the live LiDAR subset that projected into the current camera frame
- `/filtered_lidar_debug`: a transient-local copy of the latest filtered LiDAR cloud, useful for `echo --once` after startup
- `/filtered_lidar_overlay`: optional image overlay showing projected LiDAR points on the camera image

The runtime knobs for these live in:
- [`src/ASV_perception/EndToEnd/Configs/blueboat_real.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/Configs/blueboat_real.yaml#L59)

Quick checks:

```bash
cd /home/asv/asv_autonomy
source ./scripts/host/setup_ros.sh

ros2 topic list | grep filtered_lidar
ros2 topic echo /filtered_lidar_debug --once
```

By default, stage timing summaries are also logged every 10 synchronized frames from the active online node. Those timings currently break out:
- image decode
- LiDAR-to-camera projection
- segmentation
- map update
- propagation
- LiDAR transform
- label tensor conversion
- BKI update
- publish
- total callback time
