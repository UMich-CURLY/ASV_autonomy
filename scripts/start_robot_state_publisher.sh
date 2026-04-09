#!/bin/bash
set -e

source /opt/ros/humble/setup.bash

ROBOT_XACRO="${ROBOT_XACRO:-/opt/asv/urdf/blueboat_real.urdf.xacro}"

if [ ! -f "${ROBOT_XACRO}" ]; then
  echo "Robot Xacro not found: ${ROBOT_XACRO}" >&2
  exit 1
fi

if command -v xacro >/dev/null 2>&1; then
  XACRO_CMD=(xacro "${ROBOT_XACRO}")
elif python3 -c "import xacro" >/dev/null 2>&1; then
  XACRO_CMD=(python3 -m xacro "${ROBOT_XACRO}")
else
  echo "xacro is not available in this container. Rebuild the Docker image." >&2
  exit 1
fi

URDF_TMP="$(mktemp /tmp/blueboat_robot_XXXXXX.urdf)"
PARAMS_TMP="$(mktemp /tmp/blueboat_robot_XXXXXX.yaml)"
cleanup() {
  rm -f "${URDF_TMP}"
  rm -f "${PARAMS_TMP}"
}
trap cleanup EXIT INT TERM

"${XACRO_CMD[@]}" > "${URDF_TMP}"

if [ ! -s "${URDF_TMP}" ]; then
  echo "Expanded robot description is empty." >&2
  exit 1
fi

{
  echo "robot_state_publisher:"
  echo "  ros__parameters:"
  echo "    use_sim_time: false"
  echo "    robot_description: |"
  sed 's/^/      /' "${URDF_TMP}"
} > "${PARAMS_TMP}"

ros2 run robot_state_publisher robot_state_publisher \
     --ros-args \
     --params-file "${PARAMS_TMP}"
