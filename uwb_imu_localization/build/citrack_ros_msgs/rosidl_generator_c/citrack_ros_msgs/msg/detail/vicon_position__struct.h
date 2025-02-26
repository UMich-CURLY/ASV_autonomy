// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:msg/ViconPosition.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__STRUCT_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'segment_name'
// Member 'subject_name'
// Member 'translation_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ViconPosition in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__msg__ViconPosition
{
  float x_trans;
  float y_trans;
  float z_trans;
  float x_rot;
  float y_rot;
  float z_rot;
  float w;
  rosidl_runtime_c__String segment_name;
  rosidl_runtime_c__String subject_name;
  int32_t frame_number;
  rosidl_runtime_c__String translation_type;
} citrack_ros_msgs__msg__ViconPosition;

// Struct for a sequence of citrack_ros_msgs__msg__ViconPosition.
typedef struct citrack_ros_msgs__msg__ViconPosition__Sequence
{
  citrack_ros_msgs__msg__ViconPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__msg__ViconPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__VICON_POSITION__STRUCT_H_
