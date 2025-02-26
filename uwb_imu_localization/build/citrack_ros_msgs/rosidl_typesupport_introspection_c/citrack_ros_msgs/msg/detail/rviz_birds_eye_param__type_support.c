// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from citrack_ros_msgs:msg/RvizBirdsEyeParam.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "citrack_ros_msgs/msg/detail/rviz_birds_eye_param__rosidl_typesupport_introspection_c.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "citrack_ros_msgs/msg/detail/rviz_birds_eye_param__functions.h"
#include "citrack_ros_msgs/msg/detail/rviz_birds_eye_param__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `offset`
#include "geometry_msgs/msg/point.h"
// Member `offset`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  citrack_ros_msgs__msg__RvizBirdsEyeParam__init(message_memory);
}

void citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_fini_function(void * message_memory)
{
  citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__RvizBirdsEyeParam, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__RvizBirdsEyeParam, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__RvizBirdsEyeParam, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__RvizBirdsEyeParam, offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__RvizBirdsEyeParam, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_members = {
  "citrack_ros_msgs__msg",  // message namespace
  "RvizBirdsEyeParam",  // message name
  5,  // number of fields
  sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam),
  citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_member_array,  // message members
  citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_init_function,  // function to initialize message memory (memory has to be allocated)
  citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_type_support_handle = {
  0,
  &citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, RvizBirdsEyeParam)() {
  citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_type_support_handle.typesupport_identifier) {
    citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &citrack_ros_msgs__msg__RvizBirdsEyeParam__rosidl_typesupport_introspection_c__RvizBirdsEyeParam_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
