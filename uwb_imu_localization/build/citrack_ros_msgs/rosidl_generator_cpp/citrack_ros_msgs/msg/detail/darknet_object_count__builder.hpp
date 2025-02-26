// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/darknet_object_count__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_DarknetObjectCount_count
{
public:
  explicit Init_DarknetObjectCount_count(::citrack_ros_msgs::msg::DarknetObjectCount & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::DarknetObjectCount count(::citrack_ros_msgs::msg::DarknetObjectCount::_count_type arg)
  {
    msg_.count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetObjectCount msg_;
};

class Init_DarknetObjectCount_header
{
public:
  Init_DarknetObjectCount_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetObjectCount_count header(::citrack_ros_msgs::msg::DarknetObjectCount::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DarknetObjectCount_count(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetObjectCount msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::DarknetObjectCount>()
{
  return citrack_ros_msgs::msg::builder::Init_DarknetObjectCount_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__BUILDER_HPP_
