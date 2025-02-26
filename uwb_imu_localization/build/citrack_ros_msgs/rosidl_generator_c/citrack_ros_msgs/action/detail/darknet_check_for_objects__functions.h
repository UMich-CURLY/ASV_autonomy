// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__FUNCTIONS_H_
#define CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "citrack_ros_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.h"

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Goal *
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Result *
citrack_ros_msgs__action__DarknetCheckForObjects_Result__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Result * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Result * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Result__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Result * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Result * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback *
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * output);

/// Initialize action/DarknetCheckForObjects message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage
 * )) before or use
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg);

/// Finalize action/DarknetCheckForObjects message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg);

/// Create action/DarknetCheckForObjects message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage *
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__create();

/// Destroy action/DarknetCheckForObjects message.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg);

/// Check for action/DarknetCheckForObjects message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * rhs);

/// Copy a action/DarknetCheckForObjects message.
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
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * output);

/// Initialize array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the number of elements and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array);

/// Create array of action/DarknetCheckForObjects messages.
/**
 * It allocates the memory for the array and calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/DarknetCheckForObjects messages.
/**
 * It calls
 * citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array);

/// Check for action/DarknetCheckForObjects message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_citrack_ros_msgs
bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/DarknetCheckForObjects messages.
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
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__FUNCTIONS_H_
