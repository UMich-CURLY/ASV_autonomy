#include "communication/ros2_subscriber.h"
// #include <memory>
// #include <iostream>
// #include <Eigen/Dense>
#include <algorithm>
#include <cmath>

namespace ros_wrapper {

namespace {

double WrapAngle(const double angle_rad) {
    return std::atan2(std::sin(angle_rad), std::cos(angle_rad));
}

double BlendAngle(const double old_angle_rad, const double new_angle_rad, const double gain) {
    const double clipped_gain = std::clamp(gain, 0.0, 1.0);
    const double x = (1.0 - clipped_gain) * std::cos(old_angle_rad) + clipped_gain * std::cos(new_angle_rad);
    const double y = (1.0 - clipped_gain) * std::sin(old_angle_rad) + clipped_gain * std::sin(new_angle_rad);
    return std::atan2(y, x);
}

Eigen::Quaterniond YawPitchRollToQuaternion(const double yaw, const double pitch, const double roll) {
    const Eigen::AngleAxisd yaw_rot(yaw, Eigen::Vector3d::UnitZ());
    const Eigen::AngleAxisd pitch_rot(pitch, Eigen::Vector3d::UnitY());
    const Eigen::AngleAxisd roll_rot(roll, Eigen::Vector3d::UnitX());
    Eigen::Quaterniond q(yaw_rot * pitch_rot * roll_rot);
    q.normalize();
    return q;
}

Eigen::Vector3d ConvertGpsAntennaPositionToBodyPosition(
    const Eigen::Vector3d& enu_gps_translation,
    const Eigen::Quaterniond& world_from_body_orientation,
    const Eigen::Matrix4d& gps_src_to_body) {
    Eigen::Quaterniond q_world_from_body = world_from_body_orientation;
    if (q_world_from_body.norm() < 1e-12) {
        q_world_from_body = Eigen::Quaterniond::Identity();
    } else {
        q_world_from_body.normalize();
    }

    // translation_gps_source_to_body currently carries the URDF xyz offset
    // (body -> GPS antenna) in body frame.
    const Eigen::Vector3d t_body_to_gps = gps_src_to_body.block<3, 1>(0, 3);
    return enu_gps_translation - q_world_from_body.toRotationMatrix() * t_body_to_gps;
}

} // namespace

// ROSSubscriber::ROSSubscriber(rclcpp::Node::SharedPtr node)
//     : rclcpp::Node("ros2_subscriber"), node_(node), thread_started_(false) {}
ROSSubscriber::ROSSubscriber(rclcpp::Node::SharedPtr node)
    : node_(node), thread_started_(false) {}

void ROSSubscriber::SetGPSIMUHeadingCorrectionParams(const double min_displacement_m,
                                                     const double min_speed_mps,
                                                     const double yaw_bias_filter_gain) {
    cog_min_displacement_m_ = std::max(0.0, min_displacement_m);
    cog_min_speed_mps_ = std::max(0.0, min_speed_mps);
    yaw_bias_filter_gain_ = std::clamp(yaw_bias_filter_gain, 0.0, 1.0);
    RCLCPP_INFO(node_->get_logger(),
                "GPS-IMU heading correction params: min_displacement=%.3f m, min_speed=%.3f m/s, bias_gain=%.3f",
                cog_min_displacement_m_,
                cog_min_speed_mps_,
                yaw_bias_filter_gain_);
}

void ROSSubscriber::SetInitialHeadingOffset(const double initial_heading_offset_rad) {
    initial_heading_offset_enabled_ = true;
    initial_heading_offset_rad_ = WrapAngle(initial_heading_offset_rad);
    RCLCPP_INFO(node_->get_logger(),
                "Initial heading offset fallback: %.3f rad",
                initial_heading_offset_rad_);
}

void ROSSubscriber::SetReferencePosition(const double lat_deg,
                                         const double lon_deg,
                                         const double alt_m) {
    reference_position << lat_deg, lon_deg, alt_m;
    reference_initialized = true;
    RCLCPP_INFO(
        node_->get_logger(),
        "Reference position forced from config: [%.9f, %.9f, %.3f]",
        reference_position(0),
        reference_position(1),
        reference_position(2));
}

ROSSubscriber::~ROSSubscriber() {
    if (thread_started_) {
        if (subscribing_thread_.joinable()) {
            subscribing_thread_.join();
        }
    }
    subscriber_list_.clear();
    imu_queue_list_.clear();
}

IMUQueuePair ROSSubscriber::AddIMUSubscriber(const std::string& topic_name) {
    RCLCPP_INFO(node_->get_logger(), "Subscribing to IMU topic: %s", topic_name.c_str());

    // Create queue and mutex
    IMUQueuePtr imu_queue_ptr = std::make_shared<std::queue<std::shared_ptr<ImuMeasurement<double>>>>();
    auto mutex = std::make_shared<std::mutex>();
    mutex_list_.push_back(mutex);

    // Create ROS2 subscription
    auto callback = [this, mutex, imu_queue_ptr](const sensor_msgs::msg::Imu::SharedPtr imu_msg) {
        this->IMUCallback(imu_msg, mutex, imu_queue_ptr);
    };

    auto subscriber = node_->create_subscription<sensor_msgs::msg::Imu>(
        topic_name, 
        1000,  
        callback
    );

    subscriber_list_.push_back(subscriber);
    imu_queue_list_.push_back(imu_queue_ptr);

    return {imu_queue_ptr, mutex};
}

PositionQueuePair ROSSubscriber::AddOdom2PositionSubscriber(
    const std::string &topic_name,
    const std::vector<double> &translation_odomsrc2body,
    const std::vector<double> &rotation_odomsrc2body) {
    std::cout << "Subscribing to odometry topic: " << topic_name << std::endl;
    auto position_queue_ptr = std::make_shared<OdomQueue>();
    auto mutex = std::make_shared<std::mutex>();

    Eigen::Quaternion<double> orientation_quat(rotation_odomsrc2body[0], rotation_odomsrc2body[1],
                                               rotation_odomsrc2body[2], rotation_odomsrc2body[3]);
    odom_src_to_body_ = Eigen::Matrix4d::Identity();
    odom_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
    odom_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_odomsrc2body.data());

