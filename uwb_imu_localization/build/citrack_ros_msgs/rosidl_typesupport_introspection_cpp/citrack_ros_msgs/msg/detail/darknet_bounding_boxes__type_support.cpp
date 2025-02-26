// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__struct.hpp"
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

void DarknetBoundingBoxes_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::msg::DarknetBoundingBoxes(_init);
}

void DarknetBoundingBoxes_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::msg::DarknetBoundingBoxes *>(message_memory);
  typed_message->~DarknetBoundingBoxes();
}

size_t size_function__DarknetBoundingBoxes__bounding_boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<citrack_ros_msgs::msg::DarknetBoundingBox> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DarknetBoundingBoxes__bounding_boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<citrack_ros_msgs::msg::DarknetBoundingBox> *>(untyped_member);
  return &member[index];
}

void * get_function__DarknetBoundingBoxes__bounding_boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<citrack_ros_msgs::msg::DarknetBoundingBox> *>(untyped_member);
  return &member[index];
}

void fetch_function__DarknetBoundingBoxes__bounding_boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const citrack_ros_msgs::msg::DarknetBoundingBox *>(
    get_const_function__DarknetBoundingBoxes__bounding_boxes(untyped_member, index));
  auto & value = *reinterpret_cast<citrack_ros_msgs::msg::DarknetBoundingBox *>(untyped_value);
  value = item;
}

void assign_function__DarknetBoundingBoxes__bounding_boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<citrack_ros_msgs::msg::DarknetBoundingBox *>(
    get_function__DarknetBoundingBoxes__bounding_boxes(untyped_member, index));
  const auto & value = *reinterpret_cast<const citrack_ros_msgs::msg::DarknetBoundingBox *>(untyped_value);
  item = value;
}

void resize_function__DarknetBoundingBoxes__bounding_boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<citrack_ros_msgs::msg::DarknetBoundingBox> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetBoundingBoxes_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::DarknetBoundingBoxes, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image_header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::DarknetBoundingBoxes, image_header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "bounding_boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::msg::DarknetBoundingBox>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::DarknetBoundingBoxes, bounding_boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__DarknetBoundingBoxes__bounding_boxes,  // size() function pointer
    get_const_function__DarknetBoundingBoxes__bounding_boxes,  // get_const(index) function pointer
    get_function__DarknetBoundingBoxes__bounding_boxes,  // get(index) function pointer
    fetch_function__DarknetBoundingBoxes__bounding_boxes,  // fetch(index, &value) function pointer
    assign_function__DarknetBoundingBoxes__bounding_boxes,  // assign(index, value) function pointer
    resize_function__DarknetBoundingBoxes__bounding_boxes  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetBoundingBoxes_message_members = {
  "citrack_ros_msgs::msg",  // message namespace
  "DarknetBoundingBoxes",  // message name
  3,  // number of fields
  sizeof(citrack_ros_msgs::msg::DarknetBoundingBoxes),
  DarknetBoundingBoxes_message_member_array,  // message members
  DarknetBoundingBoxes_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetBoundingBoxes_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetBoundingBoxes_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetBoundingBoxes_message_members,
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
get_message_type_support_handle<citrack_ros_msgs::msg::DarknetBoundingBoxes>()
{
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::DarknetBoundingBoxes_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, msg, DarknetBoundingBoxes)() {
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::DarknetBoundingBoxes_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
