# Blueboat Perception GPU Setup

This guide captures the intended Jetson GPU path for Blueboat perception.

Use this instead of the older CPU-only Conda path when validating online perception performance.

For the authoritative host/container split, also see:
- [`jetson_deployment.md`](/home/asv/asv_autonomy/docs/jetson_deployment.md)

## Goals

- use a normal `venv` on Jetson for the GPU runtime
- install NVIDIA's Jetson PyTorch wheel explicitly
- build SAM2 and GroundingDINO against that GPU-enabled PyTorch
- fail early if CUDA is not visible in the container

## Repo Changes

The Jetson environment file no longer installs `torch` or `torchvision` from `conda-forge`:
- [`environment.jetson.yaml`](/home/asv/asv_autonomy/src/ASV_perception/EndToEnd/environment.jetson.yaml)

Instead, the setup script expects the Jetson GPU torch stack to be installed explicitly and now creates a Jetson-specific `venv`:
- [`setup_perception.sh`](/home/asv/asv_autonomy/scripts/setup_perception.sh)
- [`perception_jetson_venv_requirements.txt`](/home/asv/asv_autonomy/scripts/perception_jetson_venv_requirements.txt)

Important behaviors:
- `PERCEPTION_TORCH_BACKEND=auto` selects `jetson` on `aarch64`
- Jetson mode uses `/opt/asv/.venvs/ros2_grounded_sam2`
- `SAM2_BUILD_CUDA` defaults to `1` in Jetson mode
- editable installs use `--no-deps` so they do not overwrite the chosen torch stack
- `TORCH_CUDA_ARCH_LIST` defaults to `8.7` for Orin-class Jetsons
- when running through Compose, the venv and model assets persist in Docker volumes

## Required Inputs

Before running the setup script in Jetson GPU mode, choose:

- `TORCH_INSTALL`
  - package spec such as `torch==2.8.0`, or an official NVIDIA wheel URL
- `TORCHVISION_INSTALL`
  - matching torchvision package spec or wheel URL
- optionally `TORCHAUDIO_INSTALL`
- optionally `INSTALL_CUSPARSELT=1`
  - some newer NVIDIA wheels require this
- optionally `TORCH_PIP_INDEX_URL`
  - recommended for the Jetson AI Lab package index
- optionally `TORCH_PIP_TRUSTED_HOST`
  - useful for private/simple indexes without standard CA setup

Reference:
- NVIDIA Jetson PyTorch install guide: <https://docs.nvidia.com/deeplearning/frameworks/install-pytorch-jetson-platform/index.html>
- NVIDIA Jetson PyTorch release notes / compatibility matrix: <https://docs.nvidia.com/deeplearning/frameworks/install-pytorch-jetson-platform-release-notes/pytorch-jetson-rel.html>

## Container Workflow

For the normal reproducible path, prefer the host wrapper:

```bash
cd /home/asv/asv_autonomy
bash ./scripts/host/prepare_jetson_container.sh
```

If you need to debug the install manually from an already running `asv_dev` container, run:

```bash
cd /home/asv/asv_autonomy

docker exec -it asv_dev bash -lc '
  export TORCH_PIP_INDEX_URL="https://pypi.jetson-ai-lab.io/jp6/cu126/+simple"
  export TORCH_PIP_TRUSTED_HOST="pypi.jetson-ai-lab.io"
  export TORCH_INSTALL="torch==2.8.0"
  export TORCHVISION_INSTALL="torchvision==0.23.0"
  export INSTALL_CUSPARSELT=1
  /opt/asv/scripts/setup_perception.sh
'
```

This package-spec + index flow is preferred over hardcoded hashed wheel URLs because the index can rotate underlying file paths while preserving the package version contract.

## Validation

After setup, verify CUDA is visible from the perception environment:

```bash
docker exec -it asv_dev bash -lc '
  source /opt/asv/.venvs/ros2_grounded_sam2/bin/activate
  export LD_LIBRARY_PATH="/opt/asv/.venvs/ros2_grounded_sam2/lib/python3.10/site-packages/torch/lib:/usr/local/cuda/lib64:${LD_LIBRARY_PATH:-}"
  python - <<'"'"'PY'"'"'
import torch, torchvision
print("torch", torch.__version__)
print("torchvision", torchvision.__version__)
print("cuda_available", torch.cuda.is_available())
print("torch_cuda", torch.version.cuda)
PY
'
```

The expected result is:

- `cuda_available True`
- a non-empty `torch_cuda`
- no `Failed to load custom C++ ops` warning during later perception startup

## Current Limitation

This guide only covers the packaging/runtime slice.

It does not yet:
- benchmark end-to-end throughput
- add projection-only debug mode
- automatically migrate old writable-layer state from containers created before the persistence volumes existed
  - The clean answer is to recreate the container with [`prepare_jetson_container.sh`](/home/asv/asv_autonomy/scripts/host/prepare_jetson_container.sh) and let it repopulate the persisted venv/checkpoints.
