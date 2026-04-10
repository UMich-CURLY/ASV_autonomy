#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
COMPOSE_FILE="${COMPOSE_FILE:-${REPO_ROOT}/docker/compose.jetson.yaml}"
CONTAINER_NAME="${CONTAINER_NAME:-asv_dev}"

START_VECTORNAV="${START_VECTORNAV:-true}"
START_REALSENSE="${START_REALSENSE:-true}"
START_LIDAR="${START_LIDAR:-false}"

failures=0
warnings=0

pass() {
  printf '[PASS] %s\n' "$1"
}

warn() {
  warnings=$((warnings + 1))
  printf '[WARN] %s\n' "$1" >&2
}

fail() {
  failures=$((failures + 1))
  printf '[FAIL] %s\n' "$1" >&2
}

check_cmd() {
  local cmd="$1"
  local label="$2"
  if command -v "${cmd}" >/dev/null 2>&1; then
    pass "${label}: $(command -v "${cmd}")"
  else
    fail "${label} is missing"
  fi
}

check_file() {
  local path="$1"
  local label="$2"
  if [ -e "${path}" ]; then
    pass "${label}: ${path}"
  else
    fail "${label} not found: ${path}"
  fi
}

resolve_realsense_setup() {
  if [ -n "${REALSENSE_WS:-}" ] && [ -f "${REALSENSE_WS}/install/local_setup.bash" ]; then
    printf '%s\n' "${REALSENSE_WS}/install/local_setup.bash"
    return
  fi

  local candidates=(
    "${HOME}/realsense/ros2/install/local_setup.bash"
    "${HOME}/realsense/ros2_ws/install/local_setup.bash"
    "${HOME}/asv_sensorsuite/ros2_ws/install/local_setup.bash"
  )

  local candidate
  for candidate in "${candidates[@]}"; do
    if [ -f "${candidate}" ]; then
      printf '%s\n' "${candidate}"
      return
    fi
  done
}

resolve_lidar_setup() {
  if [ -n "${LIDAR_WS:-}" ]; then
    if [ -f "${LIDAR_WS}/install/setup.bash" ]; then
      printf '%s\n' "${LIDAR_WS}/install/setup.bash"
      return
    fi
    if [ -f "${LIDAR_WS}/install/local_setup.bash" ]; then
      printf '%s\n' "${LIDAR_WS}/install/local_setup.bash"
      return
    fi
  fi

  local candidates=(
    "${HOME}/lidar/install/setup.bash"
    "${HOME}/lidar/install/local_setup.bash"
    "${HOME}/lidar_ws/install/setup.bash"
    "${HOME}/lidar_ws/install/local_setup.bash"
    "${HOME}/asv_sensorsuite/lidar_ws/install/setup.bash"
    "${HOME}/asv_sensorsuite/lidar_ws/install/local_setup.bash"
  )

  local candidate
  for candidate in "${candidates[@]}"; do
    if [ -f "${candidate}" ]; then
      printf '%s\n' "${candidate}"
      return
    fi
  done
}

print_section() {
  printf '\n%s\n' "$1"
}

print_section "Blueboat Jetson Preflight"
printf 'Host role: ROS 2 host sensor launchers, Docker engine, device/network setup.\n'
printf 'Container role: autonomy, robot_state_publisher, localization, perception, GPU runtime.\n'

print_section "Host Basics"
if [ "$(uname -m)" = "aarch64" ]; then
  pass "Host architecture is aarch64"
else
  fail "Host architecture is $(uname -m); this workflow expects a Jetson-class aarch64 host"
fi

check_cmd docker "Docker CLI"
check_file "${COMPOSE_FILE}" "Compose file"
check_file "/opt/ros/humble/setup.bash" "Host ROS 2 Humble setup"
check_cmd python3 "Host Python 3"

if docker compose version >/dev/null 2>&1; then
  pass "Docker Compose plugin is available"
else
  fail "Docker Compose plugin is not available"
fi

if docker compose -f "${COMPOSE_FILE}" config >/dev/null 2>&1; then
  pass "Compose file parses successfully"
else
  fail "Compose file failed 'docker compose config'"
fi

if command -v docker >/dev/null 2>&1; then
  if docker info >/dev/null 2>&1; then
    pass "Docker daemon is reachable"
  else
    fail "Docker daemon is not reachable for the current user"
  fi
fi

if command -v dpkg-query >/dev/null 2>&1; then
  if l4t_version="$(dpkg-query --showformat='${Version}' --show nvidia-l4t-core 2>/dev/null)"; then
    pass "Jetson L4T package is installed: nvidia-l4t-core ${l4t_version}"
  else
    fail "nvidia-l4t-core is not installed; JetPack/L4T does not look complete on this host"
  fi
else
  warn "dpkg-query is not available; skipping JetPack/L4T package verification"
fi

if command -v docker >/dev/null 2>&1; then
  if docker info --format '{{json .Runtimes}}' 2>/dev/null | grep -q '"nvidia"'; then
    pass "Docker NVIDIA runtime is registered"
  else
    fail "Docker does not report an 'nvidia' runtime"
  fi
