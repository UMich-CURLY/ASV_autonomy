// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/RvizBirdsEyeParam.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_HPP_

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
// Member 'offset'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__RvizBirdsEyeParam __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__RvizBirdsEyeParam __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RvizBirdsEyeParam_
{
  using Type = RvizBirdsEyeParam_<ContainerAllocator>;

  explicit RvizBirdsEyeParam_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    offset(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0l;
      this->width = 0l;
      this->resolution = 0.0;
    }
  }

  explicit RvizBirdsEyeParam_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    offset(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->height = 0l;
      this->width = 0l;
      this->resolution = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _height_type =
    int32_t;
  _height_type height;
  using _width_type =
    int32_t;
  _width_type width;
  using _offset_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _offset_type offset;
  using _resolution_type =
    double;
  _resolution_type resolution;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__width(
    const int32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__offset(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->offset = _arg;
    return *this;
  }
  Type & set__resolution(
    const double & _arg)
  {
    this->resolution = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__RvizBirdsEyeParam
    std::shared_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__RvizBirdsEyeParam
    std::shared_ptr<citrack_ros_msgs::msg::RvizBirdsEyeParam_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RvizBirdsEyeParam_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->offset != other.offset) {
      return false;
    }
    if (this->resolution != other.resolution) {
      return false;
    }
    return true;
  }
  bool operator!=(const RvizBirdsEyeParam_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RvizBirdsEyeParam_

// alias to use template instance with default allocator
using RvizBirdsEyeParam =
  citrack_ros_msgs::msg::RvizBirdsEyeParam_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__RVIZ_BIRDS_EYE_PARAM__STRUCT_HPP_
