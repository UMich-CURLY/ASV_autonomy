# Blueboat Jetson Deployment

This document is the authoritative host/container split for the current working Blueboat stack.

The goal is to keep the deployment modular:
- the Jetson host owns hardware access and host ROS 2 sensor launchers
- Docker owns autonomy, robot description, localization, perception, and the GPU runtime
- persistent Docker volumes own the perception venv and downloaded model assets
- one host-side preparation script owns the clean container install flow

If you move this repo to another Jetson, this document should be enough to reproduce the same structure without relying on leftover state from the current machine.

The repo now also carries an explicit desktop sibling scaffold:
- [`desktop_deployment.md`](/home/asv/asv_autonomy/docs/desktop_deployment.md)

## Responsibilities

Host-side responsibilities:
- JetPack / CUDA / NVIDIA container runtime
- Docker Engine + Compose plugin
- ROS 2 Humble on the host
- host sensor workspaces:
  - VectorNav
  - RealSense ROS wrapper
  - RoboSense LiDAR ROS driver
- USB devices, serial devices, and NIC configuration
- launching host sensor nodes

Container-side responsibilities:
- robot_state_publisher
- map -> odom bootstrap
- pose TF rebroadcasting
- localization node
- online perception node
- Jetson GPU PyTorch runtime
- SAM2 / GroundingDINO editable installs

Shared contract between host and container:
- topics are exchanged over `network_mode: host`
- DDS settings come from [`docker/ros.env`](/home/asv/asv_autonomy/docker/ros.env)
- the host publishes sensor topics
- the container consumes those topics and publishes autonomy/perception outputs

## Current Host Requirements

Required on the Jetson host:
- JetPack 6.2 / CUDA 12.6-class environment
- Docker with NVIDIA runtime enabled
- ROS 2 Humble installed at `/opt/ros/humble`
- this repo checked out at `/home/asv/asv_autonomy`

Required host sensor workspaces:
- VectorNav:
  - default expected at `~/vectornav/install/setup.bash`
- RealSense:
  - default candidates:
    - `~/realsense/ros2/install/local_setup.bash`
    - `~/realsense/ros2_ws/install/local_setup.bash`
    - `~/asv_sensorsuite/ros2_ws/install/local_setup.bash`
- RoboSense LiDAR:
  - default candidates:
    - `~/lidar/install/setup.bash`
    - `~/lidar/install/local_setup.bash`
    - `~/lidar_ws/install/setup.bash`
    - `~/lidar_ws/install/local_setup.bash`

Repo-owned host configs:
- VectorNav: [`config/vectornav/blueboat_vn100.yaml`](/home/asv/asv_autonomy/config/vectornav/blueboat_vn100.yaml)
- RealSense: [`config/realsense/blueboat_d455.yaml`](/home/asv/asv_autonomy/config/realsense/blueboat_d455.yaml)
- LiDAR: [`config/lidar/blueboat_config.yaml`](/home/asv/asv_autonomy/config/lidar/blueboat_config.yaml)

## Current Container Requirements

The Docker image is built from:
- [`docker/Dockerfile.jetson`](/home/asv/asv_autonomy/docker/Dockerfile.jetson)

The running container is configured by:
- [`docker/compose.jetson.yaml`](/home/asv/asv_autonomy/docker/compose.jetson.yaml)

The container now persists critical perception state using Docker volumes:
- `perception_venv` -> `/opt/asv/.venvs`
- `sam2_checkpoints` -> `/opt/asv/src/ASV_perception/EndToEnd/Segmentation/checkpoints`
- `gdino_checkpoints` -> `/opt/asv/src/ASV_perception/EndToEnd/Segmentation/gdino_checkpoints`
- `huggingface_cache` -> `/root/.cache/huggingface`

That means:
- `docker compose down` is safe
- `docker compose down -v` will destroy the persisted perception runtime and model caches
- a freshly recreated container can be repopulated deterministically by rerunning the host preparation script
- once the preparation script has prewarmed the Hugging Face cache, Jetson perception can run without internet access

## One-Time Host Preflight

