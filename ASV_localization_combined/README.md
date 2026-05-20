# ASV Localization Combined

This folder is intended to be used through the ROS2 workspace at `ROS2/`.
For VRX BlueBoat testing, use:

```
cd <PATH>/<TO>/ASV_localization_combined
./build_ros.sh
./run_localization.sh vrx
```

Do not run `colcon build` from the practice umbrella folder. If you want to run
manually, build from `ASV_localization_combined/ROS2` and source
`ASV_localization_combined/ROS2/install/setup.bash`.

# DRIFT: Dead Reckoning In Field Time
![all_robots](figures/drift_all_robots.gif?raw=true "Title")

## Description
Dead Reckoning In Field Time (DRIFT) is an open-source C++ software library designed to provide accurate and high-frequency proprioceptive state estimation for a variety of mobile robot architectures. By default, DRIFT supports legged robots, differential-drive wheeled robots, full-size vehicles with shaft encoders and marine robots with a Doppler Velocity Log (DVL). Leveraging symmetry-preserving filters such as [Invariant Kalman Filtering (InEKF)](https://www.annualreviews.org/doi/10.1146/annurev-control-060117-105010), this modular library empowers roboticists and engineers with a robust and adaptable tool to estimate instantaneous local pose and velocity in diverse environments. The software is structured in a modular fashion, allowing users to define their own sensor types, and propagation and correction methods, offering a high degree of customization.

Detailed documentations and tutorials can be found at [https://umich-curly.github.io/DRIFT_Website/](https://umich-curly.github.io/DRIFT_Website/).

## Framework
![flow_chart](figures/flow_chart.jpg?raw=true "flow chart")

## Run Time Analysis
We perform runtime evaluations using a personal laptop with an Intel i5-11400H CPU and an NVIDIA Jetson AGX Xavier (CPU). DRIFT can operate at an extremely high frequency using CPU-only computation, even on the resourced-constrained Jetson AGX Xavier. For the optional contact estimator, the inference speed on an NVIDIA RTX 3090 GPU is approximately 1100 Hz, and the inference speed on a Jetson AGX Xavier (GPU) is around 830 Hz after TensorRT optimization.

![run_time](figures/run_time.png?raw=true "run time")

# Dependencies
We have tested the library in **Ubuntu 20.04** and **22.04**, but it should be easy to compile in other platforms.

> ### C++17 Compiler
We use the threading functionalities of C++17.


> ### Eigen3
Required by header files. Download and install instructions can be found at: http://eigen.tuxfamily.org. **Requires at least 3.1.0**.

> ### Yaml-cpp
Required by header files. Download and install instructions can be found at: https://github.com/jbeder/yaml-cpp.

> ### ROS2 (Optional)
Building with ROS2 is optional. Instructions are [found below](https://github.com/UMich-CURLY/drift/tree/main#4-ros).

# Building DRIFT library

Clone the repository:
```
git clone -b ros2 https://github.com/spsingh37/drift.git
cd drift
```
Create another directory which we will name 'build' and use cmake and make to compile an build project:

```
mkdir build
cd build
cmake ..
make -j4
```

## Install the library
After building the library, you can install the library to the system. This will allow other projects to find the library without needing to specify the path to the library. 

```
sudo make install
```
Then, you can include the library in your project by adding the following line to your CMakeLists.txt file (this is already done in this repo so ignore):
```
find_package(drift REQUIRED)
```

# ROS2
This combined fork keeps the ROS2 surface-vehicle path focused on the BlueBoat
GPS+IMU InEKF with GPS course-over-ground heading correction. It starts from the
cleaner BlueBoat-only structure and carries over the current stack changes needed
by the practice autonomy setup:

- `DRIFT_ROS_COMM_CONFIG` and the `ros_comm_config` ROS parameter select the ROS
  communication profile.
- `config/blueboat_vrx`, `config/blueboat_real`, and `config/blueboat_isaac`
  hold the estimator YAMLs.
- The canonical outputs are `/localization/pose`, `/localization/twist`, and
  `/localization/path`.
- Compatibility aliases keep the current stack working during migration:
  `/gt_pose`, `/drift/pose`, and `/wamv/inekf_odom_correction/twist`.

## Building the ROS2 node
```
cd <PATH>/<TO>/ASV_localization_combined
./build_ros.sh
source ROS2/install/setup.bash
```

## Run
VRX is the default profile if no config is provided:
```
ros2 run drift_ros2 wamv_gpsimu_ros2
```

Explicit VRX profile:
```
DRIFT_ROS_COMM_CONFIG=<PATH>/<TO>/ASV_localization_combined/ROS2/drift_ros2/config/blueboat_vrx/ros_comm.yaml \
ros2 run drift_ros2 wamv_gpsimu_ros2
```

ROS parameter equivalent:
```
ros2 run drift_ros2 wamv_gpsimu_ros2 --ros-args \
  -p ros_comm_config:=<PATH>/<TO>/ASV_localization_combined/ROS2/drift_ros2/config/blueboat_vrx/ros_comm.yaml
```

Isaac Sim profile:
```
DRIFT_ROS_COMM_CONFIG=<PATH>/<TO>/ASV_localization_combined/ROS2/drift_ros2/config/blueboat_isaac/ros_comm.yaml \
ros2 run drift_ros2 wamv_gpsimu_ros2
```

For the physical boat, use
`ROS2/drift_ros2/config/blueboat_real/ros_comm.yaml` and set
`reference_position: [lat, lon, alt]` there when you want a fixed ENU origin.

## Run the repo with your own robots:
Please refer to the tutorial here: https://umich-curly.github.io/DRIFT_Website/tutorials/.

# Contact Estimation
The contact estimation and the contact data set can be found in https://github.com/UMich-CURLY/deep-contact-estimator.

# Citations
If you find this work useful, please kindly cite the following papers

* Tzu-Yuan Lin, Tingjun Li, Wenzhe Tong, and Maani Ghaffari. "Proprioceptive Invariant Robot State Estimation." arXiv preprint arXiv:2311.04320 (2023). (Under review for Transaction on Robotics)
```
@article{lin2023proprioceptive,
  title={Proprioceptive Invariant Robot State Estimation},
  author={Lin, Tzu-Yuan and Li, Tingjun and Tong, Wenzhe and Ghaffari, Maani},
  journal={arXiv preprint arXiv:2311.04320},
  year={2023}
}
```
* Tzu-Yuan Lin, Ray Zhang, Justin Yu, and Maani Ghaffari. "Legged Robot State Estimation using Invariant Kalman Filtering and Learned Contact Events." In Conference on robot learning. PMLR, 2021
```
@inproceedings{
   lin2021legged,
   title={Legged Robot State Estimation using Invariant Kalman Filtering and Learned Contact Events},
   author={Tzu-Yuan Lin and Ray Zhang and Justin Yu and Maani Ghaffari},
   booktitle={5th Annual Conference on Robot Learning },
   year={2021},
   url={https://openreview.net/forum?id=yt3tDB67lc5}
}
```

# License
DRIFT is released under a [BSD 3-Clause License](https://github.com/UMich-CURLY/drift/blob/main/LICENSE). 
