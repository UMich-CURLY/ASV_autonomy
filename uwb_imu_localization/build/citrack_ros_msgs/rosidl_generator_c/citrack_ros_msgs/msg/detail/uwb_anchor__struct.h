// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/UwbAnchor.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/UwbAnchor in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__UwbAnchor
{
  rosidl_runtime_c__String id;
  double x;
  double y;
  double z;
  double distancefromtag;
} citrack_ros_msgs__msg__UwbAnchor;

// Struct for a sequence of citrack_ros_msgs__msg__UwbAnchor.
typedef struct citrack_ros_msgs__msg__UwbAnchor__Sequence
{
  citrack_ros_msgs__msg__UwbAnchor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__UwbAnchor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_ANCHOR__STRUCT_H_
