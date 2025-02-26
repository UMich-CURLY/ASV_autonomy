// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/MultiTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tags_list'
#include "citrack_ros_msgs/msg/detail/custom_tag__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__MultiTags __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__MultiTags __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultiTags_
{
  using Type = MultiTags_<ContainerAllocator>;

  explicit MultiTags_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MultiTags_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _tags_list_type =
    std::vector<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>>;
  _tags_list_type tags_list;

  // setters for named parameter idiom
  Type & set__tags_list(
    const std::vector<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>> & _arg)
  {
    this->tags_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__MultiTags
    std::shared_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__MultiTags
    std::shared_ptr<citrack_ros_msgs::msg::MultiTags_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultiTags_ & other) const
  {
    if (this->tags_list != other.tags_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultiTags_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultiTags_

// alias to use template instance with default allocator
using MultiTags =
  citrack_ros_msgs::msg::MultiTags_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__MULTI_TAGS__STRUCT_HPP_
