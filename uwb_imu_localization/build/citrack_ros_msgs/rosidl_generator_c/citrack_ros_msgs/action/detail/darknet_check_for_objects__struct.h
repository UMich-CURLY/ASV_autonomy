// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__STRUCT_H_
#define CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Goal
{
  /// Goal definition
  int16_t id;
  sensor_msgs__msg__Image image;
} citrack_ros_msgs__action__DarknetCheckForObjects_Goal;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_Goal.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'bounding_boxes'
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Result
{
  int16_t id;
  citrack_ros_msgs__msg__DarknetBoundingBoxes bounding_boxes;
} citrack_ros_msgs__action__DarknetCheckForObjects_Result;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_Result.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} citrack_ros_msgs__action__DarknetCheckForObjects_Feedback;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_Feedback.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal goal;
} citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response
{
  int8_t status;
  citrack_ros_msgs__action__DarknetCheckForObjects_Result result;
} citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.h"

/// Struct defined in action/DarknetCheckForObjects in the package citrack_ros_msgs.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback feedback;
} citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage;

// Struct for a sequence of citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage.
typedef struct citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence
{
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__STRUCT_H_
