#include <rclcpp/rclcpp.hpp>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <thread>
#include <mutex>

#include "communication/ros2_publisher.h"
#include "communication/ros2_subscriber.h"
#include "drift/estimator/inekf_estimator.h"

using namespace std;
using namespace state;
using namespace estimator;

namespace {

constexpr double kDegToRad = 3.14159265358979323846 / 180.0;

std::string ResolveProjectPath(const std::string& project_dir, const std::string& path) {
    const std::filesystem::path candidate(path);
    if (candidate.is_absolute()) {
        return candidate.lexically_normal().string();
    }
    return (std::filesystem::path(project_dir) / candidate).lexically_normal().string();
}

std::string ResolveEnvPathOrDefault(const char* env_name, const std::string& default_path) {
    const char* env_value = std::getenv(env_name);
    if (env_value == nullptr || std::string(env_value).empty()) {
        return default_path;
    }
    return std::filesystem::path(env_value).lexically_normal().string();
}

std::string ResolveConfigPath(const YAML::Node& config,
                              const std::string& project_dir,
                              const std::string& key,
                              const std::string& default_path) {
    if (config["estimator_configs"] && config["estimator_configs"][key]) {
        return ResolveProjectPath(project_dir, config["estimator_configs"][key].as<std::string>());
    }
    return ResolveProjectPath(project_dir, default_path);
}

std::string LegacyFilterConfigDir(const YAML::Node& config, const std::string& project_dir) {
    if (config["filter"] && config["filter"]["config_dir"]) {
        return ResolveProjectPath(project_dir, config["filter"]["config_dir"].as<std::string>());
    }
    return ResolveProjectPath(project_dir, "config/blueboat_vrx");
}

}  // namespace

