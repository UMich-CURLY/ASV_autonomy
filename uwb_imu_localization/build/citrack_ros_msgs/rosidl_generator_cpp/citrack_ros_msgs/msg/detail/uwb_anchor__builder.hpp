// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/UwbAnchor.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/uwb_anchor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_UwbAnchor_distancefromtag
{
public:
  explicit Init_UwbAnchor_distancefromtag(::citrack_ros_msgs::msg::UwbAnchor & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::UwbAnchor distancefromtag(::citrack_ros_msgs::msg::UwbAnchor::_distancefromtag_type arg)
  {
    msg_.distancefromtag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbAnchor msg_;
};

class Init_UwbAnchor_z
{
public:
  explicit Init_UwbAnchor_z(::citrack_ros_msgs::msg::UwbAnchor & msg)
  : msg_(msg)
  {}
  Init_UwbAnchor_distancefromtag z(::citrack_ros_msgs::msg::UwbAnchor::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_UwbAnchor_distancefromtag(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbAnchor msg_;
};

class Init_UwbAnchor_y
{
public:
  explicit Init_UwbAnchor_y(::citrack_ros_msgs::msg::UwbAnchor & msg)
  : msg_(msg)
  {}
  Init_UwbAnchor_z y(::citrack_ros_msgs::msg::UwbAnchor::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_UwbAnchor_z(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbAnchor msg_;
};

class Init_UwbAnchor_x
{
public:
  explicit Init_UwbAnchor_x(::citrack_ros_msgs::msg::UwbAnchor & msg)
  : msg_(msg)
  {}
  Init_UwbAnchor_y x(::citrack_ros_msgs::msg::UwbAnchor::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_UwbAnchor_y(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbAnchor msg_;
};

class Init_UwbAnchor_id
{
public:
  Init_UwbAnchor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbAnchor_x id(::citrack_ros_msgs::msg::UwbAnchor::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_UwbAnchor_x(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbAnchor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::UwbAnchor>()
{
  return citrack_ros_msgs::msg::builder::Init_UwbAnchor_id();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__BUILDER_HPP_
