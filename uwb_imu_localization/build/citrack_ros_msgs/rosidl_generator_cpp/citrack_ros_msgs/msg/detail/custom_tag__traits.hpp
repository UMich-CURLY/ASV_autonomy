// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__TRAITS_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "citrack_ros_msgs/msg/detail/custom_tag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace citrack_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CustomTag & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pose_x
  {
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << ", ";
  }

  // member: pose_y
  {
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << ", ";
  }

  // member: pose_z
  {
    out << "pose_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_z, out);
    out << ", ";
  }

  // member: orientation_x
  {
    out << "orientation_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_x, out);
    out << ", ";
  }

  // member: orientation_y
  {
    out << "orientation_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_y, out);
    out << ", ";
  }

  // member: orientation_z
  {
    out << "orientation_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_z, out);
    out << ", ";
  }

  // member: orientation_w
  {
    out << "orientation_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CustomTag & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: pose_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << "\n";
  }

  // member: pose_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << "\n";
  }

  // member: pose_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_z, out);
    out << "\n";
  }

  // member: orientation_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_x: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_x, out);
    out << "\n";
  }

  // member: orientation_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_y: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_y, out);
    out << "\n";
  }

  // member: orientation_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_z: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_z, out);
    out << "\n";
  }

  // member: orientation_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_w: ";
    rosidl_generator_traits::value_to_yaml(msg.orientation_w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CustomTag & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace citrack_ros_msgs

namespace rosidl_generator_traits
{

[[deprecated("use citrack_ros_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const citrack_ros_msgs::msg::CustomTag & msg,
  std::ostream & out, size_t indentation = 0)
{
  citrack_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use citrack_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const citrack_ros_msgs::msg::CustomTag & msg)
{
  return citrack_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<citrack_ros_msgs::msg::CustomTag>()
{
  return "citrack_ros_msgs::msg::CustomTag";
}

template<>
inline const char * name<citrack_ros_msgs::msg::CustomTag>()
{
  return "citrack_ros_msgs/msg/CustomTag";
}

template<>
struct has_fixed_size<citrack_ros_msgs::msg::CustomTag>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<citrack_ros_msgs::msg::CustomTag>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<citrack_ros_msgs::msg::CustomTag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__TRAITS_HPP_
