#!/bin/bash
source ~/miniconda3/etc/profile.d/conda.sh
conda activate asv_autonomy
cd /home/asv/ASV_autonomy/BKI_ROS/EndToEnd
python ros2_node_pt_cloud.py

