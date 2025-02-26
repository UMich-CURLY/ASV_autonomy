// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__rosidl_typesupport_introspection_c.h"
#include "citrack_ros_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__functions.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__struct.h"


// Include directives for member types
// Member `header`
// Member `image_header`
#include "std_msgs/msg/header.h"
// Member `header`
// Member `image_header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `bounding_boxes`
#include "citrack_ros_msgs/msg/darknet_bounding_box.h"
// Member `bounding_boxes`
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  citrack_ros_msgs__msg__DarknetBoundingBoxes__init(message_memory);
}

void citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_fini_function(void * message_memory)
{
  citrack_ros_msgs__msg__DarknetBoundingBoxes__fini(message_memory);
}

size_t citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__size_function__DarknetBoundingBoxes__bounding_boxes(
  const void * untyped_member)
{
  const citrack_ros_msgs__msg__DarknetBoundingBox__Sequence * member =
    (const citrack_ros_msgs__msg__DarknetBoundingBox__Sequence *)(untyped_member);
  return member->size;
}

const void * citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_const_function__DarknetBoundingBoxes__bounding_boxes(
  const void * untyped_member, size_t index)
{
  const citrack_ros_msgs__msg__DarknetBoundingBox__Sequence * member =
    (const citrack_ros_msgs__msg__DarknetBoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void * citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_function__DarknetBoundingBoxes__bounding_boxes(
  void * untyped_member, size_t index)
{
  citrack_ros_msgs__msg__DarknetBoundingBox__Sequence * member =
    (citrack_ros_msgs__msg__DarknetBoundingBox__Sequence *)(untyped_member);
  return &member->data[index];
}

void citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__fetch_function__DarknetBoundingBoxes__bounding_boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const citrack_ros_msgs__msg__DarknetBoundingBox * item =
    ((const citrack_ros_msgs__msg__DarknetBoundingBox *)
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_const_function__DarknetBoundingBoxes__bounding_boxes(untyped_member, index));
  citrack_ros_msgs__msg__DarknetBoundingBox * value =
    (citrack_ros_msgs__msg__DarknetBoundingBox *)(untyped_value);
  *value = *item;
}

void citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__assign_function__DarknetBoundingBoxes__bounding_boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  citrack_ros_msgs__msg__DarknetBoundingBox * item =
    ((citrack_ros_msgs__msg__DarknetBoundingBox *)
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_function__DarknetBoundingBoxes__bounding_boxes(untyped_member, index));
  const citrack_ros_msgs__msg__DarknetBoundingBox * value =
    (const citrack_ros_msgs__msg__DarknetBoundingBox *)(untyped_value);
  *item = *value;
}

bool citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__resize_function__DarknetBoundingBoxes__bounding_boxes(
  void * untyped_member, size_t size)
{
  citrack_ros_msgs__msg__DarknetBoundingBox__Sequence * member =
    (citrack_ros_msgs__msg__DarknetBoundingBox__Sequence *)(untyped_member);
  citrack_ros_msgs__msg__DarknetBoundingBox__Sequence__fini(member);
  return citrack_ros_msgs__msg__DarknetBoundingBox__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBoxes, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "image_header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBoxes, image_header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bounding_boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs__msg__DarknetBoundingBoxes, bounding_boxes),  // bytes offset in struct
    NULL,  // default value
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__size_function__DarknetBoundingBoxes__bounding_boxes,  // size() function pointer
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_const_function__DarknetBoundingBoxes__bounding_boxes,  // get_const(index) function pointer
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__get_function__DarknetBoundingBoxes__bounding_boxes,  // get(index) function pointer
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__fetch_function__DarknetBoundingBoxes__bounding_boxes,  // fetch(index, &value) function pointer
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__assign_function__DarknetBoundingBoxes__bounding_boxes,  // assign(index, value) function pointer
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__resize_function__DarknetBoundingBoxes__bounding_boxes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_members = {
  "citrack_ros_msgs__msg",  // message namespace
  "DarknetBoundingBoxes",  // message name
  3,  // number of fields
  sizeof(citrack_ros_msgs__msg__DarknetBoundingBoxes),
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_member_array,  // message members
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_init_function,  // function to initialize message memory (memory has to be allocated)
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_type_support_handle = {
  0,
  &citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, DarknetBoundingBoxes)() {
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, citrack_ros_msgs, msg, DarknetBoundingBox)();
  if (!citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_type_support_handle.typesupport_identifier) {
    citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &citrack_ros_msgs__msg__DarknetBoundingBoxes__rosidl_typesupport_introspection_c__DarknetBoundingBoxes_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
