// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__TRAITS_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
// Member 'image_header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'bounding_boxes'
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__traits.hpp"

namespace citrack_ros_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DarknetBoundingBoxes & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: image_header
  {
    out << "image_header: ";
    to_flow_style_yaml(msg.image_header, out);
    out << ", ";
  }

  // member: bounding_boxes
  {
    if (msg.bounding_boxes.size() == 0) {
      out << "bounding_boxes: []";
    } else {
      out << "bounding_boxes: [";
      size_t pending_items = msg.bounding_boxes.size();
      for (auto item : msg.bounding_boxes) {
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
  const DarknetBoundingBoxes & msg,
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

  // member: image_header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image_header:\n";
    to_block_style_yaml(msg.image_header, out, indentation + 2);
  }

  // member: bounding_boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bounding_boxes.size() == 0) {
      out << "bounding_boxes: []\n";
    } else {
      out << "bounding_boxes:\n";
      for (auto item : msg.bounding_boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DarknetBoundingBoxes & msg, bool use_flow_style = false)
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
  const citrack_ros_msgs::msg::DarknetBoundingBoxes & msg,
  std::ostream & out, size_t indentation = 0)
{
  citrack_ros_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use citrack_ros_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const citrack_ros_msgs::msg::DarknetBoundingBoxes & msg)
{
  return citrack_ros_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<citrack_ros_msgs::msg::DarknetBoundingBoxes>()
{
  return "citrack_ros_msgs::msg::DarknetBoundingBoxes";
}

template<>
inline const char * name<citrack_ros_msgs::msg::DarknetBoundingBoxes>()
{
  return "citrack_ros_msgs/msg/DarknetBoundingBoxes";
}

template<>
struct has_fixed_size<citrack_ros_msgs::msg::DarknetBoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<citrack_ros_msgs::msg::DarknetBoundingBoxes>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<citrack_ros_msgs::msg::DarknetBoundingBoxes>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__TRAITS_HPP_
