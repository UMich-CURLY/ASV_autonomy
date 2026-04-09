#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

source "${SCRIPT_DIR}/setup_ros.sh"

if [ -n "${REALSENSE_WS:-}" ]; then
  REALSENSE_WS_CANDIDATES=("${REALSENSE_WS}")
else
  REALSENSE_WS_CANDIDATES=(
    "${HOME}/realsense/ros2"
    "${HOME}/realsense/ros2_ws"
    "${HOME}/asv_sensorsuite/ros2_ws"
  )
fi

REALSENSE_SETUP=""
for candidate in "${REALSENSE_WS_CANDIDATES[@]}"; do
  if [ -f "${candidate}/install/local_setup.bash" ]; then
    REALSENSE_SETUP="${candidate}/install/local_setup.bash"
    break
  fi
done

REALSENSE_CONFIG="${REALSENSE_CONFIG:-${REPO_ROOT}/config/realsense/blueboat_d455.yaml}"
CAMERA_NAMESPACE="${CAMERA_NAMESPACE:-sensors}"
# Keep this as "camera" so the wrapper publishes camera_link and related frames
# under the same root frame name used by the Xacro.
CAMERA_NAME="${CAMERA_NAME:-camera}"

if [ -z "${REALSENSE_SETUP}" ]; then
  echo "RealSense workspace not found. Set REALSENSE_WS or build the wrapper on the Jetson host." >&2
  exit 1
fi

if [ ! -f "${REALSENSE_CONFIG}" ]; then
  echo "RealSense config not found: ${REALSENSE_CONFIG}" >&2
  exit 1
fi

source "${REALSENSE_SETUP}"

ros2 daemon stop >/dev/null 2>&1 || true

echo "Launching RealSense from ${REALSENSE_SETUP}" >&2
echo "Using config ${REALSENSE_CONFIG} with ${CAMERA_NAMESPACE}/${CAMERA_NAME}" >&2

exec ros2 launch realsense2_camera rs_launch.py \
  camera_namespace:="${CAMERA_NAMESPACE}" \
  camera_name:="${CAMERA_NAME}" \
  config_file:="${REALSENSE_CONFIG}" \
  output:=screen \
  log_level:=info