    auto callback = [this, mutex, position_queue_ptr](const nav_msgs::msg::Odometry::SharedPtr msg) {
        Odom2PositionCallback(msg, mutex, position_queue_ptr);
    };

    subscriber_list_.push_back(node_->create_subscription<nav_msgs::msg::Odometry>(
        topic_name, 1000, callback));

    position_queue_list_.push_back(position_queue_ptr);
    return {position_queue_ptr, mutex};
}

// PositionQueuePair ROSSubscriber::AddGPS2PositionSubscriber(
//     const std::string &topic_name,
//     const std::vector<double> &translation_gpssrc2body,
//     const std::vector<double> &rotation_gpssrc2body,
//     const Eigen::Vector3d &reference_position) {
//     std::cout << "Subscribing to GPS topic: " << topic_name << std::endl;
//     auto position_queue_ptr = std::make_shared<OdomQueue>();
//     auto mutex = std::make_shared<std::mutex>();

//     Eigen::Quaternion<double> orientation_quat(rotation_gpssrc2body[0], rotation_gpssrc2body[1],
//                                                rotation_gpssrc2body[2], rotation_gpssrc2body[3]);
//     gps_src_to_body_ = Eigen::Matrix4d::Identity();
//     gps_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
//     gps_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_gpssrc2body.data());

//     auto callback = [this, mutex, position_queue_ptr, reference_position](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
//         GPS2PositionCallback(msg, mutex, position_queue_ptr, reference_position);
//     };

//     subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
//         topic_name, 1000, callback));

//     position_queue_list_.push_back(position_queue_ptr);
//     return {position_queue_ptr, mutex};
// }

// PositionQueuePair ROSSubscriber::AddGPS2PositionSubscriber(
//     const std::string &topic_name,
//     const std::vector<double> &translation_gpssrc2body,
//     const std::vector<double> &rotation_gpssrc2body) 
// {
//     std::cout << "Subscribing to GPS topic: " << topic_name << std::endl;
    
//     auto position_queue_ptr = std::make_shared<OdomQueue>();
//     auto mutex = std::make_shared<std::mutex>();

//     Eigen::Quaternion<double> orientation_quat(
//         rotation_gpssrc2body[0], rotation_gpssrc2body[1],
//         rotation_gpssrc2body[2], rotation_gpssrc2body[3]);

//     gps_src_to_body_ = Eigen::Matrix4d::Identity();
//     gps_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
//     gps_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_gpssrc2body.data());

//     // Lambda callback without passing reference_position_ptr anymore
//     auto callback = [this, mutex, position_queue_ptr](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
//         std::lock_guard<std::mutex> lock(*mutex);

//         if (!reference_initialized) {
//             reference_position << msg->latitude, msg->longitude, msg->altitude;
//             reference_initialized = true;
//             RCLCPP_INFO(node_->get_logger(), "GPS reference position initialized: [%f, %f, %f]", 
//                         reference_position(0), reference_position(1), reference_position(2));
//         }

