#!/bin/bash
set -euo pipefail

source /opt/conda/etc/profile.d/conda.sh

CONDA_ROOT=${CONDA_ROOT:-/opt/conda}
PERCEPTION_DIR=/opt/asv/src/ASV_perception/EndToEnd
SEGMENTATION_DIR=${PERCEPTION_DIR}/Segmentation
ENV_NAME=ros2_grounded_sam2
VENV_DIR=${PERCEPTION_VENV_DIR:-/opt/asv/.venvs/${ENV_NAME}}
JETSON_VENV_REQUIREMENTS=${JETSON_VENV_REQUIREMENTS:-/opt/asv/scripts/perception_jetson_venv_requirements.txt}
ARCH=$(uname -m)
if [ "$(uname -m)" = "aarch64" ] && [ -f "${PERCEPTION_DIR}/environment.jetson.yaml" ]; then
  DEFAULT_ENV_FILE=${PERCEPTION_DIR}/environment.jetson.yaml
else
  DEFAULT_ENV_FILE=${PERCEPTION_DIR}/environment.desktop.yaml
fi
ENV_FILE=${PERCEPTION_ENV_FILE:-${DEFAULT_ENV_FILE}}
PERCEPTION_TORCH_BACKEND=${PERCEPTION_TORCH_BACKEND:-auto}
TORCH_INSTALL=${TORCH_INSTALL:-}
TORCHVISION_INSTALL=${TORCHVISION_INSTALL:-}
TORCHAUDIO_INSTALL=${TORCHAUDIO_INSTALL:-}
TORCH_PIP_INDEX_URL=${TORCH_PIP_INDEX_URL:-}
TORCH_PIP_EXTRA_INDEX_URL=${TORCH_PIP_EXTRA_INDEX_URL:-}
TORCH_PIP_TRUSTED_HOST=${TORCH_PIP_TRUSTED_HOST:-}
INSTALL_CUSPARSELT=${INSTALL_CUSPARSELT:-auto}
TORCH_CUDA_ARCH_LIST=${TORCH_CUDA_ARCH_LIST:-8.7}
CUDA_HOME=${CUDA_HOME:-/usr/local/cuda}
INSTALL_TORCHSPARSE=${INSTALL_TORCHSPARSE:-0}
PREWARM_HF_TEXT_ENCODER=${PREWARM_HF_TEXT_ENCODER:-1}
HF_TEXT_ENCODER_MODEL_ID=${HF_TEXT_ENCODER_MODEL_ID:-bert-base-uncased}

if [ "${PERCEPTION_TORCH_BACKEND}" = "auto" ]; then
  if [ "${ARCH}" = "aarch64" ]; then
    PERCEPTION_TORCH_BACKEND=jetson
  else
    PERCEPTION_TORCH_BACKEND=conda
  fi
fi

if [ "${PERCEPTION_TORCH_BACKEND}" = "jetson" ]; then
  PERCEPTION_RUNTIME_KIND=venv
else
  PERCEPTION_RUNTIME_KIND=conda
fi

if [ -z "${SAM2_BUILD_CUDA+x}" ]; then
  if [ "${PERCEPTION_TORCH_BACKEND}" = "jetson" ]; then
    SAM2_BUILD_CUDA=1
  else
    SAM2_BUILD_CUDA=0
  fi
fi

venv_torch_lib_dir() {
  "${VENV_DIR}/bin/python" - <<'PY'
import pathlib
import sys

print(pathlib.Path(sys.prefix) / f"lib/python{sys.version_info.major}.{sys.version_info.minor}/site-packages/torch/lib")
PY
}

ensure_jetson_venv() {
  if [ ! -x "${VENV_DIR}/bin/python" ]; then
    echo "Creating Jetson perception venv at ${VENV_DIR}..."
    python3 -m venv "${VENV_DIR}"
  fi

  env PATH="${VENV_DIR}/bin:${PATH}" \
    "${VENV_DIR}/bin/python" -m pip install --upgrade pip setuptools wheel
}

