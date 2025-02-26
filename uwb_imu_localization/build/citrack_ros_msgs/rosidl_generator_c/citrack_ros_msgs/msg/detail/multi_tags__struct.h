// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/MultiTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tags_list'
#include "citrack_ros_msgs/msg/detail/custom_tag__struct.h"

/// Struct defined in msg/MultiTags in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__MultiTags
{
  citrack_ros_msgs__msg__CustomTag__Sequence tags_list;
} citrack_ros_msgs__msg__MultiTags;

// Struct for a sequence of citrack_ros_msgs__msg__MultiTags.
typedef struct citrack_ros_msgs__msg__MultiTags__Sequence
{
  citrack_ros_msgs__msg__MultiTags * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__MultiTags__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_H_