//         GPS2PositionCallback(msg, mutex, position_queue_ptr);
//     };

//     subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
//         topic_name, 1000, callback));

//     position_queue_list_.push_back(position_queue_ptr);
//     return {position_queue_ptr, mutex};
// }

PositionQueuePair ROSSubscriber::AddGPS2PositionSubscriber(
    const std::string &topic_name,
    const std::vector<double> &translation_gpssrc2body,
    const std::vector<double> &rotation_gpssrc2body) 
{
    std::cout << "Subscribing to GPS topic: " << topic_name << std::endl;
    
    auto position_queue_ptr = std::make_shared<OdomQueue>();
    auto mutex = std::make_shared<std::mutex>();

    // Set gps_src_to_body_ transform
    Eigen::Quaternion<double> orientation_quat(
        rotation_gpssrc2body[0], rotation_gpssrc2body[1],
        rotation_gpssrc2body[2], rotation_gpssrc2body[3]);

    gps_src_to_body_ = Eigen::Matrix4d::Identity();
    gps_src_to_body_.block<3, 3>(0, 0) = orientation_quat.toRotationMatrix();
    gps_src_to_body_.block<3, 1>(0, 3) = Eigen::Vector3d(translation_gpssrc2body.data());

    // Create a temporary subscription JUST to initialize reference_position
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr temp_sub;
    temp_sub = node_->create_subscription<sensor_msgs::msg::NavSatFix>(
        topic_name, 10,
        [&, this](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
            if (!reference_initialized) {
                reference_position << msg->latitude, msg->longitude, msg->altitude;
                reference_initialized = true;
                RCLCPP_INFO(node_->get_logger(), "GPS reference position initialized: [%f, %f, %f]", 
                            reference_position(0), reference_position(1), reference_position(2));
                
                // After initializing, destroy this temp subscriber
                temp_sub.reset();
            }
        });

    // Real subscriber (pure callback assuming reference_position is ready)
    auto callback = [this, mutex, position_queue_ptr](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        if (!reference_initialized) {
            reference_position << msg->latitude, msg->longitude, msg->altitude;
            reference_initialized = true;
            RCLCPP_INFO(node_->get_logger(), "GPS reference position initialized: [%f, %f, %f]", 
                        reference_position(0), reference_position(1), reference_position(2));
        }
    
        // RCLCPP_INFO(node_->get_logger(), "Processing GPS message: [%f, %f, %f]", msg->latitude, msg->longitude, msg->altitude);
        
        // Check if the reference position is initialized
        if (reference_initialized) {
            GPS2PositionCallback(msg, mutex, position_queue_ptr, reference_position);
        } else {
            RCLCPP_WARN(node_->get_logger(), "Reference position still not initialized! Skipping message.");
        }
    };
    // auto callback = [this, mutex, position_queue_ptr, reference_position](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
    //             GPS2PositionCallback(msg, mutex, position_queue_ptr, reference_position);
    //         };

    subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
        topic_name, 1000, callback));

    position_queue_list_.push_back(position_queue_ptr);

    return {position_queue_ptr, mutex};
}

