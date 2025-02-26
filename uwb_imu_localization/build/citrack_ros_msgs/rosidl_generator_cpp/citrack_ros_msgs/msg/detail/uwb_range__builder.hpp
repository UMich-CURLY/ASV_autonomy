// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/uwb_range__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_UwbRange_range
{
public:
  explicit Init_UwbRange_range(::citrack_ros_msgs::msg::UwbRange & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::UwbRange range(::citrack_ros_msgs::msg::UwbRange::_range_type arg)
  {
    msg_.range = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbRange msg_;
};

class Init_UwbRange_anc_id
{
public:
  explicit Init_UwbRange_anc_id(::citrack_ros_msgs::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_range anc_id(::citrack_ros_msgs::msg::UwbRange::_anc_id_type arg)
  {
    msg_.anc_id = std::move(arg);
    return Init_UwbRange_range(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbRange msg_;
};

class Init_UwbRange_tag_id
{
public:
  explicit Init_UwbRange_tag_id(::citrack_ros_msgs::msg::UwbRange & msg)
  : msg_(msg)
  {}
  Init_UwbRange_anc_id tag_id(::citrack_ros_msgs::msg::UwbRange::_tag_id_type arg)
  {
    msg_.tag_id = std::move(arg);
    return Init_UwbRange_anc_id(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbRange msg_;
};

class Init_UwbRange_header
{
public:
  Init_UwbRange_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbRange_tag_id header(::citrack_ros_msgs::msg::UwbRange::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UwbRange_tag_id(msg_);
  }

private:
  ::citrack_ros_msgs::msg::UwbRange msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::UwbRange>()
{
  return citrack_ros_msgs::msg::builder::Init_UwbRange_header();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__BUILDER_HPP_
