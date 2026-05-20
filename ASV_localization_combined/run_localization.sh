#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

PROFILE="vrx"
if [[ "${1:-}" == "vrx" || "${1:-}" == "real" || "${1:-}" == "isaac" ]]; then
  PROFILE="$1"
  shift
fi

CONFIG_FILE="${SCRIPT_DIR}/ROS2/drift_ros2/config/blueboat_${PROFILE}/ros_comm.yaml"
SETUP_FILE="${SCRIPT_DIR}/ROS2/install/setup.bash"

if [[ ! -f "${CONFIG_FILE}" ]]; then
  echo "Unknown localization profile '${PROFILE}'. Expected one of: vrx, real, isaac." >&2
  exit 1
fi

if [[ ! -f "${SETUP_FILE}" ]]; then
  echo "Missing ${SETUP_FILE}" >&2
  echo "Build first with: ${SCRIPT_DIR}/build_ros.sh" >&2
  exit 1
fi

if [[ -n "${CONDA_PREFIX:-}" && -n "${LD_LIBRARY_PATH:-}" ]]; then
  CLEANED_LD_LIBRARY_PATH=""
  IFS=':' read -r -a LD_PARTS <<< "${LD_LIBRARY_PATH}"
  for part in "${LD_PARTS[@]}"; do
    if [[ "${part}" == "${CONDA_PREFIX}/lib"* ]]; then
      continue
    fi
    if [[ -z "${CLEANED_LD_LIBRARY_PATH}" ]]; then
      CLEANED_LD_LIBRARY_PATH="${part}"
    else
      CLEANED_LD_LIBRARY_PATH="${CLEANED_LD_LIBRARY_PATH}:${part}"
    fi
  done
  export LD_LIBRARY_PATH="${CLEANED_LD_LIBRARY_PATH}"
fi

set +u
source /opt/ros/humble/setup.bash
source "${SETUP_FILE}"
set -u

export DRIFT_ROS_COMM_CONFIG="${DRIFT_ROS_COMM_CONFIG:-${CONFIG_FILE}}"
echo "Running DRIFT BlueBoat localization profile '${PROFILE}'"
echo "DRIFT_ROS_COMM_CONFIG=${DRIFT_ROS_COMM_CONFIG}"

ros2 run drift_ros2 wamv_gpsimu_ros2 "$@"