PoseQueuePair ROSSubscriber::AddGPSIMU2PoseSubscriber(
    const std::string &gps_topic_name,
    const std::string &imu_topic_name,
    const std::vector<double> &translation_gpssrc2body,
    const std::vector<double> &rotation_gpssrc2body)
{
    std::cout << "Subscribing to GPS: " << gps_topic_name << " and IMU: " << imu_topic_name << std::endl;

    auto pose_queue_ptr = std::make_shared<OdomQueue>();
    auto mutex = std::make_shared<std::mutex>();

    // Reset heading correction state whenever this pipeline is created.
    prev_cog_position_initialized_ = false;
    yaw_bias_initialized_ = false;
    yaw_bias_rad_ = 0.0;

    // Transform from GPS source to robot body
    Eigen::Quaterniond orientation_quat(
        rotation_gpssrc2body[0], rotation_gpssrc2body[1],
        rotation_gpssrc2body[2], rotation_gpssrc2body[3]);

    gps_src_to_body_ = Eigen::Matrix4d::Identity();
    gps_src_to_body_.block<3,3>(0,0) = orientation_quat.toRotationMatrix();
    gps_src_to_body_.block<3,1>(0,3) = Eigen::Vector3d(translation_gpssrc2body.data());

    // IMU orientation state (latest orientation from IMU)
    std::shared_ptr<geometry_msgs::msg::Quaternion> latest_orientation =
        std::make_shared<geometry_msgs::msg::Quaternion>();

    auto imu_callback = [this, latest_orientation](const sensor_msgs::msg::Imu::SharedPtr msg) {
        *latest_orientation = msg->orientation;
    
        // Convert ROS quaternion to Eigen
        Eigen::Quaterniond current_q(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
    
        if (!this->initial_orientation_set) {
            *(this->initial_orientation) = current_q;
            this->initial_orientation_set = true;
        }        
    };    

    subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::Imu>(
        imu_topic_name, 1000, imu_callback));

    // GPS reference initialization
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr temp_sub;
    temp_sub = node_->create_subscription<sensor_msgs::msg::NavSatFix>(
        gps_topic_name, 10,
        [&, this](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
            if (!reference_initialized) {
                reference_position << msg->latitude, msg->longitude, msg->altitude;
                reference_initialized = true;
                RCLCPP_INFO(node_->get_logger(), "GPS reference initialized: [%f, %f, %f]",
                            reference_position(0), reference_position(1), reference_position(2));
                temp_sub.reset();
            }
        });

    auto gps_callback = [this, mutex, pose_queue_ptr, latest_orientation](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
        if (!reference_initialized) {
            reference_position << msg->latitude, msg->longitude, msg->altitude;
            reference_initialized = true;
            RCLCPP_INFO(node_->get_logger(), "GPS reference position initialized: [%f, %f, %f]", 
                        reference_position(0), reference_position(1), reference_position(2));
        }
    
        if (reference_initialized && this->initial_orientation_set) {
            const geometry_msgs::msg::Quaternion& ros_q = *latest_orientation;
            Eigen::Quaterniond current_q(ros_q.w, ros_q.x, ros_q.y, ros_q.z);
    
            // Compute relative orientation
            Eigen::Quaterniond relative_q = this->initial_orientation->inverse() * current_q;
    
            GPSIMU2PoseCallback(msg, mutex, relative_q, pose_queue_ptr, reference_position);
        } else {
            RCLCPP_WARN(node_->get_logger(), "Reference or initial orientation not initialized! Skipping message.");
        }
    };
    

    subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
        gps_topic_name, 1000, gps_callback));

    pose_queue_list_.push_back(pose_queue_ptr);
    return {pose_queue_ptr, mutex};
}

// PoseQueuePair ROSSubscriber::AddGPSIMU2PoseSubscriber(
//     const std::string &gps_topic_name,
//     const std::string &imu_topic_name,
//     const std::vector<double> &translation_gpssrc2body,
//     const std::vector<double> &rotation_gpssrc2body)
// {
//     std::cout << "Subscribing to GPS: " << gps_topic_name << " and IMU: " << imu_topic_name << std::endl;

//     auto pose_queue_ptr = std::make_shared<OdomQueue>();
//     auto mutex = std::make_shared<std::mutex>();

//     // Transform from GPS source to robot body
//     Eigen::Quaterniond orientation_quat(
//         rotation_gpssrc2body[0], rotation_gpssrc2body[1],
//         rotation_gpssrc2body[2], rotation_gpssrc2body[3]);

//     gps_src_to_body_ = Eigen::Matrix4d::Identity();
//     gps_src_to_body_.block<3,3>(0,0) = orientation_quat.toRotationMatrix();
//     gps_src_to_body_.block<3,1>(0,3) = Eigen::Vector3d(translation_gpssrc2body.data());

//     // === Replace dynamic IMU tracking with fixed orientation ===
//     // Set latest_orientation to identity (or static known value)
//     auto latest_orientation = std::make_shared<geometry_msgs::msg::Quaternion>();
//     latest_orientation->w = 1.0;  // Identity quaternion
//     latest_orientation->x = 0.0;
//     latest_orientation->y = 0.0;
//     latest_orientation->z = 0.0;

//     // Comment out the IMU subscriber for now (testing if it affects publishing rate)
//     /*
//     auto imu_callback = [this, latest_orientation](const sensor_msgs::msg::Imu::SharedPtr msg) {
//         *latest_orientation = msg->orientation;

//         Eigen::Quaterniond current_q(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);

//         if (!this->initial_orientation_set) {
//             *(this->initial_orientation) = current_q;
//             this->initial_orientation_set = true;
//         }
//     };

//     subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::Imu>(
//         imu_topic_name, 1000, imu_callback));
//     */

//     // Reference GPS init
//     rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr temp_sub;
//     temp_sub = node_->create_subscription<sensor_msgs::msg::NavSatFix>(
//         gps_topic_name, 10,
//         [&, this](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
//             if (!reference_initialized) {
//                 reference_position << msg->latitude, msg->longitude, msg->altitude;
//                 reference_initialized = true;
//                 RCLCPP_INFO(node_->get_logger(), "GPS reference initialized: [%f, %f, %f]",
//                             reference_position(0), reference_position(1), reference_position(2));
//                 temp_sub.reset();
//             }
//         });

