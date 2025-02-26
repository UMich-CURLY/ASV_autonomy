// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBoxes.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_HPP_
#define CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
// Member 'image_header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'bounding_boxes'
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__citrack_ros_msgs__msg__DarknetBoundingBoxes __attribute__((deprecated))
#else
# define DEPRECATED__citrack_ros_msgs__msg__DarknetBoundingBoxes __declspec(deprecated)
#endif

namespace citrack_ros_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DarknetBoundingBoxes_
{
  using Type = DarknetBoundingBoxes_<ContainerAllocator>;

  explicit DarknetBoundingBoxes_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    image_header(_init)
  {
    (void)_init;
  }

  explicit DarknetBoundingBoxes_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    image_header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _image_header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _image_header_type image_header;
  using _bounding_boxes_type =
    std::vector<citrack_ros_msgs::msg::DarknetBoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::DarknetBoundingBox_<ContainerAllocator>>>;
  _bounding_boxes_type bounding_boxes;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__image_header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->image_header = _arg;
    return *this;
  }
  Type & set__bounding_boxes(
    const std::vector<citrack_ros_msgs::msg::DarknetBoundingBox_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<citrack_ros_msgs::msg::DarknetBoundingBox_<ContainerAllocator>>> & _arg)
  {
    this->bounding_boxes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> *;
  using ConstRawPtr =
    const citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__citrack_ros_msgs__msg__DarknetBoundingBoxes
    std::shared_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__citrack_ros_msgs__msg__DarknetBoundingBoxes
    std::shared_ptr<citrack_ros_msgs::msg::DarknetBoundingBoxes_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DarknetBoundingBoxes_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->image_header != other.image_header) {
      return false;
    }
    if (this->bounding_boxes != other.bounding_boxes) {
      return false;
    }
    return true;
  }
  bool operator!=(const DarknetBoundingBoxes_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DarknetBoundingBoxes_

// alias to use template instance with default allocator
using DarknetBoundingBoxes =
  citrack_ros_msgs::msg::DarknetBoundingBoxes_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__DARKNET_BOUNDING_BOXES__STRUCT_HPP_
