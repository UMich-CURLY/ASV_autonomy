// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_DarknetBoundingBoxes_bounding_boxes
{
public:
  explicit Init_DarknetBoundingBoxes_bounding_boxes(::citrack_ros_msgs::msg::DarknetBoundingBoxes & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::DarknetBoundingBoxes bounding_boxes(::citrack_ros_msgs::msg::DarknetBoundingBoxes::_bounding_boxes_type arg)
  {
    msg_.bounding_boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBoxes msg_;
};

class Init_DarknetBoundingBoxes_image_header
{
public:
  explicit Init_DarknetBoundingBoxes_image_header(::citrack_ros_msgs::msg::DarknetBoundingBoxes & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBoxes_bounding_boxes image_header(::citrack_ros_msgs::msg::DarknetBoundingBoxes::_image_header_type arg)
  {
    msg_.image_header = std::move(arg);
    return Init_DarknetBoundingBoxes_bounding_boxes(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBoxes msg_;
};

class Init_DarknetBoundingBoxes_header
{
public:
  Init_DarknetBoundingBoxes_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetBoundingBoxes_image_header header(::citrack_ros_msgs::msg::DarknetBoundingBoxes::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DarknetBoundingBoxes_image_header(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBoxes msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::DarknetBoundingBoxes>()
{
  return citrack_ros_msgs::msg::builder::Init_DarknetBoundingBoxes_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__BUILDER_HPP_
