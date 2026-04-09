#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
ROS_ENV_FILE="${ROS_ENV_FILE:-${REPO_ROOT}/docker/ros.env}"

setup_ros_fail() {
  echo "$1" >&2
  if [[ "${BASH_SOURCE[0]}" != "${0}" ]]; then
    return 1
  fi
  exit 1
}

if [ ! -f /opt/ros/humble/setup.bash ]; then
  setup_ros_fail "ROS 2 Humble is not installed on this host."
fi

source /opt/ros/humble/setup.bash

if [ -f "${ROS_ENV_FILE}" ]; then
  set -a
  # shellcheck disable=SC1090
  source "${ROS_ENV_FILE}"
  set +a
fi

unset ROS_LOCALHOST_ONLY
