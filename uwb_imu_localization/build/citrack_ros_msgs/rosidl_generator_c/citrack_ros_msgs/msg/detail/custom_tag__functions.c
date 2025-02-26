// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/custom_tag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
citrack_ros_msgs__msg__CustomTag__init(citrack_ros_msgs__msg__CustomTag * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    citrack_ros_msgs__msg__CustomTag__fini(msg);
    return false;
  }
  // pose_x
  // pose_y
  // pose_z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
  return true;
}

void
citrack_ros_msgs__msg__CustomTag__fini(citrack_ros_msgs__msg__CustomTag * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pose_x
  // pose_y
  // pose_z
  // orientation_x
  // orientation_y
  // orientation_z
  // orientation_w
}

bool
citrack_ros_msgs__msg__CustomTag__are_equal(const citrack_ros_msgs__msg__CustomTag * lhs, const citrack_ros_msgs__msg__CustomTag * rhs)
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
  // pose_x
  if (lhs->pose_x != rhs->pose_x) {
    return false;
  }
  // pose_y
  if (lhs->pose_y != rhs->pose_y) {
    return false;
  }
  // pose_z
  if (lhs->pose_z != rhs->pose_z) {
    return false;
  }
  // orientation_x
  if (lhs->orientation_x != rhs->orientation_x) {
    return false;
  }
  // orientation_y
  if (lhs->orientation_y != rhs->orientation_y) {
    return false;
  }
  // orientation_z
  if (lhs->orientation_z != rhs->orientation_z) {
    return false;
  }
  // orientation_w
  if (lhs->orientation_w != rhs->orientation_w) {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__msg__CustomTag__copy(
  const citrack_ros_msgs__msg__CustomTag * input,
  citrack_ros_msgs__msg__CustomTag * output)
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
  // pose_x
  output->pose_x = input->pose_x;
  // pose_y
  output->pose_y = input->pose_y;
  // pose_z
  output->pose_z = input->pose_z;
  // orientation_x
  output->orientation_x = input->orientation_x;
  // orientation_y
  output->orientation_y = input->orientation_y;
  // orientation_z
  output->orientation_z = input->orientation_z;
  // orientation_w
  output->orientation_w = input->orientation_w;
  return true;
}

citrack_ros_msgs__msg__CustomTag *
citrack_ros_msgs__msg__CustomTag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__CustomTag * msg = (citrack_ros_msgs__msg__CustomTag *)allocator.allocate(sizeof(citrack_ros_msgs__msg__CustomTag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__msg__CustomTag));
  bool success = citrack_ros_msgs__msg__CustomTag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__msg__CustomTag__destroy(citrack_ros_msgs__msg__CustomTag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__msg__CustomTag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__msg__CustomTag__Sequence__init(citrack_ros_msgs__msg__CustomTag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__CustomTag * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__msg__CustomTag *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__msg__CustomTag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__msg__CustomTag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__msg__CustomTag__fini(&data[i - 1]);
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
citrack_ros_msgs__msg__CustomTag__Sequence__fini(citrack_ros_msgs__msg__CustomTag__Sequence * array)
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
      citrack_ros_msgs__msg__CustomTag__fini(&array->data[i]);
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

citrack_ros_msgs__msg__CustomTag__Sequence *
citrack_ros_msgs__msg__CustomTag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__CustomTag__Sequence * array = (citrack_ros_msgs__msg__CustomTag__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__msg__CustomTag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__msg__CustomTag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__msg__CustomTag__Sequence__destroy(citrack_ros_msgs__msg__CustomTag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__msg__CustomTag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__msg__CustomTag__Sequence__are_equal(const citrack_ros_msgs__msg__CustomTag__Sequence * lhs, const citrack_ros_msgs__msg__CustomTag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__msg__CustomTag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__msg__CustomTag__Sequence__copy(
  const citrack_ros_msgs__msg__CustomTag__Sequence * input,
  citrack_ros_msgs__msg__CustomTag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__msg__CustomTag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__msg__CustomTag * data =
      (citrack_ros_msgs__msg__CustomTag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__msg__CustomTag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__msg__CustomTag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__msg__CustomTag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
