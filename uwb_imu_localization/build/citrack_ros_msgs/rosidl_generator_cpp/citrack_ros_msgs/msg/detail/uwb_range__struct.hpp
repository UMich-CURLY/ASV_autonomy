// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/UwbRange.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__UwbRange __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__UwbRange __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UwbRange_
{
  using Type = UwbRange_<ContainerAllocator>;

  explicit UwbRange_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->anc_id = "";
      this->range = 0.0;
    }
  }

  explicit UwbRange_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    tag_id(_alloc),
    anc_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->anc_id = "";
      this->range = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tag_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tag_id_type tag_id;
  using _anc_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _anc_id_type anc_id;
  using _range_type =
    double;
  _range_type range;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tag_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tag_id = _arg;
    return *this;
  }
  Type & set__anc_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->anc_id = _arg;
    return *this;
  }
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbRange
    std::shared_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbRange
    std::shared_ptr<citrack_ros_msgs::msg::UwbRange_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UwbRange_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tag_id != other.tag_id) {
      return false;
    }
    if (this->anc_id != other.anc_id) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    return true;
  }
  bool operator!=(const UwbRange_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UwbRange_

// alias to use template instance with default allocator
using UwbRange =
  citrack_ros_msgs::msg::UwbRange_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_RANGE__STRUCT_HPP_
