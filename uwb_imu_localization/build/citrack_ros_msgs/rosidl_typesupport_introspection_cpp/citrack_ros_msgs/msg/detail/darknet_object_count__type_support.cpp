// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "citrack_ros_msgs/msg/detail/darknet_object_count__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetObjectCount_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::msg::DarknetObjectCount(_init);
}

void DarknetObjectCount_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::msg::DarknetObjectCount *>(message_memory);
  typed_message->~DarknetObjectCount();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetObjectCount_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::DarknetObjectCount, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "count",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::DarknetObjectCount, count),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetObjectCount_message_members = {
  "citrack_ros_msgs::msg",  // message namespace
  "DarknetObjectCount",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::msg::DarknetObjectCount),
  DarknetObjectCount_message_member_array,  // message members
  DarknetObjectCount_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetObjectCount_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetObjectCount_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetObjectCount_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::msg::DarknetObjectCount>()
{
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::DarknetObjectCount_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, msg, DarknetObjectCount)() {
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::DarknetObjectCount_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
