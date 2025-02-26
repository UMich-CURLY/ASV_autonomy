// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_Goal(_init);
}

void DarknetCheckForObjects_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_Goal *>(message_memory);
  typed_message->~DarknetCheckForObjects_Goal();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_Goal_message_member_array[2] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_Goal, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_Goal, image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_Goal_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_Goal",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_Goal),
  DarknetCheckForObjects_Goal_message_member_array,  // message members
  DarknetCheckForObjects_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_Goal_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Goal>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Goal)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_Result(_init);
}

void DarknetCheckForObjects_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_Result *>(message_memory);
  typed_message->~DarknetCheckForObjects_Result();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_Result_message_member_array[2] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_Result, id),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::msg::DarknetBoundingBoxes>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_Result, bounding_boxes),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_Result_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_Result",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_Result),
  DarknetCheckForObjects_Result_message_member_array,  // message members
  DarknetCheckForObjects_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_Result_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Result>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Result)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_Feedback(_init);
}

void DarknetCheckForObjects_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_Feedback *>(message_memory);
  typed_message->~DarknetCheckForObjects_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_Feedback_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_Feedback, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_Feedback_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_Feedback",  // message name
  1,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_Feedback),
  DarknetCheckForObjects_Feedback_message_member_array,  // message members
  DarknetCheckForObjects_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_Feedback_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Feedback>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Feedback)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request(_init);
}

void DarknetCheckForObjects_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request *>(message_memory);
  typed_message->~DarknetCheckForObjects_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Goal>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_SendGoal_Request_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request),
  DarknetCheckForObjects_SendGoal_Request_message_member_array,  // message members
  DarknetCheckForObjects_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Request)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response(_init);
}

void DarknetCheckForObjects_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response *>(message_memory);
  typed_message->~DarknetCheckForObjects_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response, accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_SendGoal_Response_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response),
  DarknetCheckForObjects_SendGoal_Response_message_member_array,  // message members
  DarknetCheckForObjects_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Response)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DarknetCheckForObjects_SendGoal_service_members = {
  "citrack_ros_msgs::action",  // service namespace
  "DarknetCheckForObjects_SendGoal",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DarknetCheckForObjects_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_SendGoal_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request(_init);
}

void DarknetCheckForObjects_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request *>(message_memory);
  typed_message->~DarknetCheckForObjects_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_GetResult_Request_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request),
  DarknetCheckForObjects_GetResult_Request_message_member_array,  // message members
  DarknetCheckForObjects_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Request)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response(_init);
}

void DarknetCheckForObjects_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response *>(message_memory);
  typed_message->~DarknetCheckForObjects_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Result>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_GetResult_Response_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response),
  DarknetCheckForObjects_GetResult_Response_message_member_array,  // message members
  DarknetCheckForObjects_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Response)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DarknetCheckForObjects_GetResult_service_members = {
  "citrack_ros_msgs::action",  // service namespace
  "DarknetCheckForObjects_GetResult",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DarknetCheckForObjects_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_GetResult_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_GetResult_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void DarknetCheckForObjects_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage(_init);
}

void DarknetCheckForObjects_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage *>(message_memory);
  typed_message->~DarknetCheckForObjects_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DarknetCheckForObjects_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Feedback>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DarknetCheckForObjects_FeedbackMessage_message_members = {
  "citrack_ros_msgs::action",  // message namespace
  "DarknetCheckForObjects_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage),
  DarknetCheckForObjects_FeedbackMessage_message_member_array,  // message members
  DarknetCheckForObjects_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  DarknetCheckForObjects_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DarknetCheckForObjects_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DarknetCheckForObjects_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace citrack_ros_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_FeedbackMessage)() {
  return &::citrack_ros_msgs::action::rosidl_typesupport_introspection_cpp::DarknetCheckForObjects_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
