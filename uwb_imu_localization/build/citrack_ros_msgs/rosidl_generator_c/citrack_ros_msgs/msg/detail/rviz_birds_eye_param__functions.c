// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:msg/RvizBirdsEyeParam.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/rviz_birds_eye_param__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `offset`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__init(citrack_ros_msgs__msg__RvizBirdsEyeParam * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(msg);
    return false;
  }
  // height
  // width
  // offset
  if (!geometry_msgs__msg__Point__init(&msg->offset)) {
    citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(msg);
    return false;
  }
  // resolution
  return true;
}

void
citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(citrack_ros_msgs__msg__RvizBirdsEyeParam * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // height
  // width
  // offset
  geometry_msgs__msg__Point__fini(&msg->offset);
  // resolution
}

bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__are_equal(const citrack_ros_msgs__msg__RvizBirdsEyeParam * lhs, const citrack_ros_msgs__msg__RvizBirdsEyeParam * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // offset
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->offset), &(rhs->offset)))
  {
    return false;
  }
  // resolution
  if (lhs->resolution != rhs->resolution) {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__copy(
  const citrack_ros_msgs__msg__RvizBirdsEyeParam * input,
  citrack_ros_msgs__msg__RvizBirdsEyeParam * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // height
  output->height = input->height;
  // width
  output->width = input->width;
  // offset
  if (!geometry_msgs__msg__Point__copy(
      &(input->offset), &(output->offset)))
  {
    return false;
  }
  // resolution
  output->resolution = input->resolution;
  return true;
}

citrack_ros_msgs__msg__RvizBirdsEyeParam *
citrack_ros_msgs__msg__RvizBirdsEyeParam__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__RvizBirdsEyeParam * msg = (citrack_ros_msgs__msg__RvizBirdsEyeParam *)allocator.allocate(sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam));
  bool success = citrack_ros_msgs__msg__RvizBirdsEyeParam__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__msg__RvizBirdsEyeParam__destroy(citrack_ros_msgs__msg__RvizBirdsEyeParam * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__init(citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__RvizBirdsEyeParam * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__msg__RvizBirdsEyeParam *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__msg__RvizBirdsEyeParam__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__fini(citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence *
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * array = (citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__destroy(citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__are_equal(const citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * lhs, const citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__msg__RvizBirdsEyeParam__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence__copy(
  const citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * input,
  citrack_ros_msgs__msg__RvizBirdsEyeParam__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__msg__RvizBirdsEyeParam);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__msg__RvizBirdsEyeParam * data =
      (citrack_ros_msgs__msg__RvizBirdsEyeParam *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__msg__RvizBirdsEyeParam__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__msg__RvizBirdsEyeParam__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__msg__RvizBirdsEyeParam__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
