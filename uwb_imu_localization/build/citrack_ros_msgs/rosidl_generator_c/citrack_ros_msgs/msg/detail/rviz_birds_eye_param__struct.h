// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/RvizBirdsEyeParam.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_H_

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
// Member 'offset'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/RvizBirdsEyeParam in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__RvizBirdsEyeParam
{
  std_msgs__msg__Header header;
  /// Size of the BirdEye image in px
  int32_t height;
  int32_t width;
  /// Pixel from upper left corner to the origin of the car coordinate system. (z=0)
  geometry_msgs__msg__Point offset;
  /// Resolution of the bird's-eye view image in px / m.
  double resolution;
} citrack_ros_msgs__msg__RvizBirdsEyeParam;

// Struct for a sequence of citrack_ros_msgs__msg__RvizBirdsEyeParam.
typedef struct citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence
{
  citrack_ros_msgs__msg__RvizBirdsEyeParam * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_H_