run_in_env() {
  if [ "${PERCEPTION_RUNTIME_KIND}" = "venv" ]; then
    local torch_lib_dir
    torch_lib_dir=$(venv_torch_lib_dir 2>/dev/null || true)
    env \
      VIRTUAL_ENV="${VENV_DIR}" \
      PATH="${VENV_DIR}/bin:${PATH}" \
      LD_LIBRARY_PATH="${torch_lib_dir}:${CUDA_HOME}/lib64:${LD_LIBRARY_PATH:-}" \
      "$@"
  else
    conda run -n "${ENV_NAME}" env LD_LIBRARY_PATH="${CONDA_ROOT}/envs/${ENV_NAME}/lib:${LD_LIBRARY_PATH:-}" "$@"
  fi
}

write_install_manifest() {
  local manifest_path
  local runtime_root

  if [ "${PERCEPTION_RUNTIME_KIND}" = "venv" ]; then
    runtime_root="${VENV_DIR}"
  else
    runtime_root="/opt/conda/envs/${ENV_NAME}"
  fi

  manifest_path="${runtime_root}/asv_perception_install_manifest.txt"

  {
    echo "install_utc=$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
    echo "runtime_kind=${PERCEPTION_RUNTIME_KIND}"
    echo "torch_backend=${PERCEPTION_TORCH_BACKEND}"
    echo "runtime_root=${runtime_root}"
    echo "env_file=${ENV_FILE}"
    echo "torch_install=${TORCH_INSTALL:-<image_or_env_managed>}"
    echo "torchvision_install=${TORCHVISION_INSTALL:-<image_or_env_managed>}"
    echo "torchaudio_install=${TORCHAUDIO_INSTALL:-<not_requested>}"
    echo "torch_pip_index_url=${TORCH_PIP_INDEX_URL:-<default>}"
    echo "install_cusparselt=${INSTALL_CUSPARSELT}"
    echo "sam2_build_cuda=${SAM2_BUILD_CUDA}"
    echo "torch_cuda_arch_list=${TORCH_CUDA_ARCH_LIST}"
    echo "cuda_home=${CUDA_HOME}"
    echo "segmentation_dir=${SEGMENTATION_DIR}"
    echo "prewarm_hf_text_encoder=${PREWARM_HF_TEXT_ENCODER}"
    echo "hf_text_encoder_model_id=${HF_TEXT_ENCODER_MODEL_ID}"
  } > "${manifest_path}"

  run_in_env python - <<'PY' >> "${manifest_path}"
import platform
import sys

print(f"python={platform.python_version()}")
print(f"platform={platform.platform()}")
print(f"machine={platform.machine()}")

try:
    import torch
    print(f"torch={torch.__version__}")
    print(f"torch_cuda_available={torch.cuda.is_available()}")
    print(f"torch_cuda={torch.version.cuda}")
except Exception as exc:
    print(f"torch_import_error={exc}")

try:
    import torchvision
    print(f"torchvision={torchvision.__version__}")
except Exception as exc:
    print(f"torchvision_import_error={exc}")

for module_name in ("sam2._C", "groundingdino._C"):
    try:
        __import__(module_name)
        print(f"{module_name}=ok")
    except Exception as exc:
        print(f"{module_name}={exc}")
PY

  echo "Wrote perception install manifest to ${manifest_path}"
}

prewarm_huggingface_assets() {
  if [ "${PREWARM_HF_TEXT_ENCODER}" != "1" ]; then
    echo "Skipping Hugging Face text encoder prewarm."
    return
  fi

  echo "Prewarming Hugging Face cache for ${HF_TEXT_ENCODER_MODEL_ID}..."
  run_in_env env HF_TEXT_ENCODER_MODEL_ID="${HF_TEXT_ENCODER_MODEL_ID}" python - <<'PY'
import os
from transformers import AutoTokenizer, BertModel

model_id = os.environ["HF_TEXT_ENCODER_MODEL_ID"]

tokenizer = AutoTokenizer.from_pretrained(model_id)
model = BertModel.from_pretrained(model_id)

print("huggingface_tokenizer_vocab_size", len(tokenizer))
print("huggingface_text_encoder_hidden_size", model.config.hidden_size)
print("huggingface_text_encoder_model_id", model_id)
PY

  echo "Validating offline Hugging Face cache for ${HF_TEXT_ENCODER_MODEL_ID}..."
  run_in_env env \
    HF_TEXT_ENCODER_MODEL_ID="${HF_TEXT_ENCODER_MODEL_ID}" \
    TRANSFORMERS_OFFLINE=1 \
    HF_HUB_OFFLINE=1 \
    python - <<'PY'
import os
from transformers import AutoTokenizer, BertModel

model_id = os.environ["HF_TEXT_ENCODER_MODEL_ID"]

AutoTokenizer.from_pretrained(model_id, local_files_only=True)
BertModel.from_pretrained(model_id, local_files_only=True)

print("huggingface_offline_cache_ok", model_id)
PY
}

