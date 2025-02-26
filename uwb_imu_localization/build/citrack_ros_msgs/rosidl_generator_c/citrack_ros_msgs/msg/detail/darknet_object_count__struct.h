// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__STRUCT_H_

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

/// Struct defined in msg/DarknetObjectCount in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__DarknetObjectCount
{
  std_msgs__msg__Header header;
  int8_t count;
} citrack_ros_msgs__msg__DarknetObjectCount;

// Struct for a sequence of citrack_ros_msgs__msg__DarknetObjectCount.
typedef struct citrack_ros_msgs__msg__DarknetObjectCount__Sequence
{
  citrack_ros_msgs__msg__DarknetObjectCount * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__DarknetObjectCount__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_OBJECT_COUNT__STRUCT_H_
