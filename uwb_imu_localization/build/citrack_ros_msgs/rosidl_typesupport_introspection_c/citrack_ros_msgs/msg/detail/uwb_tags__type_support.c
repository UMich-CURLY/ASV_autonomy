// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from citrack_ros_msgs:msg/UwbTags.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "citrack_ros_msgs/msg/detail/uwb_tags__rosidl_typesupport_introspection_c.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "citrack_ros_msgs/msg/detail/uwb_tags__functions.h"
#include "citrack_ros_msgs/msg/detail/uwb_tags__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `tags`
#include "citrack_ros_msgs/msg/uwb_tag.h"
// Member `tags`
#include "citrack_ros_msgs/msg/detail/uwb_tag__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  citrack_ros_msgs__msg__UwbTags__init(message_memory);
}

void citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_fini_function(void * message_memory)
{
  citrack_ros_msgs__msg__UwbTags__fini(message_memory);
}

size_t citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__size_function__UwbTags__tags(
  const void * untyped_member)
{
  const citrack_ros_msgs__msg__UwbTag__Sequence * member =
    (const citrack_ros_msgs__msg__UwbTag__Sequence *)(untyped_member);
  return member->size;
}

const void * citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_const_function__UwbTags__tags(
  const void * untyped_member, size_t index)
{
  const citrack_ros_msgs__msg__UwbTag__Sequence * member =
    (const citrack_ros_msgs__msg__UwbTag__Sequence *)(untyped_member);
  return &member->data[index];
}

void * citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_function__UwbTags__tags(
  void * untyped_member, size_t index)
{
  citrack_ros_msgs__msg__UwbTag__Sequence * member =
    (citrack_ros_msgs__msg__UwbTag__Sequence *)(untyped_member);
  return &member->data[index];
}

void citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__fetch_function__UwbTags__tags(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const citrack_ros_msgs__msg__UwbTag * item =
    ((const citrack_ros_msgs__msg__UwbTag *)
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_const_function__UwbTags__tags(untyped_member, index));
  citrack_ros_msgs__msg__UwbTag * value =
    (citrack_ros_msgs__msg__UwbTag *)(untyped_value);
  *value = *item;
}

void citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__assign_function__UwbTags__tags(
  void * untyped_member, size_t index, const void * untyped_value)
{
  citrack_ros_msgs__msg__UwbTag * item =
    ((citrack_ros_msgs__msg__UwbTag *)
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_function__UwbTags__tags(untyped_member, index));
  const citrack_ros_msgs__msg__UwbTag * value =
    (const citrack_ros_msgs__msg__UwbTag *)(untyped_value);
  *item = *value;
}

bool citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__resize_function__UwbTags__tags(
  void * untyped_member, size_t size)
{
  citrack_ros_msgs__msg__UwbTag__Sequence * member =
    (citrack_ros_msgs__msg__UwbTag__Sequence *)(untyped_member);
  citrack_ros_msgs__msg__UwbTag__Sequence__fini(member);
  return citrack_ros_msgs__msg__UwbTag__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbTags, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tags",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__UwbTags, tags),  // bytes offset in struct
    NULL,  // default value
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__size_function__UwbTags__tags,  // size() function pointer
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_const_function__UwbTags__tags,  // get_const(index) function pointer
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__get_function__UwbTags__tags,  // get(index) function pointer
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__fetch_function__UwbTags__tags,  // fetch(index, &value) function pointer
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__assign_function__UwbTags__tags,  // assign(index, value) function pointer
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__resize_function__UwbTags__tags  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_members = {
  "citrack_ros_msgs__msg",  // message namespace
  "UwbTags",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs__msg__UwbTags),
  citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_member_array,  // message members
  citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_init_function,  // function to initialize message memory (memory has to be allocated)
  citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_type_support_handle = {
  0,
  &citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, UwbTags)() {
  citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, UwbTag)();
  if (!citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_type_support_handle.typesupport_identifier) {
    citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &citrack_ros_msgs__msg__UwbTags__rosidl_typesupport_introspection_c__UwbTags_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
