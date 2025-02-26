// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__rosidl_typesupport_fastrtps_cpp.hpp"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace citrack_ros_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_citrack_ros_msgs
cdr_serialize(
  const citrack_ros_msgs::msg::DarknetBoundingBox & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: probability
  cdr << ros_message.probability;
  // Member: xmin
  cdr << ros_message.xmin;
  // Member: ymin
  cdr << ros_message.ymin;
  // Member: xmax
  cdr << ros_message.xmax;
  // Member: ymax
  cdr << ros_message.ymax;
  // Member: id
  cdr << ros_message.id;
  // Member: class_name
  cdr << ros_message.class_name;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_citrack_ros_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  citrack_ros_msgs::msg::DarknetBoundingBox & ros_message)
{
  // Member: probability
  cdr >> ros_message.probability;

  // Member: xmin
  cdr >> ros_message.xmin;

  // Member: ymin
  cdr >> ros_message.ymin;

  // Member: xmax
  cdr >> ros_message.xmax;

  // Member: ymax
  cdr >> ros_message.ymax;

  // Member: id
  cdr >> ros_message.id;

  // Member: class_name
  cdr >> ros_message.class_name;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_citrack_ros_msgs
get_serialized_size(
  const citrack_ros_msgs::msg::DarknetBoundingBox & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: probability
  {
    size_t item_size = sizeof(ros_message.probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xmin
  {
    size_t item_size = sizeof(ros_message.xmin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymin
  {
    size_t item_size = sizeof(ros_message.ymin);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: xmax
  {
    size_t item_size = sizeof(ros_message.xmax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ymax
  {
    size_t item_size = sizeof(ros_message.ymax);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: class_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.class_name.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_citrack_ros_msgs
max_serialized_size_DarknetBoundingBox(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: probability
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: xmin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ymin
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: xmax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ymax
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: class_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = citrack_ros_msgs::msg::DarknetBoundingBox;
    is_plain =
      (
      offsetof(DataType, class_name) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DarknetBoundingBox__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const citrack_ros_msgs::msg::DarknetBoundingBox *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DarknetBoundingBox__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<citrack_ros_msgs::msg::DarknetBoundingBox *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DarknetBoundingBox__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const citrack_ros_msgs::msg::DarknetBoundingBox *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DarknetBoundingBox__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DarknetBoundingBox(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DarknetBoundingBox__callbacks = {
  "citrack_ros_msgs::msg",
  "DarknetBoundingBox",
  _DarknetBoundingBox__cdr_serialize,
  _DarknetBoundingBox__cdr_deserialize,
  _DarknetBoundingBox__get_serialized_size,
  _DarknetBoundingBox__max_serialized_size
};

static rosidl_message_type_support_t _DarknetBoundingBox__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DarknetBoundingBox__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_citrack_ros_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::msg::DarknetBoundingBox>()
{
  return &citrack_ros_msgs::msg::typesupport_fastrtps_cpp::_DarknetBoundingBox__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, msg, DarknetBoundingBox)() {
  return &citrack_ros_msgs::msg::typesupport_fastrtps_cpp::_DarknetBoundingBox__handle;
}

#ifdef __cplusplus
}
#endif
