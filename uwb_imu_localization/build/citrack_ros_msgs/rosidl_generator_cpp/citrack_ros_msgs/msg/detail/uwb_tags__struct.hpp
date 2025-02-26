// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/UwbTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'tags'
#include "citrack_ros_msgs/msg/detail/uwb_tag__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__UwbTags __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__UwbTags __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UwbTags_
{
  using Type = UwbTags_<ContainerAllocator>;

  explicit UwbTags_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit UwbTags_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tags_type =
    std::vector<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>>;
  _tags_type tags;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tags(
    const std::vector<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>> & _arg)
  {
    this->tags = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbTags
    std::shared_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbTags
    std::shared_ptr<citrack_ros_msgs::msg::UwbTags_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UwbTags_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tags != other.tags) {
      return false;
    }
    return true;
  }
  bool operator!=(const UwbTags_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UwbTags_

// alias to use template instance with default allocator
using UwbTags =
  citrack_ros_msgs::msg::UwbTags_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__STRUCT_HPP_
