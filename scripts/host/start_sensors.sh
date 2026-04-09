#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

START_VECTORNAV="${START_VECTORNAV:-true}"
START_REALSENSE="${START_REALSENSE:-true}"
START_LIDAR="${START_LIDAR:-false}"
SENSOR_PIDS=()
INTERRUPTED=false

bash "${SCRIPT_DIR}/stop_sensors.sh"

cleanup() {
  if [ "${INTERRUPTED}" = "true" ]; then
    return
  fi

  for pid in "${SENSOR_PIDS[@]}"; do
    kill "${pid}" >/dev/null 2>&1 || true
  done
}

handle_interrupt() {
  INTERRUPTED=true
  trap - INT TERM
  wait || true
  exit 130
}

trap cleanup EXIT
trap handle_interrupt INT TERM

if [ "${START_VECTORNAV}" = "true" ]; then
  bash "${SCRIPT_DIR}/start_vectornav.sh" &
  SENSOR_PIDS+=("$!")
fi

if [ "${START_REALSENSE}" = "true" ]; then
  bash "${SCRIPT_DIR}/start_realsense.sh" &
  SENSOR_PIDS+=("$!")
fi

if [ "${START_LIDAR}" = "true" ]; then
  bash "${SCRIPT_DIR}/start_lidar.sh" &
  SENSOR_PIDS+=("$!")
fi

wait -n
