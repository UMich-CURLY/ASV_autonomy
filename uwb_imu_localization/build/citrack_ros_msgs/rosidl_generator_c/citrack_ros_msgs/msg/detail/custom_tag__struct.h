// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/CustomTag in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__CustomTag
{
  std_msgs__msg__Header header;
  double pose_x;
  double pose_y;
  double pose_z;
  double orientation_x;
  double orientation_y;
  double orientation_z;
  double orientation_w;
} citrack_ros_msgs__msg__CustomTag;

// Struct for a sequence of citrack_ros_msgs__msg__CustomTag.
typedef struct citrack_ros_msgs__msg__CustomTag__Sequence
{
  citrack_ros_msgs__msg__CustomTag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__CustomTag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_H_
