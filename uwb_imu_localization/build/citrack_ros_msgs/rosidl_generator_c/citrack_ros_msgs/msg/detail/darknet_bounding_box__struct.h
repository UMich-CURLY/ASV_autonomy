// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DarknetBoundingBox in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__DarknetBoundingBox
{
  double probability;
  int64_t xmin;
  int64_t ymin;
  int64_t xmax;
  int64_t ymax;
  int16_t id;
  rosidl_runtime_c__String class_name;
} citrack_ros_msgs__msg__DarknetBoundingBox;

// Struct for a sequence of citrack_ros_msgs__msg__DarknetBoundingBox.
typedef struct citrack_ros_msgs__msg__DarknetBoundingBox__Sequence
{
  citrack_ros_msgs__msg__DarknetBoundingBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__DarknetBoundingBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOX__STRUCT_H_
