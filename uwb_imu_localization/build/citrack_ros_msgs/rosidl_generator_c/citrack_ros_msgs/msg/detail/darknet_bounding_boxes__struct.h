// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_H_

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
// Member 'image_header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'bounding_boxes'
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.h"

/// Struct defined in msg/DarknetBoundingBoxes in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__DarknetBoundingBoxes
{
  std_msgs__msg__Header header;
  std_msgs__msg__Header image_header;
  citrack_ros_msgs__msg__DarknetBoundingBox__Sequence bounding_boxes;
} citrack_ros_msgs__msg__DarknetBoundingBoxes;

// Struct for a sequence of citrack_ros_msgs__msg__DarknetBoundingBoxes.
typedef struct citrack_ros_msgs__msg__DarknetBoundingBoxes__Sequence
{
  citrack_ros_msgs__msg__DarknetBoundingBoxes * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__DarknetBoundingBoxes__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_H_
