#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

source "${SCRIPT_DIR}/setup_ros.sh"

VECTORNAV_WS="${VECTORNAV_WS:-${HOME}/vectornav}"
VECTORNAV_SETUP="${VECTORNAV_SETUP:-${VECTORNAV_WS}/install/setup.bash}"
VECTORNAV_CONFIG="${VECTORNAV_CONFIG:-${REPO_ROOT}/config/vectornav/blueboat_vn100.yaml}"

if [ ! -f "${VECTORNAV_SETUP}" ]; then
  echo "VectorNav workspace not found: ${VECTORNAV_SETUP}" >&2
  echo "Build the driver on the Jetson host first, or set VECTORNAV_WS." >&2
  exit 1
fi

if [ ! -f "${VECTORNAV_CONFIG}" ]; then
  echo "VectorNav config not found: ${VECTORNAV_CONFIG}" >&2
  exit 1
fi

source "${VECTORNAV_SETUP}"

ros2 daemon stop >/dev/null 2>&1 || true

cleanup() {
  for pid in "${VECTORNAV_PIDS[@]}"; do
    kill "${pid}" >/dev/null 2>&1 || true
  done
}

trap cleanup EXIT INT TERM

ros2 run vectornav vectornav --ros-args --params-file "${VECTORNAV_CONFIG}" &
VECTORNAV_NODE_PID=$!
ros2 run vectornav vn_sensor_msgs --ros-args --params-file "${VECTORNAV_CONFIG}" &
VECTORNAV_SENSOR_MSGS_PID=$!
VECTORNAV_PIDS=("${VECTORNAV_NODE_PID}" "${VECTORNAV_SENSOR_MSGS_PID}")

wait -n
