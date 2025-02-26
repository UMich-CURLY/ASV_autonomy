// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:msg/UwbAnchor.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/uwb_anchor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `id`
#include "rosidl_runtime_c/string_functions.h"

bool
citrack_ros_msgs__msg__UwbAnchor__init(citrack_ros_msgs__msg__UwbAnchor * msg)
{
  if (!msg) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__init(&msg->id)) {
    citrack_ros_msgs__msg__UwbAnchor__fini(msg);
    return false;
  }
  // x
  // y
  // z
  // distancefromtag
  return true;
}

void
citrack_ros_msgs__msg__UwbAnchor__fini(citrack_ros_msgs__msg__UwbAnchor * msg)
{
  if (!msg) {
    return;
  }
  // id
  rosidl_runtime_c__String__fini(&msg->id);
  // x
  // y
  // z
  // distancefromtag
}

bool
citrack_ros_msgs__msg__UwbAnchor__are_equal(const citrack_ros_msgs__msg__UwbAnchor * lhs, const citrack_ros_msgs__msg__UwbAnchor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // distancefromtag
  if (lhs->distancefromtag != rhs->distancefromtag) {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__msg__UwbAnchor__copy(
  const citrack_ros_msgs__msg__UwbAnchor * input,
  citrack_ros_msgs__msg__UwbAnchor * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  if (!rosidl_runtime_c__String__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // distancefromtag
  output->distancefromtag = input->distancefromtag;
  return true;
}

citrack_ros_msgs__msg__UwbAnchor *
citrack_ros_msgs__msg__UwbAnchor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__UwbAnchor * msg = (citrack_ros_msgs__msg__UwbAnchor *)allocator.allocate(sizeof(citrack_ros_msgs__msg__UwbAnchor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__msg__UwbAnchor));
  bool success = citrack_ros_msgs__msg__UwbAnchor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__msg__UwbAnchor__destroy(citrack_ros_msgs__msg__UwbAnchor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__msg__UwbAnchor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__msg__UwbAnchor__Sequence__init(citrack_ros_msgs__msg__UwbAnchor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__UwbAnchor * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__msg__UwbAnchor *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__msg__UwbAnchor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__msg__UwbAnchor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__msg__UwbAnchor__fini(&data[i - 1]);
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
citrack_ros_msgs__msg__UwbAnchor__Sequence__fini(citrack_ros_msgs__msg__UwbAnchor__Sequence * array)
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
      citrack_ros_msgs__msg__UwbAnchor__fini(&array->data[i]);
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

citrack_ros_msgs__msg__UwbAnchor__Sequence *
citrack_ros_msgs__msg__UwbAnchor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__UwbAnchor__Sequence * array = (citrack_ros_msgs__msg__UwbAnchor__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__msg__UwbAnchor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__msg__UwbAnchor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__msg__UwbAnchor__Sequence__destroy(citrack_ros_msgs__msg__UwbAnchor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__msg__UwbAnchor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__msg__UwbAnchor__Sequence__are_equal(const citrack_ros_msgs__msg__UwbAnchor__Sequence * lhs, const citrack_ros_msgs__msg__UwbAnchor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__msg__UwbAnchor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__msg__UwbAnchor__Sequence__copy(
  const citrack_ros_msgs__msg__UwbAnchor__Sequence * input,
  citrack_ros_msgs__msg__UwbAnchor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__msg__UwbAnchor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__msg__UwbAnchor * data =
      (citrack_ros_msgs__msg__UwbAnchor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__msg__UwbAnchor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__msg__UwbAnchor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__msg__UwbAnchor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
