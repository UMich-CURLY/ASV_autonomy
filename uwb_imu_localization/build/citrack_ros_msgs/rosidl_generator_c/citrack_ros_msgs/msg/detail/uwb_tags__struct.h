// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/UwbTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_H_

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
// Member 'tags'
#include "citrack_ros_msgs/msg/detail/uwb_tag__struct.h"

/// Struct defined in msg/UwbTags in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__UwbTags
{
  std_msgs__msg__Header header;
  citrack_ros_msgs__msg__UwbTag__Sequence tags;
} citrack_ros_msgs__msg__UwbTags;

// Struct for a sequence of citrack_ros_msgs__msg__UwbTags.
typedef struct citrack_ros_msgs__msg__UwbTags__Sequence
{
  citrack_ros_msgs__msg__UwbTags * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__UwbTags__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_H_
