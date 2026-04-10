# Blueboat Checkpoint Bringup

This runbook captures the current working checkpoint for the Blueboat real-robot stack.

At this checkpoint:
- VectorNav IMU is running on the Jetson host.
- RealSense D455 is running on the Jetson host.
- RoboSense LiDAR host integration is working and can be enabled with `START_LIDAR=true`.
- The robot Xacro/URDF is running in Docker through `robot_state_publisher`.
- The real robot TF boundary is:
  - Xacro owns `base_link -> imu_link/gps_link/lidar_link/camera_link`
  - RealSense owns the camera frames below `camera_link`
- GPS is not connected yet, so localization pose output is not expected to work yet.
- Jetson perception now expects the persisted venv at `/opt/asv/.venvs/ros2_grounded_sam2`.

## Architecture

Jetson host:
- hardware-facing sensor drivers
- VectorNav workspace
- RealSense workspace
- RoboSense workspace

Docker container:
- `robot_state_publisher`
- TF bootstrap (`map -> odom`)
- localization
- perception

Shared ROS/DDS settings:
- [`docker/ros.env`](/home/asv/asv_autonomy/docker/ros.env)

## Expected Host Workspaces

VectorNav:
- default expected path: `~/vectornav`
- override with `VECTORNAV_WS=/path/to/vectornav`

RealSense:
- default search order:
  - `~/realsense/ros2`
  - `~/realsense/ros2_ws`
  - `~/asv_sensorsuite/ros2_ws`
- override with `REALSENSE_WS=/path/to/workspace`

RoboSense:
- default search order:
  - `~/lidar`
  - `~/lidar_ws`
  - `~/asv_sensorsuite/lidar_ws`
- override with `LIDAR_WS=/path/to/workspace`

## Main Host Scripts

Host ROS setup:
- [`scripts/host/setup_ros.sh`](/home/asv/asv_autonomy/scripts/host/setup_ros.sh)

Start VectorNav only:
- [`scripts/host/start_vectornav.sh`](/home/asv/asv_autonomy/scripts/host/start_vectornav.sh)

Start RealSense only:
- [`scripts/host/start_realsense.sh`](/home/asv/asv_autonomy/scripts/host/start_realsense.sh)

Start RoboSense LiDAR only:
- [`scripts/host/start_lidar.sh`](/home/asv/asv_autonomy/scripts/host/start_lidar.sh)

Stop host sensor processes:
- [`scripts/host/stop_sensors.sh`](/home/asv/asv_autonomy/scripts/host/stop_sensors.sh)

Start host sensors together:
- [`scripts/host/start_sensors.sh`](/home/asv/asv_autonomy/scripts/host/start_sensors.sh)

Start Docker autonomy:
- [`scripts/host/start_autonomy.sh`](/home/asv/asv_autonomy/scripts/host/start_autonomy.sh)

