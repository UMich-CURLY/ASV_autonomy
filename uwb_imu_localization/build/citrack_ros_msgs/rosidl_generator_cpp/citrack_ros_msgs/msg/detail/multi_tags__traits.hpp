// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from citrack_ros_msgs:msg/MultiTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__TRAITS_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "citrack_ros_msgs/msg/detail/multi_tags__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tags_list'
#include "citrack_ros_msgs/msg/detail/custom_tag__traits.hpp"

namespace citrack_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultiTags & msg,
  std::ostream & out)
{
  out << "{";
  // member: tags_list
  {
    if (msg.tags_list.size() == 0) {
      out << "tags_list: []";
    } else {
      out << "tags_list: [";
      size_t pending_items = msg.tags_list.size();
      for (auto item : msg.tags_list) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultiTags & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tags_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tags_list.size() == 0) {
      out << "tags_list: []\n";
    } else {
      out << "tags_list:\n";
      for (auto item : msg.tags_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultiTags & msg, bool use_flow_style = false)
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
  const citrack_ros_msgs::msg::MultiTags & msg,
  std::ostream & out, size_t indentation = 0)
{
  citrack_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use citrack_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const citrack_ros_msgs::msg::MultiTags & msg)
{
  return citrack_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<citrack_ros_msgs::msg::MultiTags>()
{
  return "citrack_ros_msgs::msg::MultiTags";
}

template<>
inline const char * name<citrack_ros_msgs::msg::MultiTags>()
{
  return "citrack_ros_msgs/msg/MultiTags";
}

template<>
struct has_fixed_size<citrack_ros_msgs::msg::MultiTags>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<citrack_ros_msgs::msg::MultiTags>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<citrack_ros_msgs::msg::MultiTags>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__TRAITS_HPP_
