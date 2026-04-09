#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

source "${SCRIPT_DIR}/setup_ros.sh"

if [ -n "${LIDAR_WS:-}" ]; then
  LIDAR_WS_CANDIDATES=("${LIDAR_WS}")
else
  LIDAR_WS_CANDIDATES=(
    "${HOME}/lidar"
    "${HOME}/lidar_ws"
    "${HOME}/asv_sensorsuite/lidar_ws"
  )
fi

LIDAR_SETUP=""
for candidate in "${LIDAR_WS_CANDIDATES[@]}"; do
  if [ -f "${candidate}/install/setup.bash" ]; then
    LIDAR_SETUP="${candidate}/install/setup.bash"
    break
  fi

  if [ -f "${candidate}/install/local_setup.bash" ]; then
    LIDAR_SETUP="${candidate}/install/local_setup.bash"
    break
  fi
done

LIDAR_CONFIG="${LIDAR_CONFIG:-${REPO_ROOT}/config/lidar/blueboat_config.yaml}"

if [ -z "${LIDAR_SETUP}" ]; then
  echo "RoboSense workspace not found. Set LIDAR_WS or build the driver on the Jetson host." >&2
  exit 1
fi

if [ ! -f "${LIDAR_CONFIG}" ]; then
  echo "LiDAR config not found: ${LIDAR_CONFIG}" >&2
  exit 1
fi

source "${LIDAR_SETUP}"

ros2 daemon stop >/dev/null 2>&1 || true

echo "Launching RoboSense LiDAR from ${LIDAR_SETUP}" >&2
echo "Using config ${LIDAR_CONFIG}" >&2
echo "Expecting live UDP packets on the configured MSOP/DIFOP ports." >&2

exec ros2 run rslidar_sdk rslidar_sdk_node --ros-args -p "config_path:=${LIDAR_CONFIG}"
