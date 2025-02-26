// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from citrack_ros_msgs:msg/UwbTags.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__FUNCTIONS_H_
#define CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "citrack_ros_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "citrack_ros_msgs/msg/detail/uwb_tags__struct.h"

/// Initialize msg/UwbTags message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__msg__UwbTags
 * )) before or use
 * citrack_ros_msgs__msg__UwbTags__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__init(citrack_ros_msgs__msg__UwbTags * msg);

/// Finalize msg/UwbTags message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__msg__UwbTags__fini(citrack_ros_msgs__msg__UwbTags * msg);

/// Create msg/UwbTags message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__msg__UwbTags__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__msg__UwbTags *
citrack_ros_msgs__msg__UwbTags__create();

/// Destroy msg/UwbTags message.
/**
 * It calls
 * citrack_ros_msgs__msg__UwbTags__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__msg__UwbTags__destroy(citrack_ros_msgs__msg__UwbTags * msg);

/// Check for msg/UwbTags message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__are_equal(const citrack_ros_msgs__msg__UwbTags * lhs, const citrack_ros_msgs__msg__UwbTags * rhs);

/// Copy a msg/UwbTags message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__copy(
  const citrack_ros_msgs__msg__UwbTags * input,
  citrack_ros_msgs__msg__UwbTags * output);

/// Initialize array of msg/UwbTags messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__msg__UwbTags__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__Sequence__init(citrack_ros_msgs__msg__UwbTags__Sequence * array, size_t size);

/// Finalize array of msg/UwbTags messages.
/**
 * It calls
 * citrack_ros_msgs__msg__UwbTags__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__msg__UwbTags__Sequence__fini(citrack_ros_msgs__msg__UwbTags__Sequence * array);

/// Create array of msg/UwbTags messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__msg__UwbTags__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__msg__UwbTags__Sequence *
citrack_ros_msgs__msg__UwbTags__Sequence__create(size_t size);

/// Destroy array of msg/UwbTags messages.
/**
 * It calls
 * citrack_ros_msgs__msg__UwbTags__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__msg__UwbTags__Sequence__destroy(citrack_ros_msgs__msg__UwbTags__Sequence * array);

/// Check for msg/UwbTags message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__Sequence__are_equal(const citrack_ros_msgs__msg__UwbTags__Sequence * lhs, const citrack_ros_msgs__msg__UwbTags__Sequence * rhs);

/// Copy an array of msg/UwbTags messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__msg__UwbTags__Sequence__copy(
  const citrack_ros_msgs__msg__UwbTags__Sequence * input,
  citrack_ros_msgs__msg__UwbTags__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__MSG__DETAIL__UWB_TAGS__FUNCTIONS_H_
