#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
COMPOSE_FILE="${COMPOSE_FILE:-${REPO_ROOT}/docker/compose.jetson.yaml}"
CONTAINER_NAME="${CONTAINER_NAME:-asv_dev}"
AUTONOMY_COMMAND="${AUTONOMY_COMMAND:-/opt/asv/scripts/run_autonomy.sh}"
ENABLE_LOCALIZATION="${ENABLE_LOCALIZATION:-true}"
ENABLE_PERCEPTION="${ENABLE_PERCEPTION:-true}"
ENABLE_FAKE_POSE="${ENABLE_FAKE_POSE:-false}"
FAKE_POSE_MODE="${FAKE_POSE_MODE:-stationary}"
FAKE_POSE_RATE_HZ="${FAKE_POSE_RATE_HZ:-20.0}"

if ! command -v docker >/dev/null 2>&1; then
  echo "docker is not installed on this host." >&2
  exit 1
fi

docker compose -f "${COMPOSE_FILE}" up -d

if ! docker exec "${CONTAINER_NAME}" bash -lc "source /opt/ros/humble/setup.bash && (command -v xacro >/dev/null 2>&1 || python3 -c 'import xacro' >/dev/null 2>&1)"; then
  echo "Container is missing xacro. Rebuilding the autonomy image..." >&2
  docker compose -f "${COMPOSE_FILE}" build
  docker compose -f "${COMPOSE_FILE}" up -d --force-recreate
fi

exec docker exec -it \
  -e ENABLE_LOCALIZATION="${ENABLE_LOCALIZATION}" \
  -e ENABLE_PERCEPTION="${ENABLE_PERCEPTION}" \
  -e ENABLE_FAKE_POSE="${ENABLE_FAKE_POSE}" \
  -e FAKE_POSE_MODE="${FAKE_POSE_MODE}" \
  -e FAKE_POSE_RATE_HZ="${FAKE_POSE_RATE_HZ}" \
  "${CONTAINER_NAME}" \
  bash -lc "${AUTONOMY_COMMAND}"
