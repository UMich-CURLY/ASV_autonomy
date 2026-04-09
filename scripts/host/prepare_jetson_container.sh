#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
COMPOSE_FILE="${COMPOSE_FILE:-${REPO_ROOT}/docker/compose.jetson.yaml}"
CONTAINER_NAME="${CONTAINER_NAME:-asv_dev}"

RUN_PREFLIGHT="${RUN_PREFLIGHT:-true}"
BUILD_IMAGE="${BUILD_IMAGE:-true}"
FORCE_RECREATE="${FORCE_RECREATE:-true}"

TORCH_PIP_INDEX_URL="${TORCH_PIP_INDEX_URL:-https://pypi.jetson-ai-lab.io/jp6/cu126/+simple}"
TORCH_PIP_TRUSTED_HOST="${TORCH_PIP_TRUSTED_HOST:-pypi.jetson-ai-lab.io}"
TORCH_INSTALL="${TORCH_INSTALL:-torch==2.8.0}"
TORCHVISION_INSTALL="${TORCHVISION_INSTALL:-torchvision==0.23.0}"
TORCHAUDIO_INSTALL="${TORCHAUDIO_INSTALL:-torchaudio==2.8.0}"
INSTALL_CUSPARSELT="${INSTALL_CUSPARSELT:-1}"

if [ "$(uname -m)" != "aarch64" ]; then
  echo "This helper is for Jetson-class aarch64 hosts only." >&2
  exit 1
fi

if [ "${RUN_PREFLIGHT}" = "true" ]; then
  "${REPO_ROOT}/scripts/host/preflight_jetson.sh"
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
  -e TORCH_PIP_INDEX_URL="${TORCH_PIP_INDEX_URL}" \
  -e TORCH_PIP_TRUSTED_HOST="${TORCH_PIP_TRUSTED_HOST}" \
  -e TORCH_INSTALL="${TORCH_INSTALL}" \
  -e TORCHVISION_INSTALL="${TORCHVISION_INSTALL}" \
  -e TORCHAUDIO_INSTALL="${TORCHAUDIO_INSTALL}" \
  -e INSTALL_CUSPARSELT="${INSTALL_CUSPARSELT}" \
  "${CONTAINER_NAME}" \
  bash -lc '/opt/asv/scripts/setup_perception.sh'

docker exec -i \
  "${CONTAINER_NAME}" \
  bash -lc '
    source /opt/asv/.venvs/ros2_grounded_sam2/bin/activate
    export LD_LIBRARY_PATH="/opt/asv/.venvs/ros2_grounded_sam2/lib/python3.10/site-packages/torch/lib:/usr/local/cuda/lib64:${LD_LIBRARY_PATH:-}"
    python -c "import torch, torchvision, sam2._C, groundingdino._C; print(\"torch\", torch.__version__); print(\"torchvision\", torchvision.__version__); print(\"cuda_available\", torch.cuda.is_available()); print(\"torch_cuda\", torch.version.cuda); print(\"gpu_name\", torch.cuda.get_device_name(0) if torch.cuda.is_available() else \"none\"); print(\"sam2_cuda_ext ok\"); print(\"groundingdino_cuda_ext ok\")"
  '

echo
echo "Jetson container preparation completed."
echo "Next steps:"
echo "  1. Start host sensors: ./scripts/host/start_sensors.sh"
echo "  2. Start autonomy:    ./scripts/host/start_autonomy.sh"
echo "  3. Inspect the manifest in the persisted venv if needed:"
echo "     docker exec -it ${CONTAINER_NAME} bash -lc 'cat /opt/asv/.venvs/ros2_grounded_sam2/asv_perception_install_manifest.txt'"
