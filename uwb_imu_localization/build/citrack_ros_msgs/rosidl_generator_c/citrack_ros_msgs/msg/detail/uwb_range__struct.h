// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_H_

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
// Member 'tag_id'
// Member 'anc_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/UwbRange in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__UwbRange
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String tag_id;
  rosidl_runtime_c__String anc_id;
  double range;
} citrack_ros_msgs__msg__UwbRange;

// Struct for a sequence of citrack_ros_msgs__msg__UwbRange.
typedef struct citrack_ros_msgs__msg__UwbRange__Sequence
{
  citrack_ros_msgs__msg__UwbRange * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__UwbRange__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_H_