install_jetson_pytorch() {
  if [ -z "${TORCH_INSTALL}" ]; then
    echo
    echo "Jetson GPU mode requires TORCH_INSTALL to point at an official NVIDIA PyTorch wheel."
    echo "Set TORCH_INSTALL (and usually TORCHVISION_INSTALL) before rerunning this script."
    echo
    echo "Example:"
    echo "  export TORCH_INSTALL=<official NVIDIA wheel URL>"
    echo "  export TORCHVISION_INSTALL=<matching torchvision wheel or package spec>"
    echo "  docker exec -it asv_dev bash -lc '/opt/asv/scripts/setup_perception.sh'"
    echo
    exit 1
  fi

  if [ ! -d "${CUDA_HOME}" ]; then
    echo
    echo "Expected CUDA toolkit under ${CUDA_HOME}, but it was not found."
    echo "The Jetson GPU perception path needs a container/image with CUDA toolkit files available."
    echo
    exit 1
  fi

  pip_index_args=()
  if [ -n "${TORCH_PIP_INDEX_URL}" ]; then
    pip_index_args+=(--index-url "${TORCH_PIP_INDEX_URL}")
  fi
  if [ -n "${TORCH_PIP_EXTRA_INDEX_URL}" ]; then
    pip_index_args+=(--extra-index-url "${TORCH_PIP_EXTRA_INDEX_URL}")
  fi
  if [ -n "${TORCH_PIP_TRUSTED_HOST}" ]; then
    pip_index_args+=(--trusted-host "${TORCH_PIP_TRUSTED_HOST}")
  fi

  pip_install_torch_component() {
    local spec="$1"
    if [ -z "${spec}" ]; then
      return 0
    fi
    run_in_env pip install --no-cache-dir --no-deps "${pip_index_args[@]}" "${spec}"
  }

  if [ "${INSTALL_CUSPARSELT}" = "1" ]; then
    tmpdir=$(mktemp -d)
    (
      cd "${tmpdir}"
      wget -q https://raw.githubusercontent.com/pytorch/pytorch/5c6af2b583709f6176898c017424dc9981023c28/.ci/docker/common/install_cusparselt.sh
      chmod +x install_cusparselt.sh
      export CUDA_VERSION="${CUDA_VERSION:-12.2}"
      ./install_cusparselt.sh
    )
    rm -rf "${tmpdir}"
  elif [ "${INSTALL_CUSPARSELT}" = "auto" ]; then
    echo "Skipping cuSPARSELT auto-install. Set INSTALL_CUSPARSELT=1 if your chosen NVIDIA torch wheel requires it."
  fi

  echo "Installing NVIDIA PyTorch wheel into ${ENV_NAME}..."
  run_in_env pip uninstall -y torch torchvision torchaudio >/dev/null 2>&1 || true
  pip_install_torch_component "${TORCH_INSTALL}"

  if [ -n "${TORCHVISION_INSTALL}" ]; then
    pip_install_torch_component "${TORCHVISION_INSTALL}"
  else
    echo "TORCHVISION_INSTALL is not set; relying on torchvision already being present in the environment."
  fi

  if [ -n "${TORCHAUDIO_INSTALL}" ]; then
    pip_install_torch_component "${TORCHAUDIO_INSTALL}"
  fi

  if [ -f "${JETSON_VENV_REQUIREMENTS}" ]; then
    echo "Installing Jetson perception Python requirements from ${JETSON_VENV_REQUIREMENTS}..."
    run_in_env python -m pip install --no-cache-dir -r "${JETSON_VENV_REQUIREMENTS}"
  else
    echo "Jetson requirements file ${JETSON_VENV_REQUIREMENTS} was not found."
    echo "The venv path expects that requirements file to exist."
    exit 1
  fi

  run_in_env python - <<'PY'
import sys
import torch

print("torch", torch.__version__, "cuda_available", torch.cuda.is_available(), "torch_cuda", torch.version.cuda)
if not torch.cuda.is_available():
    raise SystemExit("PyTorch installed, but CUDA is not available inside the perception environment.")

try:
    import torchvision
    print("torchvision", torchvision.__version__)
except Exception as exc:
    raise SystemExit(f"torchvision import failed after PyTorch install: {exc}")
PY
}

