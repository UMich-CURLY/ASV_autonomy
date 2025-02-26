// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:msg/ViconPosition.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__BUILDER_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/msg/detail/vicon_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace msg
{

namespace builder
{

class Init_ViconPosition_translation_type
{
public:
  explicit Init_ViconPosition_translation_type(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::msg::ViconPosition translation_type(::citrack_ros_msgs::msg::ViconPosition::_translation_type_type arg)
  {
    msg_.translation_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_frame_number
{
public:
  explicit Init_ViconPosition_frame_number(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_translation_type frame_number(::citrack_ros_msgs::msg::ViconPosition::_frame_number_type arg)
  {
    msg_.frame_number = std::move(arg);
    return Init_ViconPosition_translation_type(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_subject_name
{
public:
  explicit Init_ViconPosition_subject_name(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_frame_number subject_name(::citrack_ros_msgs::msg::ViconPosition::_subject_name_type arg)
  {
    msg_.subject_name = std::move(arg);
    return Init_ViconPosition_frame_number(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_segment_name
{
public:
  explicit Init_ViconPosition_segment_name(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_subject_name segment_name(::citrack_ros_msgs::msg::ViconPosition::_segment_name_type arg)
  {
    msg_.segment_name = std::move(arg);
    return Init_ViconPosition_subject_name(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_w
{
public:
  explicit Init_ViconPosition_w(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_segment_name w(::citrack_ros_msgs::msg::ViconPosition::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_ViconPosition_segment_name(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_z_rot
{
public:
  explicit Init_ViconPosition_z_rot(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_w z_rot(::citrack_ros_msgs::msg::ViconPosition::_z_rot_type arg)
  {
    msg_.z_rot = std::move(arg);
    return Init_ViconPosition_w(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_y_rot
{
public:
  explicit Init_ViconPosition_y_rot(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_z_rot y_rot(::citrack_ros_msgs::msg::ViconPosition::_y_rot_type arg)
  {
    msg_.y_rot = std::move(arg);
    return Init_ViconPosition_z_rot(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_x_rot
{
public:
  explicit Init_ViconPosition_x_rot(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_y_rot x_rot(::citrack_ros_msgs::msg::ViconPosition::_x_rot_type arg)
  {
    msg_.x_rot = std::move(arg);
    return Init_ViconPosition_y_rot(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_z_trans
{
public:
  explicit Init_ViconPosition_z_trans(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_x_rot z_trans(::citrack_ros_msgs::msg::ViconPosition::_z_trans_type arg)
  {
    msg_.z_trans = std::move(arg);
    return Init_ViconPosition_x_rot(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_y_trans
{
public:
  explicit Init_ViconPosition_y_trans(::citrack_ros_msgs::msg::ViconPosition & msg)
  : msg_(msg)
  {}
  Init_ViconPosition_z_trans y_trans(::citrack_ros_msgs::msg::ViconPosition::_y_trans_type arg)
  {
    msg_.y_trans = std::move(arg);
    return Init_ViconPosition_z_trans(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

class Init_ViconPosition_x_trans
{
public:
  Init_ViconPosition_x_trans()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ViconPosition_y_trans x_trans(::citrack_ros_msgs::msg::ViconPosition::_x_trans_type arg)
  {
    msg_.x_trans = std::move(arg);
    return Init_ViconPosition_y_trans(msg_);
  }

private:
  ::citrack_ros_msgs::msg::ViconPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::msg::ViconPosition>()
{
  return citrack_ros_msgs::msg::builder::Init_ViconPosition_x_trans();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__BUILDER_HPP_
