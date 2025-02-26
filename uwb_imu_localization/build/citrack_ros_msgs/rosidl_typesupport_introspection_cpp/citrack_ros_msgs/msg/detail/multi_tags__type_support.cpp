// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:msg/MultiTags.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "citrack_ros_msgs/msg/detail/multi_tags__struct.hpp"
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

void MultiTags_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::msg::MultiTags(_init);
}

void MultiTags_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::msg::MultiTags *>(message_memory);
  typed_message->~MultiTags();
}

size_t size_function__MultiTags__tags_list(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<citrack_ros_msgs::msg::CustomTag> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MultiTags__tags_list(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<citrack_ros_msgs::msg::CustomTag> *>(untyped_member);
  return &member[index];
}

void * get_function__MultiTags__tags_list(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<citrack_ros_msgs::msg::CustomTag> *>(untyped_member);
  return &member[index];
}

void fetch_function__MultiTags__tags_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const citrack_ros_msgs::msg::CustomTag *>(
    get_const_function__MultiTags__tags_list(untyped_member, index));
  auto & value = *reinterpret_cast<citrack_ros_msgs::msg::CustomTag *>(untyped_value);
  value = item;
}

void assign_function__MultiTags__tags_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<citrack_ros_msgs::msg::CustomTag *>(
    get_function__MultiTags__tags_list(untyped_member, index));
  const auto & value = *reinterpret_cast<const citrack_ros_msgs::msg::CustomTag *>(untyped_value);
  item = value;
}

void resize_function__MultiTags__tags_list(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<citrack_ros_msgs::msg::CustomTag> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MultiTags_message_member_array[1] = {
  {
    "tags_list",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::msg::CustomTag>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::msg::MultiTags, tags_list),  // bytes offset in struct
    nullptr,  // default value
    size_function__MultiTags__tags_list,  // size() function pointer
    get_const_function__MultiTags__tags_list,  // get_const(index) function pointer
    get_function__MultiTags__tags_list,  // get(index) function pointer
    fetch_function__MultiTags__tags_list,  // fetch(index, &value) function pointer
    assign_function__MultiTags__tags_list,  // assign(index, value) function pointer
    resize_function__MultiTags__tags_list  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MultiTags_message_members = {
  "citrack_ros_msgs::msg",  // message namespace
  "MultiTags",  // message name
  1,  // number of fields
  sizeof(citrack_ros_msgs::msg::MultiTags),
  MultiTags_message_member_array,  // message members
  MultiTags_init_function,  // function to initialize message memory (memory has to be allocated)
  MultiTags_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MultiTags_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MultiTags_message_members,
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
get_message_type_support_handle<citrack_ros_msgs::msg::MultiTags>()
{
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::MultiTags_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, msg, MultiTags)() {
  return &::citrack_ros_msgs::msg::rosidl_typesupport_introspection_cpp::MultiTags_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