//     auto gps_callback = [this, mutex, pose_queue_ptr, latest_orientation](const sensor_msgs::msg::NavSatFix::SharedPtr msg) {
//         if (!reference_initialized) {
//             reference_position << msg->latitude, msg->longitude, msg->altitude;
//             reference_initialized = true;
//             RCLCPP_INFO(node_->get_logger(), "GPS reference initialized: [%f, %f, %f]",
//                         reference_position(0), reference_position(1), reference_position(2));
//         }

//         if (reference_initialized /* && this->initial_orientation_set */) {
//             const geometry_msgs::msg::Quaternion& ros_q = *latest_orientation;
//             Eigen::Quaterniond current_q(ros_q.w, ros_q.x, ros_q.y, ros_q.z);

//             // If you want to simulate relative rotation: use identity
//             Eigen::Quaterniond relative_q = current_q; // No delta from initial orientation

//             GPSIMU2PoseCallback(msg, mutex, relative_q, pose_queue_ptr, reference_position);
//         } else {
//             RCLCPP_WARN(node_->get_logger(), "Reference not initialized! Skipping GPS message.");
//         }
//     };

//     subscriber_list_.push_back(node_->create_subscription<sensor_msgs::msg::NavSatFix>(
//         gps_topic_name, 1000, gps_callback));

//     pose_queue_list_.push_back(pose_queue_ptr);
//     return {pose_queue_ptr, mutex};
// }





// void ROSSubscriber::StartSubscribingThread() {
//     subscribing_thread_ = std::thread([this] { rclcpp::spin(node_); });
//     thread_started_ = true;
// }
void ROSSubscriber::StartSubscribingThread() {
    subscribing_thread_ = std::thread([this]() { this->RosSpin(); });
    thread_started_ = true;
}

// void ROSSubscriber::StartSubscribingThread() {
//     subscribing_thread_ = std::thread([this] { this->RosSpin(); });
//     thread_started_ = true;
// }

// void ROSSubscriber::StartSubscribingThread(std::shared_ptr<ROSSubscriber> node_ptr) {
//     subscribing_thread_ = std::thread([node_ptr] { node_ptr->RosSpin(); });
// }

// void ROS2Subscriber::IMUCallback(
//     const sensor_msgs::msg::Imu::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     IMUQueuePtr &imu_queue) {
// void ROSSubscriber::IMUCallback(
//     const sensor_msgs::msg::Imu::SharedPtr imu_msg,
//     const std::shared_ptr<std::mutex>& mutex, const IMUQueuePtr& imu_queue) {
//     auto imu_measurement = std::make_shared<ImuMeasurement<double>>();
//     // imu_measurement->set_header(msg->header.stamp.sec + msg->header.stamp.nanosec / 1e9, msg->header.frame_id);
//     imu_measurement->set_header(imu_msg->header.stamp.sec, 
//         imu_msg->header.stamp.sec + imu_msg->header.stamp.nanosec / 1e9, 
//         imu_msg->header.frame_id);
//     imu_measurement->set_angular_velocity(imu_msg->angular_velocity.x, imu_msg->angular_velocity.y, imu_msg->angular_velocity.z);
//     imu_measurement->set_lin_acc(imu_msg->linear_acceleration.x, imu_msg->linear_acceleration.y, imu_msg->linear_acceleration.z);

