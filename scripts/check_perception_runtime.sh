#!/bin/bash
set -euo pipefail

QUIET=false
if [ "${1:-}" = "--quiet" ]; then
  QUIET=true
  shift
fi

if [ "$#" -ne 0 ]; then
  echo "Usage: $0 [--quiet]" >&2
  exit 2
fi

PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR:-/opt/asv/.venvs/ros2_grounded_sam2}"
PERCEPTION_DIR="${PERCEPTION_DIR:-/opt/asv/src/ASV_perception/EndToEnd}"
PERCEPTION_RUNTIME_KIND="${PERCEPTION_RUNTIME_KIND:-auto}"
PERCEPTION_CONDA_ENV="${PERCEPTION_CONDA_ENV:-ros2_grounded_sam2}"

if [ "${PERCEPTION_RUNTIME_KIND}" = "auto" ]; then
  if [ -x "${PERCEPTION_VENV_DIR}/bin/python" ]; then
    PERCEPTION_RUNTIME_KIND=venv
  elif command -v conda >/dev/null 2>&1 && conda env list | awk '{print $1}' | grep -qx "${PERCEPTION_CONDA_ENV}"; then
    PERCEPTION_RUNTIME_KIND=conda
  else
    echo "Perception runtime check failed: no persisted venv or conda env was found." >&2
    exit 1
  fi
fi

run_python() {
  if [ "${PERCEPTION_RUNTIME_KIND}" = "venv" ]; then
    "${PERCEPTION_VENV_DIR}/bin/python" "$@"
    return
  fi

  conda run -n "${PERCEPTION_CONDA_ENV}" \
    env LD_LIBRARY_PATH="${LD_LIBRARY_PATH}" \
    python "$@"
}

case "${PERCEPTION_RUNTIME_KIND}" in
  venv)
    if [ ! -x "${PERCEPTION_VENV_DIR}/bin/python" ]; then
      echo "Perception runtime check failed: missing Python interpreter at ${PERCEPTION_VENV_DIR}/bin/python." >&2
      exit 1
    fi

    TORCH_LIB_DIR="$("${PERCEPTION_VENV_DIR}/bin/python" - <<'PY'
import pathlib
import sys

print(pathlib.Path(sys.prefix) / f"lib/python{sys.version_info.major}.{sys.version_info.minor}/site-packages/torch/lib")
PY
)"

    export VIRTUAL_ENV="${PERCEPTION_VENV_DIR}"
    export PATH="${PERCEPTION_VENV_DIR}/bin:${PATH}"
    export LD_LIBRARY_PATH="${TORCH_LIB_DIR}:/usr/local/cuda/lib64:${LD_LIBRARY_PATH:-}"
    export PERCEPTION_RUNTIME_ROOT="${PERCEPTION_VENV_DIR}"
    ;;
  conda)
    if ! command -v conda >/dev/null 2>&1; then
      echo "Perception runtime check failed: conda is not available in PATH." >&2
      exit 1
    fi

    CONDA_PREFIX_PATH="$(conda run -n "${PERCEPTION_CONDA_ENV}" python - <<'PY'
import sys

print(sys.prefix)
PY
)"

    if [ -z "${CONDA_PREFIX_PATH}" ]; then
      echo "Perception runtime check failed: could not resolve the conda prefix for ${PERCEPTION_CONDA_ENV}." >&2
      exit 1
    fi

    export LD_LIBRARY_PATH="${CONDA_PREFIX_PATH}/lib:${LD_LIBRARY_PATH:-}"
    export PERCEPTION_RUNTIME_ROOT="${CONDA_PREFIX_PATH}"
    ;;
  *)
    echo "Perception runtime check failed: unsupported PERCEPTION_RUNTIME_KIND=${PERCEPTION_RUNTIME_KIND}." >&2
    exit 1
    ;;
esac

export PERCEPTION_RUNTIME_KIND
export ASV_PERCEPTION_CHECK_VERBOSE=0

if [ "${QUIET}" != "true" ]; then
  export ASV_PERCEPTION_CHECK_VERBOSE=1
fi

run_python - <<'PY'
import os
import sys
from pathlib import Path

perception_dir = Path(os.environ.get("PERCEPTION_DIR", "/opt/asv/src/ASV_perception/EndToEnd"))
verbose = os.environ.get("ASV_PERCEPTION_CHECK_VERBOSE") == "1"

if not perception_dir.exists():
    raise SystemExit(f"Perception source tree is missing at {perception_dir}.")

if str(perception_dir) not in sys.path:
    sys.path.insert(0, str(perception_dir))

import torch
import torchvision
import yaml
import sam2._C
import groundingdino._C

from config_utils import CONFIG_ENV_VAR, resolve_model_config_path


def info(message: str) -> None:
    if verbose:
        print(message)


default_sam2_variant = os.environ.get("SAM2_VARIANT", "small").strip().lower()
sam2_variants = {
    "tiny": "sam2.1_hiera_tiny.pt",
    "small": "sam2.1_hiera_small.pt",
    "base_plus": "sam2.1_hiera_base_plus.pt",
    "large": "sam2.1_hiera_large.pt",
}

config_name, config_path = resolve_model_config_path(os.environ.get(CONFIG_ENV_VAR))
with Path(config_path).open("r", encoding="utf-8") as stream:
    model_params = yaml.safe_load(stream) or {}

segmentation_config = model_params.get("segmentation", {})
sam2_variant = str(segmentation_config.get("sam2_variant", default_sam2_variant)).strip().lower()
if sam2_variant not in sam2_variants:
    supported = ", ".join(sorted(sam2_variants))
    raise SystemExit(f"Unsupported SAM2 variant '{sam2_variant}' in perception config. Expected one of: {supported}.")

sam2_checkpoint_name = sam2_variants[sam2_variant]
sam2_checkpoint_path = perception_dir / "Segmentation" / "checkpoints" / sam2_checkpoint_name
grounding_dino_checkpoint_path = (
    perception_dir / "Segmentation" / "gdino_checkpoints" / "groundingdino_swint_ogc.pth"
)

if not sam2_checkpoint_path.exists():
    raise SystemExit(
        f"Perception runtime check failed: required SAM2 checkpoint is missing: {sam2_checkpoint_path}."
    )

if not grounding_dino_checkpoint_path.exists():
    raise SystemExit(
        "Perception runtime check failed: required GroundingDINO checkpoint is missing: "
        f"{grounding_dino_checkpoint_path}."
    )

manifest_path = Path(os.environ["PERCEPTION_RUNTIME_ROOT"]) / "asv_perception_install_manifest.txt"
info(f"perception_config={config_name} ({config_path})")
info(f"sam2_variant={sam2_variant}")
info(f"sam2_checkpoint={sam2_checkpoint_path}")
info(f"groundingdino_checkpoint={grounding_dino_checkpoint_path}")
info(f"install_manifest={manifest_path}")
info(
    "torch="
    f"{torch.__version__} torchvision={torchvision.__version__} "
    f"cuda_available={torch.cuda.is_available()} torch_cuda={torch.version.cuda}"
)
info("perception_runtime=ok")
PY
