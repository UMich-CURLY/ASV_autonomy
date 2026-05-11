#!/usr/bin/env bash
set -euo pipefail

#This script assumes:
#   conda activate asv_perception
#has been run.

export PYTHONNOUSERSITE=1

export CUDA_HOME="$CONDA_PREFIX"
export CUDA_PATH="$CONDA_PREFIX"
export PATH="$CUDA_HOME/bin:$PATH"
export LD_LIBRARY_PATH="$CONDA_PREFIX/lib:${LD_LIBRARY_PATH:-}"

export CPATH="$CONDA_PREFIX/targets/x86_64-linux/include:$CONDA_PREFIX/include:${CPATH:-}"
export CFLAGS="-I$CONDA_PREFIX/targets/x86_64-linux/include -I$CONDA_PREFIX/include"
export CXXFLAGS="-I$CONDA_PREFIX/targets/x86_64-linux/include -I$CONDA_PREFIX/include"

export CC="$CONDA_PREFIX/bin/x86_64-conda-linux-gnu-cc"
export CXX="$CONDA_PREFIX/bin/x86_64-conda-linux-gnu-c++"
export CUDAHOSTCXX="$CXX"


export TORCH_CUDA_ARCH_LIST="8.9"

export MAX_JOBS=1

echo "============================================================"
echo "Environment sanity check"
echo "============================================================"

echo "Python:"
which python
python --version

echo
echo "User site:"
python - <<'PY'
import site
print("ENABLE_USER_SITE:", site.ENABLE_USER_SITE)
if site.ENABLE_USER_SITE:
    raise SystemExit("ERROR: PYTHONNOUSERSITE is not active")
PY

echo
echo "nvcc:"
which nvcc
nvcc --version

echo
echo "Host compiler:"
which "$CC"
"$CC" --version | head -n 1
which "$CXX"
"$CXX" --version | head -n 1

echo
echo "PyTorch:"
python - <<'PY'
import torch
print("torch:", torch.__version__)
print("torch.version.cuda:", torch.version.cuda)
print("cuda available:", torch.cuda.is_available())
print("gpu:", torch.cuda.get_device_name(0) if torch.cuda.is_available() else "none")
if torch.version.cuda != "12.4":
    raise SystemExit("ERROR: torch.version.cuda must be 12.4")
PY

echo
echo "Header checks:"
if [ -e "$CONDA_PREFIX/include/nv/target" ]; then
    echo "found nv/target at $CONDA_PREFIX/include/nv/target"
elif [ -e "$CONDA_PREFIX/targets/x86_64-linux/include/nv/target" ]; then
    echo "found nv/target at $CONDA_PREFIX/targets/x86_64-linux/include/nv/target"
else
    echo "ERROR: missing nv/target. Check cuda-cccl / CUDA headers."
    exit 1
fi

test -e "$CONDA_PREFIX/include/google/dense_hash_map" && echo "found google/dense_hash_map"

if [ ! -e "$CONDA_PREFIX/include/google/dense_hash_map" ]; then
    echo "ERROR: missing google/dense_hash_map. Install sparsehash."
    exit 1
fi

echo
echo "============================================================"
echo "Installing packages with dependency workarounds"
echo "============================================================"

#we intentionally keep NumPy at 1.24.4 from conda.
python -m pip install --force-reinstall --no-deps \
  hydra-core==1.3.2 \
  omegaconf==2.3.0 \
  antlr4-python3-runtime==4.9.3 \
  iopath==0.1.10 \
  portalocker==3.2.0 \
  tqdm==4.67.1

python -m pip install --no-deps ros2-numpy==0.0.4
SAM2_BUILD_CUDA=0 python -m pip install --no-deps sam2==1.1.0

echo
echo "============================================================"
echo "Building local ConvBKI torchsparse"
echo "============================================================"

cd "$(dirname "$0")/src/semantic_mapping/ConvBKI/torchsparse"

git checkout v1.4.0

rm -rf build dist *.egg-info
python -m pip uninstall -y torchsparse || true

python setup.py install

cd "$(dirname "$0")"

echo
echo "============================================================"
echo "Final import test"
echo "============================================================"

python - <<'PY'
import numpy as np
print("numpy:", np.__version__)
assert np.__version__ == "1.24.4"

import torch
print("torch:", torch.__version__)
print("torch CUDA:", torch.version.cuda)
print("cuda available:", torch.cuda.is_available())

import torchvision
print("torchvision:", torchvision.__version__)

import sam2
print("sam2:", sam2.__file__)

import ros2_numpy
print("ros2_numpy:", ros2_numpy.__file__)

import torchsparse
print("torchsparse:", torchsparse.__file__)

from ultralytics import YOLO
print("ultralytics ok")
PY

echo
echo "ASV perception environment setup complete."
