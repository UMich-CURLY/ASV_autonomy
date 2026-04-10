#!/bin/bash

# Copyright (c) Meta Platforms, Inc. and affiliates.
# All rights reserved.

# This source code is licensed under the license found in the
# LICENSE file in the root directory of this source tree.

# Use either wget or curl to download the checkpoints
if command -v wget &> /dev/null; then
    CMD="wget"
elif command -v curl &> /dev/null; then
    CMD="curl -L -O"
else
    echo "Please install wget or curl to download the checkpoints."
    exit 1
fi

# Define the URLs for SAM 2 checkpoints
# SAM2_BASE_URL="https://dl.fbaipublicfiles.com/segment_anything_2/072824"
# sam2_hiera_t_url="${SAM2_BASE_URL}/sam2_hiera_tiny.pt"
# sam2_hiera_s_url="${SAM2_BASE_URL}/sam2_hiera_small.pt"
# sam2_hiera_b_plus_url="${SAM2_BASE_URL}/sam2_hiera_base_plus.pt"
# sam2_hiera_l_url="${SAM2_BASE_URL}/sam2_hiera_large.pt"

# Download each of the four checkpoints using wget
# echo "Downloading sam2_hiera_tiny.pt checkpoint..."
# $CMD $sam2_hiera_t_url || { echo "Failed to download checkpoint from $sam2_hiera_t_url"; exit 1; }

# echo "Downloading sam2_hiera_small.pt checkpoint..."
# $CMD $sam2_hiera_s_url || { echo "Failed to download checkpoint from $sam2_hiera_s_url"; exit 1; }

# echo "Downloading sam2_hiera_base_plus.pt checkpoint..."
# $CMD $sam2_hiera_b_plus_url || { echo "Failed to download checkpoint from $sam2_hiera_b_plus_url"; exit 1; }

# echo "Downloading sam2_hiera_large.pt checkpoint..."
# $CMD $sam2_hiera_l_url || { echo "Failed to download checkpoint from $sam2_hiera_l_url"; exit 1; }

# Define the URLs for SAM 2.1 checkpoints
SAM2p1_BASE_URL="https://dl.fbaipublicfiles.com/segment_anything_2/092824"
declare -A SAM2P1_URLS=(
    ["tiny"]="${SAM2p1_BASE_URL}/sam2.1_hiera_tiny.pt"
    ["small"]="${SAM2p1_BASE_URL}/sam2.1_hiera_small.pt"
    ["base_plus"]="${SAM2p1_BASE_URL}/sam2.1_hiera_base_plus.pt"
    ["large"]="${SAM2p1_BASE_URL}/sam2.1_hiera_large.pt"
)
declare -A SAM2P1_FILENAMES=(
    ["tiny"]="sam2.1_hiera_tiny.pt"
    ["small"]="sam2.1_hiera_small.pt"
    ["base_plus"]="sam2.1_hiera_base_plus.pt"
    ["large"]="sam2.1_hiera_large.pt"
)
SAM2_DOWNLOAD_VARIANTS="${SAM2_DOWNLOAD_VARIANTS:-small,tiny}"

download_if_missing() {
    local url="$1"
    local filename="$2"

    if [ -f "${filename}" ]; then
        echo "Checkpoint ${filename} already present; skipping."
        return 0
    fi

    echo "Downloading ${filename} checkpoint..."
    if [ "${CMD}" = "wget" ]; then
        wget -O "${filename}" "${url}" || { echo "Failed to download checkpoint from ${url}"; exit 1; }
    else
        curl -L -o "${filename}" "${url}" || { echo "Failed to download checkpoint from ${url}"; exit 1; }
    fi
}

# The active Blueboat Jetson path defaults to `small`, while `tiny` is also
# useful for field performance experiments.
IFS=',' read -ra requested_variants <<< "${SAM2_DOWNLOAD_VARIANTS}"
for raw_variant in "${requested_variants[@]}"; do
    variant="$(echo "${raw_variant}" | tr '[:upper:]' '[:lower:]' | xargs)"
    if [ -z "${variant}" ]; then
        continue
    fi

    if [ -z "${SAM2P1_URLS[${variant}]+x}" ]; then
        echo "Unsupported SAM2_DOWNLOAD_VARIANTS entry '${variant}'." >&2
        echo "Choose from: tiny, small, base_plus, large." >&2
        exit 1
    fi

    download_if_missing "${SAM2P1_URLS[${variant}]}" "${SAM2P1_FILENAMES[${variant}]}"
done

echo "Required SAM2 checkpoints are downloaded successfully."