Prepare the Docker container + Jetson GPU perception runtime:
- [`scripts/host/prepare_jetson_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_jetson_container.sh)

Start everything from the Jetson host:
- [`scripts/host/start_system.sh`](/home/asv/asv_autonomy/scripts/host/start_system.sh)

## Recommended Startup Order

### 1. Clean up any stale host sensor processes

```bash
cd /home/asv/asv_autonomy
./scripts/host/stop_sensors.sh
```

### 2. Start host-side sensors

```bash
cd /home/asv/asv_autonomy
./scripts/host/start_sensors.sh
```

This starts:
- VectorNav IMU
- RealSense D455

To include LiDAR too:

```bash
cd /home/asv/asv_autonomy
START_LIDAR=true ./scripts/host/start_sensors.sh
```

Current known-good LiDAR network:
- LiDAR IP `192.168.1.200`
- Jetson LiDAR NIC IP `192.168.1.102/24`
- Jetson LiDAR NIC `enx00e04c781ddd`
- NetworkManager profile `rslidar`

### 3. Prepare the Docker container cleanly

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/prepare_jetson_container.sh
```

This is the preferred Jetson path because it:
- recreates the container with the persisted venv/checkpoint mounts
- installs the known-good Jetson GPU torch stack
- prewarms the Hugging Face cache for the GroundingDINO text encoder
- validates that the text encoder can load from local cache with offline flags enabled
- validates the CUDA extensions before autonomy starts

### 4. Start autonomy in Docker

For a TF-only bringup at this checkpoint:

```bash
cd /home/asv/asv_autonomy
ENABLE_LOCALIZATION=false ENABLE_PERCEPTION=false ./scripts/host/start_autonomy.sh
```

For the normal autonomy bringup:

```bash
cd /home/asv/asv_autonomy
./scripts/host/start_autonomy.sh
```

Notes:
- The script is bind-mounted from the host at [`scripts/setup_perception.sh`](/home/asv/asv_autonomy/scripts/setup_perception.sh).
- The current deployment split is documented in [`jetson_deployment.md`](/home/asv/asv_autonomy/docs/jetson_deployment.md).
- On Jetson, the script now prefers [`environment.jetson.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/environment.jetson.yaml) instead of the frozen desktop export.
- On Jetson, the preferred production path is now the GPU setup documented in [`docs/perception_gpu_setup.md`](/home/asv/asv_autonomy/docs/perception_gpu_setup.md).
- The active online Blueboat perception path skips TorchSparse by default because it no longer uses the legacy SPVCNN path.
- On Jetson, the perception subprocess now defaults to `TRANSFORMERS_OFFLINE=1` and `HF_HUB_OFFLINE=1` so field bringup does not silently depend on internet access.
- If you intentionally need to refresh the Hugging Face cache, override those defaults for one run with `PERCEPTION_TRANSFORMERS_OFFLINE=0 PERCEPTION_HF_HUB_OFFLINE=0`.
- The active perception configs and Python entrypoints under [`src/ASV_perception/EndToEnd`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd) are bind-mounted into the Jetson container so the live perception runtime uses the host checkout directly.
- The compiled GroundingDINO / SAM2 package trees are intentionally left image-managed so their built CUDA extensions continue to work.
- If you change files outside those bind-mounted perception surfaces, rebuild the Docker image before rerunning setup because the remaining `src/` contents are still copied into the image.

For a fake-pose bringup without GPS or `drift`:

```bash
cd /home/asv/asv_autonomy
ENABLE_LOCALIZATION=false ENABLE_FAKE_POSE=true ENABLE_PERCEPTION=false ./scripts/host/start_autonomy.sh
```

For perception with synthetic motion:

```bash
cd /home/asv/asv_autonomy
ENABLE_LOCALIZATION=false ENABLE_FAKE_POSE=true FAKE_POSE_MODE=circle ./scripts/host/start_autonomy.sh
```

### 5. Optional one-command bringup

```bash
cd /home/asv/asv_autonomy
./scripts/host/start_system.sh
```

This starts:
- host sensors
- Docker autonomy

At this checkpoint, `start_system.sh` is most useful once GPS is added and localization is expected to run fully.

## Topic Checks

In a fresh host terminal:

```bash
cd /home/asv/asv_autonomy
source ./scripts/host/setup_ros.sh
ros2 topic list | grep -E 'vectornav|/sensors/camera|/tf_static'
```

Expected IMU topics include:
- `/vectornav/imu`
- `/vectornav/imu_uncompensated`

Expected camera topics include:
- `/sensors/camera/color/image_raw`
- `/sensors/camera/color/camera_info`
- `/sensors/camera/depth/image_rect_raw`
- `/sensors/camera/depth/camera_info`
- `/sensors/camera/aligned_depth_to_color/image_raw`

Expected LiDAR topic when enabled:
- `/sensors/lidar/points`

## TF Checks

Run these from a fresh host terminal:

```bash
cd /home/asv/asv_autonomy
source ./scripts/host/setup_ros.sh

ros2 run tf2_ros tf2_echo base_link imu_link
ros2 run tf2_ros tf2_echo base_link camera_link
ros2 run tf2_ros tf2_echo camera_link camera_color_optical_frame
```

Expected behavior:
- `base_link -> imu_link` should resolve from the Xacro
- `base_link -> camera_link` should resolve from the Xacro
- `camera_link -> camera_color_optical_frame` should resolve from the RealSense driver

At this checkpoint, do not use `odom -> base_link` as a health check yet.

## Current Expected Limitations

These are expected at this checkpoint:
- GPS is not connected
- `drift` cannot produce `/gt_pose`
- `odom -> base_link` is therefore not expected to exist yet
- RealSense may print intermittent `control_transfer` warnings
- `robot_state_publisher` may warn about root-link inertia; this is not a blocker

## Current TF Ownership

Real robot:
- Xacro owns:
  - `base_link -> imu_link`
  - `base_link -> gps_link`
  - `base_link -> lidar_link`
  - `base_link -> camera_link`
- RealSense owns:
  - `camera_link -> camera_color_frame`
  - `camera_link -> camera_color_optical_frame`
  - related internal camera frames

Simulation:
- the generic `camera_optical_frame` remains in the sim Xacro path only

## Current Config Files

VectorNav config:
- [`config/vectornav/blueboat_vn100.yaml`](/home/asv/asv_autonomy/config/vectornav/blueboat_vn100.yaml)

RealSense config:
- [`config/realsense/blueboat_d455.yaml`](/home/asv/asv_autonomy/config/realsense/blueboat_d455.yaml)

RoboSense config:
- [`config/lidar/blueboat_config.yaml`](/home/asv/asv_autonomy/config/lidar/blueboat_config.yaml)

LiDAR runbook:
- [`docs/lidar_host_setup.md`](/home/asv/asv_autonomy/docs/lidar_host_setup.md)

Robot Xacros:
- [`urdf/blueboat.xacro`](/home/asv/asv_autonomy/urdf/blueboat.xacro)
- [`urdf/blueboat_real.urdf.xacro`](/home/asv/asv_autonomy/urdf/blueboat_real.urdf.xacro)
- [`urdf/blueboat_sim.urdf.xacro`](/home/asv/asv_autonomy/urdf/blueboat_sim.urdf.xacro)

## Quick Recovery

If sensors look busy or duplicated:

```bash
cd /home/asv/asv_autonomy
./scripts/host/stop_sensors.sh
./scripts/host/start_sensors.sh
```

If the Docker stack gets into a weird state:

```bash
docker restart asv_dev
```

Then rerun:

```bash
cd /home/asv/asv_autonomy
ENABLE_LOCALIZATION=false ENABLE_PERCEPTION=false ./scripts/host/start_autonomy.sh
```
