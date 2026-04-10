#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
COMPOSE_FILE="${COMPOSE_FILE:-${REPO_ROOT}/docker/compose.desktop.yaml}"
CONTAINER_NAME="${CONTAINER_NAME:-asv_dev}"

BUILD_IMAGE="${BUILD_IMAGE:-true}"
FORCE_RECREATE="${FORCE_RECREATE:-true}"

if [ "$(uname -m)" = "aarch64" ]; then
  echo "This helper is for desktop/x86 hosts. Use ./scripts/host/prepare_jetson_container.sh on Jetson." >&2
  exit 1
fi

if [ "${BUILD_IMAGE}" = "true" ]; then
  docker compose -f "${COMPOSE_FILE}" build
fi

if [ "${FORCE_RECREATE}" = "true" ]; then
  docker compose -f "${COMPOSE_FILE}" up -d --force-recreate
else
  docker compose -f "${COMPOSE_FILE}" up -d
fi

docker exec -i \
  -e PERCEPTION_TORCH_BACKEND=conda \
  "${CONTAINER_NAME}" \
  bash -lc '/opt/asv/scripts/setup_perception.sh'

docker exec -i \
  "${CONTAINER_NAME}" \
  bash -lc '/opt/asv/scripts/check_perception_runtime.sh'

echo
echo "Desktop container preparation completed."
echo "Use COMPOSE_FILE=${COMPOSE_FILE} when launching shared host scripts on desktop."