//     if (Eigen::Vector4d({imu_msg->orientation.w, imu_msg->orientation.x, imu_msg->orientation.y, imu_msg->orientation.z}).norm() != 0) {
//         imu_measurement->set_quaternion(imu_msg->orientation.w, imu_msg->orientation.x, imu_msg->orientation.y, imu_msg->orientation.z);
//     }
//     std::cout << "imu x_linear_acccel: " << imu_msg->linear_acceleration.x << std::endl;
//     std::cout << "imu y_linear_acccel: " << imu_msg->linear_acceleration.y << std::endl;
//     std::cout << "imu z_linear_acccel: " << imu_msg->linear_acceleration.z << std::endl;
//     // std::lock_guard<std::mutex> lock(*mutex);
//     mutex.get()->lock();
//     imu_queue->push(imu_measurement);
//     mutex.get()->unlock();
//     // RCLCPP_INFO(this->get_logger(), "IMU measurement added to queue. Queue size: %lu", imu_queue->size());
// }
void ROSSubscriber::IMUCallback(
    const sensor_msgs::msg::Imu::SharedPtr imu_msg, 
    std::shared_ptr<std::mutex> mutex, 
    IMUQueuePtr imu_queue) {

    // Create an IMU measurement object
    auto imu_measurement = std::make_shared<ImuMeasurement<double>>();

    // Set headers and timestamps
    imu_measurement->set_header(
        imu_msg->header.stamp.sec, 
        imu_msg->header.stamp.sec + imu_msg->header.stamp.nanosec / 1e9, 
        imu_msg->header.frame_id);

    // Set angular velocity
    imu_measurement->set_angular_velocity(
        imu_msg->angular_velocity.x,
        imu_msg->angular_velocity.y,
        imu_msg->angular_velocity.z);

    // Set linear acceleration
    imu_measurement->set_lin_acc(
        imu_msg->linear_acceleration.x,
        imu_msg->linear_acceleration.y,
        imu_msg->linear_acceleration.z);

    // Set quaternion if valid
    Eigen::Vector4d quat(imu_msg->orientation.w, 
                         imu_msg->orientation.x, 
                         imu_msg->orientation.y, 
                         imu_msg->orientation.z);

    if (quat.norm() != 0) {
        imu_measurement->set_quaternion(
            imu_msg->orientation.w, 
            imu_msg->orientation.x, 
            imu_msg->orientation.y, 
            imu_msg->orientation.z);
    }

    // Lock and push the measurement into the queue
    {
        std::lock_guard<std::mutex> lock(*mutex);
        imu_queue->push(imu_measurement);
    }

    // RCLCPP_INFO(node_->get_logger(), "IMU data received and queued.");
}

// void ROS2Subscriber::Odom2PositionCallback(
//     const nav_msgs::msg::Odometry::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     OdomQueuePtr &position_queue) {
void ROSSubscriber::Odom2PositionCallback(
    const nav_msgs::msg::Odometry::SharedPtr odom_msg,
    std::shared_ptr<std::mutex> position_mutex, OdomQueuePtr position_queue) {
    auto position_measurement = std::make_shared<OdomMeasurement>();
    Eigen::Vector3d translation(odom_msg->pose.pose.position.x, odom_msg->pose.pose.position.y, odom_msg->pose.pose.position.z);
    // std::cout << "pose x before transform: " << odom_msg->pose.pose.position.x << std::endl;
    // std::cout << "pose y before transform: " << odom_msg->pose.pose.position.y << std::endl;
    // std::cout << "pose z before transform: " << odom_msg->pose.pose.position.z << std::endl;
    Eigen::Matrix4d curr_transformation = Eigen::Matrix4d::Identity();
    curr_transformation.block<3, 1>(0, 3) = translation;
    Eigen::Matrix4d transformed_pose = odom_src_to_body_.inverse() * curr_transformation;
    Eigen::Vector3d transformed_translation = transformed_pose.block<3, 1>(0, 3);
    if (!transformed_translation.allFinite()) {
        // RCLCPP_WARN(this->get_logger(), "Invalid transformation detected!");
        return;
    }
    std::cout << "odom_msg time: " << odom_msg->header.stamp.sec + odom_msg->header.stamp.nanosec / 1e9 << std::endl;
    // position_measurement->set_header(msg->header.stamp.sec + msg->header.stamp.nanosec / 1e9, msg->header.frame_id);
    position_measurement->set_header(odom_msg->header.stamp.sec, 
        odom_msg->header.stamp.sec + odom_msg->header.stamp.nanosec / 1e9, 
        odom_msg->header.frame_id);
    position_measurement->set_translation(transformed_translation);
    position_measurement->set_transformation();
    std::cout << "pose after transform: " << transformed_translation << std::endl;
    std::cout << "odom_msg time: " << odom_msg->header.stamp.sec + odom_msg->header.stamp.nanosec / 1e9 << std::endl;
    // std::lock_guard<std::mutex> lock(*mutex);
    position_mutex.get()->lock();
    std::cout << "position_measurement...trans: " << position_measurement->get_transformation()<< std::endl;
    position_queue->push(position_measurement);
    position_mutex.get()->unlock();
    // RCLCPP_INFO(this->get_logger(), "Odom measurement added to queue. Queue size: %lu", position_queue->size());
}

// void ROS2Subscriber::GPS2PositionCallback(
//     const sensor_msgs::msg::NavSatFix::SharedPtr msg,
//     const std::shared_ptr<std::mutex> &mutex,
//     OdomQueuePtr &position_queue,
//     const Eigen::Vector3d &reference_position) {
// void ROS2Subscriber::GPS2PositionCallback(
//     const sensor_msgs::msg::NavSatFix::SharedPtr msg,
//     const std::shared_ptr<std::mutex>& mutex, const OdomQueuePtr& position_queue, const Eigen::Vector3d& reference_position) {
//     auto position_measurement = std::make_shared<OdomMeasurement>();
//     Eigen::Vector3d enu_translation = ConvertGPSToENU(msg, reference_position);
//     position_measurement->set_translation(enu_translation);
    
