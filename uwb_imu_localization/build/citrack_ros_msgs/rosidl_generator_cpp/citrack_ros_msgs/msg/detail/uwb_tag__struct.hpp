// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/UwbTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__UwbTag __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__UwbTag __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UwbTag_
{
  using Type = UwbTag_<ContainerAllocator>;

  explicit UwbTag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit UwbTag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbTag
    std::shared_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__UwbTag
    std::shared_ptr<citrack_ros_msgs::msg::UwbTag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UwbTag_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const UwbTag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UwbTag_

// alias to use template instance with default allocator
using UwbTag =
  citrack_ros_msgs::msg::UwbTag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAG__STRUCT_HPP_
