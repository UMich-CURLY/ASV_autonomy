#!/bin/bash

# Copyright (c) Meta Platforms, Inc. and affiliates.
# All rights reserved.

# This source code is licensed under the license found in the
# LICENSE file in the root directory of this source tree.


# Define the URLs for the checkpoints
BASE_URL="https://github.com/IDEA-Research/GroundingDINO/releases/download/"
swint_ogc_url="${BASE_URL}v0.1.0-alpha/groundingdino_swint_ogc.pth"
swinb_cogcoor_url="${BASE_URL}v0.1.0-alpha2/groundingdino_swinb_cogcoor.pth"



download_if_missing() {
    local url="$1"
    local filename="$2"

    if [ -f "${filename}" ]; then
        echo "Checkpoint ${filename} already present; skipping."
        return 0
    fi

    echo "Downloading ${filename} checkpoint..."
    wget -O "${filename}" "${url}" || { echo "Failed to download checkpoint from ${url}"; exit 1; }
}

# The active Blueboat path uses only the SwinT GroundingDINO checkpoint.
download_if_missing "${swint_ogc_url}" "groundingdino_swint_ogc.pth"

echo "Required GroundingDINO checkpoints are downloaded successfully."