//     std::lock_guard<std::mutex> lock(*mutex);
//     position_queue->push(position_measurement);
// }
// void ROSSubscriber::GPS2PositionCallback(
//     const sensor_msgs::msg::NavSatFix::SharedPtr gps_msg,
//     std::shared_ptr<std::mutex> position_mutex,
//     OdomQueuePtr position_queue, 
//     const Eigen::Vector3d& reference_position) {

//     // std::shared_ptr<OdomMeasurement> position_measurement = std::make_shared<OdomMeasurement>();
//     auto position_measurement = std::make_shared<OdomMeasurement>();

//     double lat0 = reference_position(0);
//     double lon0 = reference_position(1);
//     double alt0 = reference_position(2);

//     // Convert GPS coordinates to ENU coordinates
//     measurement::NavSatMeasurement<double> navsat_measurement;
//     navsat_measurement.set_navsatfix(gps_msg->latitude, gps_msg->longitude, gps_msg->altitude);

//     // Obtain ENU coordinates relative to the reference lat/lon/alt
//     Eigen::Matrix<double, 3, 1> enu_translation = navsat_measurement.get_enu(lat0, lon0, alt0);

//     // Set up transformation matrix for ENU translation (no rotation as GPS lacks orientation data)
//     Eigen::Matrix4d enu_transformation = Eigen::Matrix4d::Identity();
//     enu_transformation.block<3, 1>(0, 3) = enu_translation;

//     Eigen::Matrix4d transformed_pose = gps_src_to_body_.inverse() * enu_transformation;

//     // Extract transformed translation
//     Eigen::Vector3d transformed_translation = transformed_pose.block<3, 1>(0, 3);

//     // Set headers and timestamps using ROS2 format
//     position_measurement->set_header(
//         gps_msg->header.stamp.sec,  // Sequence number (ROS2 does not use `seq`)
//         gps_msg->header.stamp.sec + gps_msg->header.stamp.nanosec / 1e9,
//         gps_msg->header.frame_id);

//     position_measurement->set_translation(transformed_translation);
//     position_measurement->set_transformation();

//     // Use lock_guard for RAII-based thread safety
//     // std::lock_guard<std::mutex> lock(*mutex);
//     position_mutex.get()->lock();
//     position_queue->push(position_measurement);
//     position_mutex.get()->unlock();
// }

void ROSSubscriber::GPS2PositionCallback(
    const sensor_msgs::msg::NavSatFix::SharedPtr gps_msg,
    std::shared_ptr<std::mutex> position_mutex,
    OdomQueuePtr position_queue,
    Eigen::Vector3d& reference_position)
{
    // If somehow called before reference initialized, skip safely
    if (!reference_initialized) {
        RCLCPP_WARN(node_->get_logger(), "Reference position not initialized yet! Ignoring GPS message.");
        return;
    }

    auto position_measurement = std::make_shared<OdomMeasurement>();

    double lat0 = reference_position(0);
    double lon0 = reference_position(1);
    double alt0 = reference_position(2);

    // Convert GPS to ENU
    measurement::NavSatMeasurement<double> navsat_measurement;
    navsat_measurement.set_navsatfix(gps_msg->latitude, gps_msg->longitude, gps_msg->altitude);

    Eigen::Matrix<double, 3, 1> enu_translation = navsat_measurement.get_enu(lat0, lon0, alt0);

    // Build ENU transformation (translation only, no rotation)
    Eigen::Matrix4d enu_transformation = Eigen::Matrix4d::Identity();
    enu_transformation.block<3, 1>(0, 3) = enu_translation;

    // Apply body-frame correction
    Eigen::Matrix4d transformed_pose = gps_src_to_body_.inverse() * enu_transformation;
    Eigen::Vector3d transformed_translation = transformed_pose.block<3, 1>(0, 3);

    // Fill position measurement
    position_measurement->set_header(
        gps_msg->header.stamp.sec,
        gps_msg->header.stamp.sec + gps_msg->header.stamp.nanosec / 1e9,
        gps_msg->header.frame_id);

    position_measurement->set_translation(transformed_translation);
    position_measurement->set_transformation();

    // Push into queue with thread safety
    {
        std::lock_guard<std::mutex> lock(*position_mutex);
        position_queue->push(position_measurement);
    }
}