fi

print_section "Repo-Owned Config"
check_file "${REPO_ROOT}/docker/ros.env" "ROS environment file"
check_file "${REPO_ROOT}/config/vectornav/blueboat_vn100.yaml" "VectorNav config"
check_file "${REPO_ROOT}/config/realsense/blueboat_d455.yaml" "RealSense config"
check_file "${REPO_ROOT}/config/lidar/blueboat_config.yaml" "LiDAR config"
check_file "${REPO_ROOT}/urdf/blueboat_real.urdf.xacro" "Robot Xacro"

print_section "Host Sensor Workspaces"
if [ "${START_VECTORNAV}" = "true" ]; then
  VECTORNAV_SETUP="${VECTORNAV_SETUP:-${VECTORNAV_WS:-${HOME}/vectornav}/install/setup.bash}"
  check_file "${VECTORNAV_SETUP}" "VectorNav workspace"
else
  warn "VectorNav workspace check skipped because START_VECTORNAV=false"
fi

if [ "${START_REALSENSE}" = "true" ]; then
  REALSENSE_SETUP="$(resolve_realsense_setup || true)"
  if [ -n "${REALSENSE_SETUP}" ]; then
    pass "RealSense workspace: ${REALSENSE_SETUP}"
  else
    fail "RealSense workspace not found. Set REALSENSE_WS or build the wrapper on the host."
  fi
else
  warn "RealSense workspace check skipped because START_REALSENSE=false"
fi

if [ "${START_LIDAR}" = "true" ]; then
  LIDAR_SETUP="$(resolve_lidar_setup || true)"
  if [ -n "${LIDAR_SETUP}" ]; then
    pass "LiDAR workspace: ${LIDAR_SETUP}"
  else
    fail "LiDAR workspace not found. Set LIDAR_WS or build the driver on the host."
  fi
else
  warn "LiDAR workspace check skipped because START_LIDAR=false"
fi

print_section "Host Devices / Networking"
if [ "${START_VECTORNAV}" = "true" ]; then
  if ls /dev/ttyUSB* >/dev/null 2>&1; then
    pass "At least one /dev/ttyUSB* device is present"
  else
    warn "No /dev/ttyUSB* devices found. VectorNav may not be connected yet."
  fi
fi

if command -v lsusb >/dev/null 2>&1; then
  if lsusb | grep -qi 'RealSense'; then
    pass "RealSense USB device is visible on the host"
  else
    warn "No RealSense USB device is visible in lsusb right now"
  fi
else
  warn "lsusb is not installed; skipping USB visibility checks"
fi

if command -v nmcli >/dev/null 2>&1; then
  pass "NetworkManager CLI is available"
else
  warn "nmcli is not installed; LiDAR NIC configuration will need manual verification"
fi

print_section "Container / Persistence"
if docker ps -a --format '{{.Names}}' | grep -qx "${CONTAINER_NAME}"; then
  pass "Container entry exists: ${CONTAINER_NAME}"

  mount_destinations="$(docker inspect -f '{{range .Mounts}}{{println .Destination}}{{end}}' "${CONTAINER_NAME}" 2>/dev/null || true)"
  for mount_path in \
    "/opt/asv/.venvs" \
    "/opt/asv/src/ASV_perception/EndToEnd/Segmentation/checkpoints" \
    "/opt/asv/src/ASV_perception/EndToEnd/Segmentation/gdino_checkpoints" \
    "/root/.cache/huggingface"
  do
    if printf '%s\n' "${mount_destinations}" | grep -qx "${mount_path}"; then
      pass "Container mount present: ${mount_path}"
    else
      warn "Container ${CONTAINER_NAME} does not currently mount ${mount_path}. Recreate it with ./scripts/host/prepare_jetson_container.sh to adopt the clean persisted layout."
    fi
  done

  if docker ps --format '{{.Names}}' | grep -qx "${CONTAINER_NAME}"; then
    if docker exec \
      -e PERCEPTION_VENV_DIR="/opt/asv/.venvs/ros2_grounded_sam2" \
      "${CONTAINER_NAME}" \
      bash -lc '/opt/asv/scripts/check_perception_runtime.sh --quiet' >/dev/null 2>&1; then
      pass "Perception runtime validates inside the running container"
    else
      warn "Container ${CONTAINER_NAME} is running, but the persisted perception runtime is incomplete or invalid. Run ./scripts/host/prepare_jetson_container.sh or set PERCEPTION_AUTO_SETUP=true when launching autonomy to repair it in-place."
    fi
  else
    warn "Container ${CONTAINER_NAME} exists but is not running; skipping in-container perception runtime validation."
  fi
else
  warn "Container ${CONTAINER_NAME} does not exist yet. Build/start it before autonomy tests."
  warn "The named persistence volumes will be created automatically by ./scripts/host/prepare_jetson_container.sh."
fi

print_section "Summary"
printf 'Failures: %d\n' "${failures}"
printf 'Warnings: %d\n' "${warnings}"

if [ "${failures}" -ne 0 ]; then
  exit 1
fi