cd "${PERCEPTION_DIR}"

if [ "${PERCEPTION_RUNTIME_KIND}" = "conda" ]; then
  echo "Creating Conda environment from ${ENV_FILE}..."
  if conda env list | awk '{print $1}' | grep -qx "${ENV_NAME}"; then
    mamba env update -n "${ENV_NAME}" -f "${ENV_FILE}" --prune || {
      echo
      echo "The selected perception environment file did not solve cleanly."
      echo "On Jetson, prefer the portable aarch64 spec in environment.jetson.yaml."
      echo
      echo "Open the selected environment file, adjust versions, and rerun this script."
      exit 1
    }
  else
    mamba env create -f "${ENV_FILE}" || {
      echo
      echo "The selected perception environment file did not solve cleanly."
      echo "On Jetson, prefer the portable aarch64 spec in environment.jetson.yaml."
      echo
      echo "Open the selected environment file, adjust versions, and rerun this script."
      exit 1
    }
  fi
else
  ensure_jetson_venv
fi

case "${PERCEPTION_TORCH_BACKEND}" in
  jetson)
    install_jetson_pytorch
    ;;
  conda)
    run_in_env python -c "import torch; print('torch', torch.__version__, 'cuda_available', torch.cuda.is_available(), 'torch_cuda', torch.version.cuda)"
    ;;
  *)
    echo "Unsupported PERCEPTION_TORCH_BACKEND=${PERCEPTION_TORCH_BACKEND}. Use 'auto', 'jetson', or 'conda'."
    exit 1
    ;;
esac

echo "Installing segmentation package..."
run_in_env env \
  SAM2_BUILD_CUDA="${SAM2_BUILD_CUDA}" \
  TORCH_CUDA_ARCH_LIST="${TORCH_CUDA_ARCH_LIST}" \
  CUDA_HOME="${CUDA_HOME}" \
  pip install --no-build-isolation --no-deps -e "${SEGMENTATION_DIR}"
run_in_env env \
  TORCH_CUDA_ARCH_LIST="${TORCH_CUDA_ARCH_LIST}" \
  CUDA_HOME="${CUDA_HOME}" \
  pip install --no-build-isolation --no-deps -e "${SEGMENTATION_DIR}/grounding_dino"

echo "Downloading checkpoints..."
cd "${SEGMENTATION_DIR}/checkpoints"
bash download_ckpts.sh
cd "${SEGMENTATION_DIR}/gdino_checkpoints"
bash download_ckpts.sh

prewarm_huggingface_assets

if [ "${INSTALL_TORCHSPARSE}" = "1" ]; then
  cd "${PERCEPTION_DIR}"

  if [ ! -d torchsparse ]; then
    git clone https://github.com/mit-han-lab/torchsparse.git
  fi

  cd torchsparse
  git checkout v1.4.0

  echo "Building TorchSparse inside the Conda env..."
  run_in_env python setup.py install || {
    echo
    echo "TorchSparse failed to build. That is the most likely Jetson patch point."
    echo "The active online perception path does not require TorchSparse, so leave"
    echo "INSTALL_TORCHSPARSE=0 unless you are intentionally reviving the old SPVCNN path."
    exit 1
  }
else
  echo "Skipping TorchSparse install; the active online perception path does not require it."
fi

echo
echo "Final perception environment validation:"
run_in_env python - <<'PY'
import torch
print("torch", torch.__version__, "cuda_available", torch.cuda.is_available(), "torch_cuda", torch.version.cuda)
try:
    import torchvision
    print("torchvision", torchvision.__version__)
except Exception as exc:
    print("torchvision import failed:", exc)
for module_name in ("sam2._C", "groundingdino._C"):
    try:
        __import__(module_name)
        print(module_name, "import ok")
    except Exception as exc:
        print(module_name, "import failed:", exc)
PY

write_install_manifest

echo
echo "Perception environment setup completed."
