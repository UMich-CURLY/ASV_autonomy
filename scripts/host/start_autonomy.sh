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
PERCEPTION_AUTO_SETUP="${PERCEPTION_AUTO_SETUP:-false}"
PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR:-/opt/asv/.venvs/ros2_grounded_sam2}"
ASV_PERCEPTION_CONFIG="${ASV_PERCEPTION_CONFIG:-}"
PERCEPTION_TRANSFORMERS_OFFLINE="${PERCEPTION_TRANSFORMERS_OFFLINE:-auto}"
PERCEPTION_HF_HUB_OFFLINE="${PERCEPTION_HF_HUB_OFFLINE:-auto}"

TORCH_PIP_INDEX_URL="${TORCH_PIP_INDEX_URL:-https://pypi.jetson-ai-lab.io/jp6/cu126/+simple}"
TORCH_PIP_TRUSTED_HOST="${TORCH_PIP_TRUSTED_HOST:-pypi.jetson-ai-lab.io}"
TORCH_INSTALL="${TORCH_INSTALL:-torch==2.8.0}"
TORCHVISION_INSTALL="${TORCHVISION_INSTALL:-torchvision==0.23.0}"
TORCHAUDIO_INSTALL="${TORCHAUDIO_INSTALL:-torchaudio==2.8.0}"
INSTALL_CUSPARSELT="${INSTALL_CUSPARSELT:-1}"

if ! command -v docker >/dev/null 2>&1; then
  echo "docker is not installed on this host." >&2
  exit 1
fi

validate_perception_runtime() {
  docker exec \
    -e PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR}" \
    -e ASV_PERCEPTION_CONFIG="${ASV_PERCEPTION_CONFIG}" \
    "${CONTAINER_NAME}" \
    bash -lc '/opt/asv/scripts/check_perception_runtime.sh --quiet'
}

repair_perception_runtime() {
  local container_arch
  container_arch="$(docker exec "${CONTAINER_NAME}" uname -m 2>/dev/null || echo unknown)"

  if [ "${container_arch}" = "aarch64" ]; then
    docker exec -i \
      -e PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR}" \
      -e TORCH_PIP_INDEX_URL="${TORCH_PIP_INDEX_URL}" \
      -e TORCH_PIP_TRUSTED_HOST="${TORCH_PIP_TRUSTED_HOST}" \
      -e TORCH_INSTALL="${TORCH_INSTALL}" \
      -e TORCHVISION_INSTALL="${TORCHVISION_INSTALL}" \
      -e TORCHAUDIO_INSTALL="${TORCHAUDIO_INSTALL}" \
      -e INSTALL_CUSPARSELT="${INSTALL_CUSPARSELT}" \
      "${CONTAINER_NAME}" \
      bash -lc '/opt/asv/scripts/setup_perception.sh'
    return
  fi

  docker exec -i \
    -e PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR}" \
    -e PERCEPTION_TORCH_BACKEND=conda \
    "${CONTAINER_NAME}" \
    bash -lc '/opt/asv/scripts/setup_perception.sh'
}

docker compose -f "${COMPOSE_FILE}" up -d

if ! docker exec "${CONTAINER_NAME}" bash -lc "source /opt/ros/humble/setup.bash && (command -v xacro >/dev/null 2>&1 || python3 -c 'import xacro' >/dev/null 2>&1)"; then
  echo "Container is missing xacro. Rebuilding the autonomy image..." >&2
  docker compose -f "${COMPOSE_FILE}" build
  docker compose -f "${COMPOSE_FILE}" up -d --force-recreate
fi

if [ "${ENABLE_PERCEPTION}" = "true" ]; then
  if ! validate_perception_runtime; then
    if [ "${PERCEPTION_AUTO_SETUP}" = "true" ]; then
      echo "Perception runtime validation failed; running /opt/asv/scripts/setup_perception.sh..." >&2
      repair_perception_runtime
      if ! validate_perception_runtime; then
        echo "Perception runtime is still invalid after setup. Inspect /opt/asv/.venvs/ros2_grounded_sam2/asv_perception_install_manifest.txt inside ${CONTAINER_NAME}." >&2
        exit 1
      fi
    else
      echo "Perception runtime validation failed. Rerun ./scripts/host/prepare_jetson_container.sh or set PERCEPTION_AUTO_SETUP=true." >&2
      exit 1
    fi
  fi
fi

exec docker exec -it \
  -e ENABLE_LOCALIZATION="${ENABLE_LOCALIZATION}" \
  -e ENABLE_PERCEPTION="${ENABLE_PERCEPTION}" \
  -e ENABLE_FAKE_POSE="${ENABLE_FAKE_POSE}" \
  -e FAKE_POSE_MODE="${FAKE_POSE_MODE}" \
  -e FAKE_POSE_RATE_HZ="${FAKE_POSE_RATE_HZ}" \
  -e PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR}" \
  -e ASV_PERCEPTION_CONFIG="${ASV_PERCEPTION_CONFIG}" \
  -e PERCEPTION_TRANSFORMERS_OFFLINE="${PERCEPTION_TRANSFORMERS_OFFLINE}" \
  -e PERCEPTION_HF_HUB_OFFLINE="${PERCEPTION_HF_HUB_OFFLINE}" \
  "${CONTAINER_NAME}" \
  bash -lc "${AUTONOMY_COMMAND}"
