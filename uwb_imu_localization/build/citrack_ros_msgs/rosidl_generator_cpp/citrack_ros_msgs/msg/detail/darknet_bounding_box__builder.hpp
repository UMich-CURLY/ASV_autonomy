// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_DarknetBoundingBox_class_name
{
public:
  explicit Init_DarknetBoundingBox_class_name(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::DarknetBoundingBox class_name(::citrack_ros_msgs::msg::DarknetBoundingBox::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_id
{
public:
  explicit Init_DarknetBoundingBox_id(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBox_class_name id(::citrack_ros_msgs::msg::DarknetBoundingBox::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DarknetBoundingBox_class_name(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_ymax
{
public:
  explicit Init_DarknetBoundingBox_ymax(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBox_id ymax(::citrack_ros_msgs::msg::DarknetBoundingBox::_ymax_type arg)
  {
    msg_.ymax = std::move(arg);
    return Init_DarknetBoundingBox_id(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_xmax
{
public:
  explicit Init_DarknetBoundingBox_xmax(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBox_ymax xmax(::citrack_ros_msgs::msg::DarknetBoundingBox::_xmax_type arg)
  {
    msg_.xmax = std::move(arg);
    return Init_DarknetBoundingBox_ymax(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_ymin
{
public:
  explicit Init_DarknetBoundingBox_ymin(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBox_xmax ymin(::citrack_ros_msgs::msg::DarknetBoundingBox::_ymin_type arg)
  {
    msg_.ymin = std::move(arg);
    return Init_DarknetBoundingBox_xmax(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_xmin
{
public:
  explicit Init_DarknetBoundingBox_xmin(::citrack_ros_msgs::msg::DarknetBoundingBox & msg)
  : msg_(msg)
  {}
  Init_DarknetBoundingBox_ymin xmin(::citrack_ros_msgs::msg::DarknetBoundingBox::_xmin_type arg)
  {
    msg_.xmin = std::move(arg);
    return Init_DarknetBoundingBox_ymin(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

class Init_DarknetBoundingBox_probability
{
public:
  Init_DarknetBoundingBox_probability()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetBoundingBox_xmin probability(::citrack_ros_msgs::msg::DarknetBoundingBox::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return Init_DarknetBoundingBox_xmin(msg_);
  }

private:
  ::citrack_ros_msgs::msg::DarknetBoundingBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::DarknetBoundingBox>()
{
  return citrack_ros_msgs::msg::builder::Init_DarknetBoundingBox_probability();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__BUILDER_HPP_