void ROSSubscriber::GPSIMU2PoseCallback(
    const sensor_msgs::msg::NavSatFix::SharedPtr gps_msg,
    std::shared_ptr<std::mutex> pose_mutex,
    const Eigen::Quaterniond& imu_orientation,
    OdomQueuePtr pose_queue,
    Eigen::Vector3d& reference_position)
{
    if (!reference_initialized) {
        RCLCPP_WARN(node_->get_logger(), "Reference position not initialized yet! Ignoring GPS message.");
        return;
    }

    auto pose_measurement = std::make_shared<OdomMeasurement>();

    // Extract reference position
    double lat0 = reference_position(0);
    double lon0 = reference_position(1);
    double alt0 = reference_position(2);

    // Convert GPS to ENU
    measurement::NavSatMeasurement<double> navsat_measurement;
    navsat_measurement.set_navsatfix(gps_msg->latitude, gps_msg->longitude, gps_msg->altitude);
    Eigen::Vector3d enu_translation = navsat_measurement.get_enu(lat0, lon0, alt0);

    // Initial body-frame position estimate from GPS antenna position.
    Eigen::Vector3d transformed_translation = ConvertGpsAntennaPositionToBodyPosition(
        enu_translation, imu_orientation, gps_src_to_body_);

    // Build a heading-corrected orientation:
    // - roll/pitch from IMU orientation
    // - yaw from IMU + learned COG yaw bias
    Eigen::Vector3d imu_ypr = imu_orientation.toRotationMatrix().eulerAngles(2, 1, 0);
    const double imu_yaw = imu_ypr[0];
    const double imu_pitch = imu_ypr[1];
    const double imu_roll = imu_ypr[2];

    const double curr_time = gps_msg->header.stamp.sec + gps_msg->header.stamp.nanosec / 1e9;
    if (prev_cog_position_initialized_) {
        const Eigen::Vector2d d_xy =
            transformed_translation.head<2>() - prev_cog_position_.head<2>();
        const double dt = curr_time - prev_cog_time_;
        const double displacement = d_xy.norm();
        const double speed = dt > 1e-6 ? displacement / dt : 0.0;

        if (displacement >= cog_min_displacement_m_ && speed >= cog_min_speed_mps_) {
            const double cog_yaw = std::atan2(d_xy.y(), d_xy.x());
            const double measured_bias = WrapAngle(cog_yaw - imu_yaw);
            if (!yaw_bias_initialized_) {
                yaw_bias_rad_ = measured_bias;
                yaw_bias_initialized_ = true;
            } else {
                yaw_bias_rad_ = BlendAngle(yaw_bias_rad_, measured_bias, yaw_bias_filter_gain_);
            }
        }
    }

    const bool heading_bias_available = yaw_bias_initialized_ || initial_heading_offset_enabled_;
    const double heading_bias_rad =
        yaw_bias_initialized_ ? yaw_bias_rad_ : initial_heading_offset_rad_;
    const double corrected_yaw = heading_bias_available
        ? WrapAngle(imu_yaw + heading_bias_rad)
        : imu_yaw;
    const Eigen::Quaterniond corrected_orientation =
        YawPitchRollToQuaternion(corrected_yaw, imu_pitch, imu_roll);

    // Recompute translation with heading-corrected attitude once available.
    const Eigen::Quaterniond translation_orientation =
        heading_bias_available ? corrected_orientation : imu_orientation;
    transformed_translation = ConvertGpsAntennaPositionToBodyPosition(
        enu_translation, translation_orientation, gps_src_to_body_);

    prev_cog_position_ = transformed_translation;
    prev_cog_time_ = curr_time;
    prev_cog_position_initialized_ = true;

    // Compose final pose (position + orientation)
    pose_measurement->set_header(
        gps_msg->header.stamp.sec,
        gps_msg->header.stamp.sec + gps_msg->header.stamp.nanosec / 1e9,
        gps_msg->header.frame_id);

    pose_measurement->set_translation(transformed_translation);
    pose_measurement->set_rotation(corrected_orientation);

    pose_measurement->set_transformation();

    // Add to queue with thread safety
    {
        std::lock_guard<std::mutex> lock(*pose_mutex);
        pose_queue->push(pose_measurement);
    }
}



void ROSSubscriber::RosSpin() {
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node_);
    executor.spin();
}
// void RosSpin() {
//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(shared_from_this());  // Add the node to the executor
//     executor.spin();  // Spins using multiple threads
// }

// void RosSpin(std::shared_ptr<ROSSubscriber> node_ptr) {
//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(node_ptr);
//     executor.spin();
// }

} // namespace ros_wrapper
