// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/custom_tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_CustomTag_orientation_w
{
public:
  explicit Init_CustomTag_orientation_w(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::CustomTag orientation_w(::citrack_ros_msgs::msg::CustomTag::_orientation_w_type arg)
  {
    msg_.orientation_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_orientation_z
{
public:
  explicit Init_CustomTag_orientation_z(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_orientation_w orientation_z(::citrack_ros_msgs::msg::CustomTag::_orientation_z_type arg)
  {
    msg_.orientation_z = std::move(arg);
    return Init_CustomTag_orientation_w(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_orientation_y
{
public:
  explicit Init_CustomTag_orientation_y(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_orientation_z orientation_y(::citrack_ros_msgs::msg::CustomTag::_orientation_y_type arg)
  {
    msg_.orientation_y = std::move(arg);
    return Init_CustomTag_orientation_z(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_orientation_x
{
public:
  explicit Init_CustomTag_orientation_x(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_orientation_y orientation_x(::citrack_ros_msgs::msg::CustomTag::_orientation_x_type arg)
  {
    msg_.orientation_x = std::move(arg);
    return Init_CustomTag_orientation_y(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_pose_z
{
public:
  explicit Init_CustomTag_pose_z(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_orientation_x pose_z(::citrack_ros_msgs::msg::CustomTag::_pose_z_type arg)
  {
    msg_.pose_z = std::move(arg);
    return Init_CustomTag_orientation_x(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_pose_y
{
public:
  explicit Init_CustomTag_pose_y(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_pose_z pose_y(::citrack_ros_msgs::msg::CustomTag::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_CustomTag_pose_z(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_pose_x
{
public:
  explicit Init_CustomTag_pose_x(::citrack_ros_msgs::msg::CustomTag & msg)
  : msg_(msg)
  {}
  Init_CustomTag_pose_y pose_x(::citrack_ros_msgs::msg::CustomTag::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_CustomTag_pose_y(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

class Init_CustomTag_header
{
public:
  Init_CustomTag_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CustomTag_pose_x header(::citrack_ros_msgs::msg::CustomTag::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CustomTag_pose_x(msg_);
  }

private:
  ::citrack_ros_msgs::msg::CustomTag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::CustomTag>()
{
  return citrack_ros_msgs::msg::builder::Init_CustomTag_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__BUILDER_HPP_
