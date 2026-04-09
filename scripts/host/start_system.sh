#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

"${SCRIPT_DIR}/start_sensors.sh" &
SENSORS_PID=$!

cleanup() {
  kill "${SENSORS_PID}" >/dev/null 2>&1 || true
}

trap cleanup EXIT INT TERM

exec "${SCRIPT_DIR}/start_autonomy.sh"
