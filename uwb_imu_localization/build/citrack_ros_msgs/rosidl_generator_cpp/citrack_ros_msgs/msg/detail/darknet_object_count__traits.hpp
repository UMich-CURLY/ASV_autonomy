// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__TRAITS_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "citrack_ros_msgs/msg/detail/darknet_object_count__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace citrack_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DarknetObjectCount & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: count
  {
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DarknetObjectCount & msg,
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

  // member: count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DarknetObjectCount & msg, bool use_flow_style = false)
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
  const citrack_ros_msgs::msg::DarknetObjectCount & msg,
  std::ostream & out, size_t indentation = 0)
{
  citrack_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use citrack_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const citrack_ros_msgs::msg::DarknetObjectCount & msg)
{
  return citrack_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<citrack_ros_msgs::msg::DarknetObjectCount>()
{
  return "citrack_ros_msgs::msg::DarknetObjectCount";
}

template<>
inline const char * name<citrack_ros_msgs::msg::DarknetObjectCount>()
{
  return "citrack_ros_msgs/msg/DarknetObjectCount";
}

template<>
struct has_fixed_size<citrack_ros_msgs::msg::DarknetObjectCount>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<citrack_ros_msgs::msg::DarknetObjectCount>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<citrack_ros_msgs::msg::DarknetObjectCount>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__TRAITS_HPP_