Before trying to run the stack on a Jetson host, run:

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/preflight_jetson.sh
```

This checks:
- Docker / Compose availability
- host ROS 2 Humble
- repo-owned config files
- expected host sensor workspaces
- basic device visibility
- whether the persistence volumes/container already exist

If you want to include LiDAR checks in preflight:

```bash
START_LIDAR=true bash ./scripts/host/preflight_jetson.sh
```

## Preferred Clean Container Install

The preferred way to lock in a Jetson cleanly is:

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/prepare_jetson_container.sh
```

This script:
- optionally runs the host preflight
- builds the Docker image
- force-recreates the container so it adopts the current Compose mounts
- installs the known-good Jetson GPU perception stack
- validates `torch`, `torchvision`, `sam2._C`, and `groundingdino._C`
- writes an install manifest to `/opt/asv/.venvs/ros2_grounded_sam2/asv_perception_install_manifest.txt`

This is the safest way to avoid relying on old writable-layer state from a previously debugged container.

## Installation Flow On A Fresh Jetson

1. Install host prerequisites:
   - JetPack / NVIDIA runtime
   - Docker
   - ROS 2 Humble
   - host sensor workspaces

2. Run the preflight:

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/preflight_jetson.sh
```

3. Prepare the container cleanly:

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/prepare_jetson_container.sh
```

4. Start host sensors:

```bash
cd /home/asv/asv_autonomy
START_LIDAR=true ./scripts/host/start_sensors.sh
```

5. Start autonomy in the container:

```bash
cd /home/asv/asv_autonomy
ENABLE_LOCALIZATION=false ENABLE_FAKE_POSE=true FAKE_POSE_MODE=circle ./scripts/host/start_autonomy.sh
```

## Clean Split In Practice

Host-owned launchers:
- [`scripts/host/start_vectornav.sh`](/home/asv/asv_autonomy/scripts/host/start_vectornav.sh)
- [`scripts/host/start_realsense.sh`](/home/asv/asv_autonomy/scripts/host/start_realsense.sh)
- [`scripts/host/start_lidar.sh`](/home/asv/asv_autonomy/scripts/host/start_lidar.sh)
- [`scripts/host/start_sensors.sh`](/home/asv/asv_autonomy/scripts/host/start_sensors.sh)

Container-owned autonomy entrypoints:
- [`scripts/host/start_autonomy.sh`](/home/asv/asv_autonomy/scripts/host/start_autonomy.sh)
- [`scripts/run_autonomy.sh`](/home/asv/asv_autonomy/scripts/run_autonomy.sh)
- [`scripts/setup_perception.sh`](/home/asv/asv_autonomy/scripts/setup_perception.sh)

Host ROS helper:
- [`scripts/host/setup_ros.sh`](/home/asv/asv_autonomy/scripts/host/setup_ros.sh)

Robot description:
- [`urdf/blueboat_real.urdf.xacro`](/home/asv/asv_autonomy/urdf/blueboat_real.urdf.xacro)

## Avoiding Conflicting Leftovers

The current working setup prefers the Jetson perception venv:
- `/opt/asv/.venvs/ros2_grounded_sam2`

If an old conda env named `ros2_grounded_sam2` still exists, the runtime will prefer the venv first. That means:
- on Jetson, a stale conda env should not affect normal autonomy runs anymore
- the Jetson runtime now expects the venv and does not silently fall back to conda

Recommended hygiene:
- do not rely on the old conda env for Jetson GPU runs
- prefer `bash ./scripts/host/prepare_jetson_container.sh` over hand-editing the container
- do not use `docker compose down -v` unless you intentionally want to wipe the perception state
- treat host workspaces as disposable build artifacts that can be rebuilt from source

## Traceability

This working deployment is now traceable through:
- host preflight: [`scripts/host/preflight_jetson.sh`](/home/asv/asv_autonomy/scripts/host/preflight_jetson.sh)
- clean container prep: [`scripts/host/prepare_jetson_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_jetson_container.sh)
- GPU perception setup: [`docs/perception_gpu_setup.md`](/home/asv/asv_autonomy/docs/perception_gpu_setup.md)
- LiDAR host setup: [`docs/lidar_host_setup.md`](/home/asv/asv_autonomy/docs/lidar_host_setup.md)
- install manifest inside the persisted venv:
  - `/opt/asv/.venvs/ros2_grounded_sam2/asv_perception_install_manifest.txt`

These docs and runtime artifacts together describe:
- what must exist on the Jetson host
- what is built and stored in Docker
- what persists across container recreation
