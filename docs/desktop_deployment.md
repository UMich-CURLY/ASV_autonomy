# Blueboat Desktop Deployment

This document marks the desktop sibling of the current Jetson deployment.

The goal is to keep the architecture consistent across platforms:
- the same ROS nodes, topics, TF contract, and runtime scripts
- a different Docker base image and perception install backend where the platform requires it

Current desktop-target files:
- [`docker/Dockerfile.desktop`](/home/asv/asv_autonomy/docker/Dockerfile.desktop)
- [`docker/compose.desktop.yaml`](/home/asv/asv_autonomy/docker/compose.desktop.yaml)
- [`scripts/host/prepare_desktop_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_desktop_container.sh)
- [`src/ASV_perception/EndToEnd/environment.desktop.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/environment.desktop.yaml)

Current Jetson-target files:
- [`docker/Dockerfile.jetson`](/home/asv/asv_autonomy/docker/Dockerfile.jetson)
- [`docker/compose.jetson.yaml`](/home/asv/asv_autonomy/docker/compose.jetson.yaml)
- [`scripts/host/prepare_jetson_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_jetson_container.sh)
- [`src/ASV_perception/EndToEnd/environment.jetson.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/environment.jetson.yaml)

Shared runtime entrypoints:
- [`scripts/run_autonomy.sh`](/home/asv/asv_autonomy/scripts/run_autonomy.sh)
- [`scripts/setup_perception.sh`](/home/asv/asv_autonomy/scripts/setup_perception.sh)
- [`scripts/host/start_autonomy.sh`](/home/asv/asv_autonomy/scripts/host/start_autonomy.sh)

Status:
- Jetson target: validated and currently working
- Desktop target: scaffolded, not yet validated end-to-end

When desktop work starts, the intent is to preserve the same autonomy/perception architecture and only change:
- the image base and package installation path
- the platform-specific preparation script
