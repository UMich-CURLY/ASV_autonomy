// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/RvizBirdsEyeParam.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/rviz_birds_eye_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_RvizBirdsEyeParam_resolution
{
public:
  explicit Init_RvizBirdsEyeParam_resolution(::citrack_ros_msgs::msg::RvizBirdsEyeParam & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam resolution(::citrack_ros_msgs::msg::RvizBirdsEyeParam::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam msg_;
};

class Init_RvizBirdsEyeParam_offset
{
public:
  explicit Init_RvizBirdsEyeParam_offset(::citrack_ros_msgs::msg::RvizBirdsEyeParam & msg)
  : msg_(msg)
  {}
  Init_RvizBirdsEyeParam_resolution offset(::citrack_ros_msgs::msg::RvizBirdsEyeParam::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return Init_RvizBirdsEyeParam_resolution(msg_);
  }

private:
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam msg_;
};

class Init_RvizBirdsEyeParam_width
{
public:
  explicit Init_RvizBirdsEyeParam_width(::citrack_ros_msgs::msg::RvizBirdsEyeParam & msg)
  : msg_(msg)
  {}
  Init_RvizBirdsEyeParam_offset width(::citrack_ros_msgs::msg::RvizBirdsEyeParam::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_RvizBirdsEyeParam_offset(msg_);
  }

private:
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam msg_;
};

class Init_RvizBirdsEyeParam_height
{
public:
  explicit Init_RvizBirdsEyeParam_height(::citrack_ros_msgs::msg::RvizBirdsEyeParam & msg)
  : msg_(msg)
  {}
  Init_RvizBirdsEyeParam_width height(::citrack_ros_msgs::msg::RvizBirdsEyeParam::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_RvizBirdsEyeParam_width(msg_);
  }

private:
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam msg_;
};

class Init_RvizBirdsEyeParam_header
{
public:
  Init_RvizBirdsEyeParam_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RvizBirdsEyeParam_height header(::citrack_ros_msgs::msg::RvizBirdsEyeParam::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RvizBirdsEyeParam_height(msg_);
  }

private:
  ::citrack_ros_msgs::msg::RvizBirdsEyeParam msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::RvizBirdsEyeParam>()
{
  return citrack_ros_msgs::msg::builder::Init_RvizBirdsEyeParam_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__BUILDER_HPP_
