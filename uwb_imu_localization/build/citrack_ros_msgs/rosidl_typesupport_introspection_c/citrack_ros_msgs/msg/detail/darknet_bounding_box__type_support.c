// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__rosidl_typesupport_introspection_c.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__functions.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.h"


// Include directives for member types
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  citrack_ros_msgs__msg__DarknetBoundingBox__init(message_memory);
}

void citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_fini_function(void * message_memory)
{
  citrack_ros_msgs__msg__DarknetBoundingBox__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_member_array[7] = {
  {
    "probability",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, probability),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, xmin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, ymin),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "xmax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, xmax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ymax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, ymax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "class_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBox, class_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_members = {
  "citrack_ros_msgs__msg",  // message namespace
  "DarknetBoundingBox",  // message name
  7,  // number of fields
  sizeof(citrack_ros_msgs__msg__DarknetBoundingBox),
  citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_member_array,  // message members
  citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_init_function,  // function to initialize message memory (memory has to be allocated)
  citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_type_support_handle = {
  0,
  &citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, DarknetBoundingBox)() {
  if (!citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_type_support_handle.typesupport_identifier) {
    citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &citrack_ros_msgs__msg__DarknetBoundingBox__rosidl_typesupport_introspection_c__DarknetBoundingBox_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
