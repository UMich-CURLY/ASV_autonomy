// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from citrack_ros_msgs:msg/UwbRange.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "citrack_ros_msgs/msg/detail/uwb_range__rosidl_typesupport_introspection_c.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "citrack_ros_msgs/msg/detail/uwb_range__functions.h"
#include "citrack_ros_msgs/msg/detail/uwb_range__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `tag_id`
// Member `anc_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  citrack_ros_msgs__msg__UwbRange__init(message_memory);
}

void citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_fini_function(void * message_memory)
{
  citrack_ros_msgs__msg__UwbRange__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbRange, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tag_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbRange, tag_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "anc_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbRange, anc_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbRange, range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_members = {
  "citrack_ros_msgs__msg",  // message namespace
  "UwbRange",  // message name
  4,  // number of fields
  sizeof(citrack_ros_msgs__msg__UwbRange),
  citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array,  // message members
  citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_init_function,  // function to initialize message memory (memory has to be allocated)
  citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle = {
  0,
  &citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, UwbRange)() {
  citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle.typesupport_identifier) {
    citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &citrack_ros_msgs__msg__UwbRange__rosidl_typesupport_introspection_c__UwbRange_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