int main(int argc, char** argv) {
    // Initialize ROS2
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("wamv_gpsimu_ros2");

    std::cout << "The subscriber is on!" << std::endl;

    // Create executor
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);

    // Load configuration

    std::string file{__FILE__};                                                                                 
    std::string project_dir{file.substr(0, file.rfind("ROS2/drift_ros2/examples/"))};
    std::cout << "Project directory: " << project_dir << std::endl;

    const std::string default_ros_config_file =
        ResolveProjectPath(project_dir, "ROS2/drift_ros2/config/blueboat_vrx/ros_comm.yaml");
    std::string ros_config_file = ResolveEnvPathOrDefault("DRIFT_ROS_COMM_CONFIG", default_ros_config_file);
    node->declare_parameter<std::string>("ros_comm_config", "");
    const std::string param_config = node->get_parameter("ros_comm_config").as_string();
    if (!param_config.empty()) {
        ros_config_file = std::filesystem::path(param_config).lexically_normal().string();
    }
    if (!std::filesystem::exists(ros_config_file)) {
        RCLCPP_FATAL(node->get_logger(), "ROS communication config does not exist: %s", ros_config_file.c_str());
        rclcpp::shutdown();
        return 1;
    }
    RCLCPP_INFO(node->get_logger(), "Loading ROS communication config: %s", ros_config_file.c_str());
    YAML::Node config = YAML::LoadFile(ros_config_file);
    const std::string legacy_filter_config_dir = LegacyFilterConfigDir(config, project_dir);

    std::string imu_topic = config["subscribers"]["imu_topic"].as<std::string>();                                       //imu + gps topics
    std::string gps_topic = config["subscribers"]["gps_topic"].as<std::string>();
    auto translation_gpssrc2body = config["subscribers"]["translation_gps_source_to_body"].as<std::vector<double>>();   //translation from gps to body
    std::vector<double> reference_position_cfg;
    if (config["subscribers"]["reference_position"]) {
        reference_position_cfg = config["subscribers"]["reference_position"].as<std::vector<double>>();
    }

    // Use fixed rotation from config instead of dynamic IMU-based rotation
    std::vector<double> rotation_gpssrc2body;
    if (config["subscribers"]["rotation_gps_source_to_body"]) {                                                         //pulls rotation quaternion from config file if the file exists
        rotation_gpssrc2body = config["subscribers"]["rotation_gps_source_to_body"].as<std::vector<double>>();
        RCLCPP_INFO(node->get_logger(), "Using rotation_gps_source_to_body from config: [%f, %f, %f, %f]", 
            rotation_gpssrc2body[0], rotation_gpssrc2body[1], rotation_gpssrc2body[2], rotation_gpssrc2body[3]);
    } else {
        // Fallback: use the GPS config rotation values [0.032, 0.0, 0.0, -0.999]                                       //otherwise use hardcoded values
        rotation_gpssrc2body = {0.032, 0.0, 0.0, -0.999};   // fix this
        RCLCPP_INFO(node->get_logger(), "Using hardcoded GPS rotation: [%f, %f, %f, %f]", 
            rotation_gpssrc2body[0], rotation_gpssrc2body[1], rotation_gpssrc2body[2], rotation_gpssrc2body[3]);
    }
    // Create ROS2 subscriber
    auto ros_sub = std::make_shared<ros_wrapper::ROSSubscriber>(node);
    if (reference_position_cfg.size() == 3) {
        ros_sub->SetReferencePosition(
            reference_position_cfg[0],
            reference_position_cfg[1],
            reference_position_cfg[2]);
    } else if (!reference_position_cfg.empty()) {
        RCLCPP_WARN(node->get_logger(),
                    "Ignoring reference_position because it does not have exactly 3 values.");
    } else {
        RCLCPP_INFO(node->get_logger(),
                    "No reference_position in config; using first GPS message as ENU origin.");
    }

    // Optional tuning for GPS COG based yaw correction (for paper claim alignment).
    const double cog_min_displacement_m =
        config["heading_correction"] && config["heading_correction"]["cog_min_displacement_m"]
            ? config["heading_correction"]["cog_min_displacement_m"].as<double>()
            : 0.15;
    const double cog_min_speed_mps =
        config["heading_correction"] && config["heading_correction"]["cog_min_speed_mps"]
            ? config["heading_correction"]["cog_min_speed_mps"].as<double>()
            : 0.20;
    const double yaw_bias_filter_gain =
        config["heading_correction"] && config["heading_correction"]["yaw_bias_filter_gain"]
            ? config["heading_correction"]["yaw_bias_filter_gain"].as<double>()
            : 0.20;
    ros_sub->SetGPSIMUHeadingCorrectionParams(
        cog_min_displacement_m, cog_min_speed_mps, yaw_bias_filter_gain);
    if (config["heading_correction"] && config["heading_correction"]["initial_heading_offset_deg"]) {
        ros_sub->SetInitialHeadingOffset(
            config["heading_correction"]["initial_heading_offset_deg"].as<double>() * kDegToRad);
    }

    // Create IMU subscriber for propagation (no longer needed for rotation initialization)
    auto qimu_and_mutex = ros_sub->AddIMUSubscriber(imu_topic);
    auto qimu = qimu_and_mutex.first;
    auto qimu_mutex = qimu_and_mutex.second;

    // Add subscriber that fuses GPS + IMU to pose measurements
    auto qpose_and_mutex = ros_sub->AddGPSIMU2PoseSubscriber(
        gps_topic, imu_topic, translation_gpssrc2body, rotation_gpssrc2body);
    auto qpose = qpose_and_mutex.first;
    auto qpose_mutex = qpose_and_mutex.second;

    // Create state estimator
    inekf::ErrorType error_type = RightInvariant;
    const std::string inekf_estimator_config =
        ResolveConfigPath(config, project_dir, "inekf_estimator",
                          legacy_filter_config_dir + "/inekf_estimator.yaml");
    const std::string imu_propagation_config =
        ResolveConfigPath(config, project_dir, "imu_propagation",
                          legacy_filter_config_dir + "/imu_propagation.yaml");
    const std::string pose_correction_config =
        ResolveConfigPath(config, project_dir, "pose_correction",
                          legacy_filter_config_dir + "/pose_correction.yaml");

    RCLCPP_INFO(node->get_logger(), "Loading INEKF config: %s", inekf_estimator_config.c_str());
    RCLCPP_INFO(node->get_logger(), "Loading IMU propagation config: %s", imu_propagation_config.c_str());
    RCLCPP_INFO(node->get_logger(), "Loading pose correction config: %s", pose_correction_config.c_str());

    InekfEstimator inekf_estimator(error_type, inekf_estimator_config);

    // Add IMU propagation and pose correction
    inekf_estimator.add_imu_propagation(qimu, qimu_mutex, imu_propagation_config);
    inekf_estimator.add_pose_correction(qpose, qpose_mutex, pose_correction_config);

    auto robot_state_queue_ptr = inekf_estimator.get_robot_state_queue_ptr();
    auto robot_state_queue_mutex_ptr = inekf_estimator.get_robot_state_queue_mutex_ptr();

    // Create ROS2 publisher
    auto ros_pub = std::make_shared<ros_wrapper::ROSPublisher>(
        node, robot_state_queue_ptr, robot_state_queue_mutex_ptr, ros_config_file);

    // Start publishing thread
    ros_pub->StartPublishingThread();

    // Start estimator thread
    std::thread estimator_thread([&]() {
        rclcpp::Rate rate(5000); // 5000 Hz
        while (rclcpp::ok()) {
            if (inekf_estimator.is_enabled()) {
                inekf_estimator.RunOnce();
            } else {
                if (inekf_estimator.BiasInitialized()) {
                    inekf_estimator.InitState();
                } else {
                    inekf_estimator.InitBias();
                }
            }
            rate.sleep();
        }
    });

    executor.spin();

    // Cleanup
    if (estimator_thread.joinable()) {
        estimator_thread.join();
    }

    rclcpp::shutdown();
    return 0;
}
