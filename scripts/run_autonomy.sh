#!/bin/bash
set -e

source /opt/ros/humble/setup.bash
source /opt/asv/src/ASV_localization/ROS2/drift_ros2/install/setup.bash
source /opt/conda/etc/profile.d/conda.sh

ARCH="$(uname -m)"
ENABLE_LOCALIZATION="${ENABLE_LOCALIZATION:-true}"
ENABLE_PERCEPTION="${ENABLE_PERCEPTION:-true}"
ENABLE_FAKE_POSE="${ENABLE_FAKE_POSE:-false}"
FAKE_POSE_MODE="${FAKE_POSE_MODE:-stationary}"
FAKE_POSE_RATE_HZ="${FAKE_POSE_RATE_HZ:-20.0}"
PERCEPTION_VENV_DIR="${PERCEPTION_VENV_DIR:-/opt/asv/.venvs/ros2_grounded_sam2}"
PERCEPTION_TRANSFORMERS_OFFLINE="${PERCEPTION_TRANSFORMERS_OFFLINE:-auto}"
PERCEPTION_HF_HUB_OFFLINE="${PERCEPTION_HF_HUB_OFFLINE:-auto}"
ASV_PERCEPTION_CONFIG="${ASV_PERCEPTION_CONFIG:-}"
PIDS=()

cleanup() {
  for pid in "${PIDS[@]}"; do
    kill "${pid}" >/dev/null 2>&1 || true
  done
}

trap cleanup EXIT INT TERM

export OPENBLAS_NUM_THREADS=1
export OMP_NUM_THREADS=1
export GOTO_NUM_THREADS=1
export MKL_NUM_THREADS=1

if [ "${PERCEPTION_TRANSFORMERS_OFFLINE}" = "auto" ]; then
  if [ "${ARCH}" = "aarch64" ]; then
    PERCEPTION_TRANSFORMERS_OFFLINE=1
  else
    PERCEPTION_TRANSFORMERS_OFFLINE=0
  fi
fi

if [ "${PERCEPTION_HF_HUB_OFFLINE}" = "auto" ]; then
  if [ "${ARCH}" = "aarch64" ]; then
    PERCEPTION_HF_HUB_OFFLINE=1
  else
    PERCEPTION_HF_HUB_OFFLINE=0
  fi
fi


# Publish the fixed sensor tree from the real-boat Xacro.
/opt/asv/scripts/start_robot_state_publisher.sh &
PIDS+=("$!")

# Bootstrap the target TF shape. For now map and odom are identical.
ros2 run tf2_ros static_transform_publisher \
      --x 0 --y 0 --z 0 \
      --roll 0 --pitch 0 --yaw 0 \
      --frame-id map \
      --child-frame-id odom &
PIDS+=("$!")

# Bridge the current localization pose topic into odom -> base_link.
python3 /opt/asv/scripts/publish_pose_tf.py \
        --ros-args \
        -p pose_topic:=/gt_pose \
        -p parent_frame:=odom \
        -p child_frame:=base_link &
PIDS+=("$!")

# Give TF publishers a moment to come up before downstream nodes subscribe.
sleep 5

if [ "${ENABLE_FAKE_POSE}" = "true" ] && [ "${ENABLE_LOCALIZATION}" = "true" ]; then
  echo "ENABLE_FAKE_POSE=true requested; skipping localization and using synthetic /gt_pose instead." >&2
  ENABLE_LOCALIZATION=false
fi

if [ "${ENABLE_FAKE_POSE}" = "true" ]; then
  python3 /opt/asv/scripts/publish_fake_pose.py \
          --ros-args \
          -p pose_topic:=/gt_pose \
          -p frame_id:=odom \
          -p mode:="${FAKE_POSE_MODE}" \
          -p rate_hz:="${FAKE_POSE_RATE_HZ}" &
  PIDS+=("$!")
fi

if [ "${ENABLE_LOCALIZATION}" = "true" ]; then
  # Start localization.
  ros2 run drift_ros2 wamv_gpsimu_ros2 &
  PIDS+=("$!")
else
  echo "Localization disabled; publishing only the static robot tree and map -> odom." >&2
fi

if [ "${ENABLE_PERCEPTION}" = "true" ]; then
  if [ -x "${PERCEPTION_VENV_DIR}/bin/python" ]; then
    if bash -lc "
      export PERCEPTION_VENV_DIR='${PERCEPTION_VENV_DIR}'
      export ASV_PERCEPTION_CONFIG='${ASV_PERCEPTION_CONFIG}'
      exec /opt/asv/scripts/check_perception_runtime.sh --quiet
    "; then
      bash -lc "
        source /opt/ros/humble/setup.bash
        export VIRTUAL_ENV='${PERCEPTION_VENV_DIR}'
        export PATH=\"${PERCEPTION_VENV_DIR}/bin:\$PATH\"
        export LD_LIBRARY_PATH=\"${PERCEPTION_VENV_DIR}/lib/python3.10/site-packages/torch/lib:/usr/local/cuda/lib64:\${LD_LIBRARY_PATH:-}\"
        export TRANSFORMERS_OFFLINE='${PERCEPTION_TRANSFORMERS_OFFLINE}'
        export HF_HUB_OFFLINE='${PERCEPTION_HF_HUB_OFFLINE}'
        export ASV_PERCEPTION_CONFIG='${ASV_PERCEPTION_CONFIG}'
        export PYTHONUNBUFFERED=1
        exec python /opt/asv/src/ASV_perception/EndToEnd/ros2_node_pt_cloud.py
      " &
      PIDS+=("$!")
    else
      echo "Skipping perception; the runtime at ${PERCEPTION_VENV_DIR} is incomplete or invalid. Run /opt/asv/scripts/setup_perception.sh or ./scripts/host/prepare_jetson_container.sh to repair it." >&2
    fi
  elif [ "${ARCH}" = "aarch64" ]; then
    echo "Skipping perception; Jetson runs require the persisted venv at ${PERCEPTION_VENV_DIR}. Run /opt/asv/scripts/setup_perception.sh to create it." >&2
  elif conda env list | awk '{print $1}' | grep -qx "ros2_grounded_sam2"; then
    # Start ConvBKI / semantic mapping
    bash -lc '
      source /opt/conda/etc/profile.d/conda.sh
      conda activate ros2_grounded_sam2
      export LD_LIBRARY_PATH="${CONDA_PREFIX}/lib:${LD_LIBRARY_PATH:-}"
      export TRANSFORMERS_OFFLINE="'"${PERCEPTION_TRANSFORMERS_OFFLINE}"'"
      export HF_HUB_OFFLINE="'"${PERCEPTION_HF_HUB_OFFLINE}"'"
      export PYTHONUNBUFFERED=1
      exec python /opt/asv/src/ASV_perception/EndToEnd/ros2_node_pt_cloud.py
    ' &
    PIDS+=("$!")
  else
    echo "Skipping perception; no Jetson perception venv or conda env was found." >&2
  fi
else
  echo "Perception disabled." >&2
fi

wait
