// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/UwbTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/uwb_tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_UwbTag_z
{
public:
  explicit Init_UwbTag_z(::citrack_ros_msgs::msg::UwbTag & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::UwbTag z(::citrack_ros_msgs::msg::UwbTag::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTag msg_;
};

class Init_UwbTag_y
{
public:
  explicit Init_UwbTag_y(::citrack_ros_msgs::msg::UwbTag & msg)
  : msg_(msg)
  {}
  Init_UwbTag_z y(::citrack_ros_msgs::msg::UwbTag::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_UwbTag_z(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTag msg_;
};

class Init_UwbTag_x
{
public:
  explicit Init_UwbTag_x(::citrack_ros_msgs::msg::UwbTag & msg)
  : msg_(msg)
  {}
  Init_UwbTag_y x(::citrack_ros_msgs::msg::UwbTag::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_UwbTag_y(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTag msg_;
};

class Init_UwbTag_id
{
public:
  Init_UwbTag_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbTag_x id(::citrack_ros_msgs::msg::UwbTag::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_UwbTag_x(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::UwbTag>()
{
  return citrack_ros_msgs::msg::builder::Init_UwbTag_id();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__BUILDER_HPP_
