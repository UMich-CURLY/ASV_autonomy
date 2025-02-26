// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from citrack_ros_msgs:msg/UwbTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__TRAITS_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "citrack_ros_msgs/msg/detail/uwb_tag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace citrack_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UwbTag & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UwbTag & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UwbTag & msg, bool use_flow_style = false)
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
  const citrack_ros_msgs::msg::UwbTag & msg,
  std::ostream & out, size_t indentation = 0)
{
  citrack_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use citrack_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const citrack_ros_msgs::msg::UwbTag & msg)
{
  return citrack_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<citrack_ros_msgs::msg::UwbTag>()
{
  return "citrack_ros_msgs::msg::UwbTag";
}

template<>
inline const char * name<citrack_ros_msgs::msg::UwbTag>()
{
  return "citrack_ros_msgs/msg/UwbTag";
}

template<>
struct has_fixed_size<citrack_ros_msgs::msg::UwbTag>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<citrack_ros_msgs::msg::UwbTag>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<citrack_ros_msgs::msg::UwbTag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__TRAITS_HPP_
