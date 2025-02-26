// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/UwbTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/uwb_tags__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_UwbTags_tags
{
public:
  explicit Init_UwbTags_tags(::citrack_ros_msgs::msg::UwbTags & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::UwbTags tags(::citrack_ros_msgs::msg::UwbTags::_tags_type arg)
  {
    msg_.tags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTags msg_;
};

class Init_UwbTags_header
{
public:
  Init_UwbTags_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbTags_tags header(::citrack_ros_msgs::msg::UwbTags::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UwbTags_tags(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbTags msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::UwbTags>()
{
  return citrack_ros_msgs::msg::builder::Init_UwbTags_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__BUILDER_HPP_
