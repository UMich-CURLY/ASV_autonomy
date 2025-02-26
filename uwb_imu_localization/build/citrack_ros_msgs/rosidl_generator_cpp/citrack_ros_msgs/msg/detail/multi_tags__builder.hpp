// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/MultiTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/multi_tags__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_MultiTags_tags_list
{
public:
  Init_MultiTags_tags_list()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::citrack_ros_msgs::msg::MultiTags tags_list(::citrack_ros_msgs::msg::MultiTags::_tags_list_type arg)
  {
    msg_.tags_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::MultiTags msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::MultiTags>()
{
  return citrack_ros_msgs::msg::builder::Init_MultiTags_tags_list();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__BUILDER_HPP_
