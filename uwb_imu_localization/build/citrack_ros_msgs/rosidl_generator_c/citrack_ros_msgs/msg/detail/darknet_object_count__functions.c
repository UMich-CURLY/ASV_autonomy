// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:msg/DarknetObjectCount.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/darknet_object_count__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
citrack_ros_msgs__msg__DarknetObjectCount__init(citrack_ros_msgs__msg__DarknetObjectCount * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    citrack_ros_msgs__msg__DarknetObjectCount__fini(msg);
    return false;
  }
  // count
  return true;
}

void
citrack_ros_msgs__msg__DarknetObjectCount__fini(citrack_ros_msgs__msg__DarknetObjectCount * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // count
}

bool
citrack_ros_msgs__msg__DarknetObjectCount__are_equal(const citrack_ros_msgs__msg__DarknetObjectCount * lhs, const citrack_ros_msgs__msg__DarknetObjectCount * rhs)
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
  // count
  if (lhs->count != rhs->count) {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__msg__DarknetObjectCount__copy(
  const citrack_ros_msgs__msg__DarknetObjectCount * input,
  citrack_ros_msgs__msg__DarknetObjectCount * output)
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
  // count
  output->count = input->count;
  return true;
}

citrack_ros_msgs__msg__DarknetObjectCount *
citrack_ros_msgs__msg__DarknetObjectCount__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__DarknetObjectCount * msg = (citrack_ros_msgs__msg__DarknetObjectCount *)allocator.allocate(sizeof(citrack_ros_msgs__msg__DarknetObjectCount), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__msg__DarknetObjectCount));
  bool success = citrack_ros_msgs__msg__DarknetObjectCount__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__msg__DarknetObjectCount__destroy(citrack_ros_msgs__msg__DarknetObjectCount * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__msg__DarknetObjectCount__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__init(citrack_ros_msgs__msg__DarknetObjectCount__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__DarknetObjectCount * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__msg__DarknetObjectCount *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__msg__DarknetObjectCount), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__msg__DarknetObjectCount__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__msg__DarknetObjectCount__fini(&data[i - 1]);
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
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__fini(citrack_ros_msgs__msg__DarknetObjectCount__Sequence * array)
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
      citrack_ros_msgs__msg__DarknetObjectCount__fini(&array->data[i]);
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

citrack_ros_msgs__msg__DarknetObjectCount__Sequence *
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__DarknetObjectCount__Sequence * array = (citrack_ros_msgs__msg__DarknetObjectCount__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__msg__DarknetObjectCount__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__msg__DarknetObjectCount__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__destroy(citrack_ros_msgs__msg__DarknetObjectCount__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__msg__DarknetObjectCount__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__are_equal(const citrack_ros_msgs__msg__DarknetObjectCount__Sequence * lhs, const citrack_ros_msgs__msg__DarknetObjectCount__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__msg__DarknetObjectCount__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__msg__DarknetObjectCount__Sequence__copy(
  const citrack_ros_msgs__msg__DarknetObjectCount__Sequence * input,
  citrack_ros_msgs__msg__DarknetObjectCount__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__msg__DarknetObjectCount);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__msg__DarknetObjectCount * data =
      (citrack_ros_msgs__msg__DarknetObjectCount *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__msg__DarknetObjectCount__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__msg__DarknetObjectCount__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__msg__DarknetObjectCount__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
