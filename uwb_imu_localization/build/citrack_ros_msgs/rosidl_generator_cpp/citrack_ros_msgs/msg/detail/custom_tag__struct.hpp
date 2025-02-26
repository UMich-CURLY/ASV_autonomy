// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_HPP_

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
# define DEPRECATED__citrack_ros_msgs__msg__CustomTag __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__CustomTag __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CustomTag_
{
  using Type = CustomTag_<ContainerAllocator>;

  explicit CustomTag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->pose_z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
    }
  }

  explicit CustomTag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->pose_z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pose_x_type =
    double;
  _pose_x_type pose_x;
  using _pose_y_type =
    double;
  _pose_y_type pose_y;
  using _pose_z_type =
    double;
  _pose_z_type pose_z;
  using _orientation_x_type =
    double;
  _orientation_x_type orientation_x;
  using _orientation_y_type =
    double;
  _orientation_y_type orientation_y;
  using _orientation_z_type =
    double;
  _orientation_z_type orientation_z;
  using _orientation_w_type =
    double;
  _orientation_w_type orientation_w;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pose_x(
    const double & _arg)
  {
    this->pose_x = _arg;
    return *this;
  }
  Type & set__pose_y(
    const double & _arg)
  {
    this->pose_y = _arg;
    return *this;
  }
  Type & set__pose_z(
    const double & _arg)
  {
    this->pose_z = _arg;
    return *this;
  }
  Type & set__orientation_x(
    const double & _arg)
  {
    this->orientation_x = _arg;
    return *this;
  }
  Type & set__orientation_y(
    const double & _arg)
  {
    this->orientation_y = _arg;
    return *this;
  }
  Type & set__orientation_z(
    const double & _arg)
  {
    this->orientation_z = _arg;
    return *this;
  }
  Type & set__orientation_w(
    const double & _arg)
  {
    this->orientation_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__CustomTag
    std::shared_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__CustomTag
    std::shared_ptr<citrack_ros_msgs::msg::CustomTag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CustomTag_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pose_x != other.pose_x) {
      return false;
    }
    if (this->pose_y != other.pose_y) {
      return false;
    }
    if (this->pose_z != other.pose_z) {
      return false;
    }
    if (this->orientation_x != other.orientation_x) {
      return false;
    }
    if (this->orientation_y != other.orientation_y) {
      return false;
    }
    if (this->orientation_z != other.orientation_z) {
      return false;
    }
    if (this->orientation_w != other.orientation_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const CustomTag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CustomTag_

// alias to use template instance with default allocator
using CustomTag =
  citrack_ros_msgs::msg::CustomTag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__CUSTOM_TAG__STRUCT_HPP_
