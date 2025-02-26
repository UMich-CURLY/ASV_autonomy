// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg)
{
  if (!msg) {
    return;
  }
  // id
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Goal * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_Goal *
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_Goal *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Goal));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_Goal *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_Goal * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `bounding_boxes`
#include "citrack_ros_msgs/msg/detail/darknet_bounding_boxes__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // bounding_boxes
  if (!citrack_ros_msgs__msg__DarknetBoundingBoxes__init(&msg->bounding_boxes)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg)
{
  if (!msg) {
    return;
  }
  // id
  // bounding_boxes
  citrack_ros_msgs__msg__DarknetBoundingBoxes__fini(&msg->bounding_boxes);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Result * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // bounding_boxes
  if (!citrack_ros_msgs__msg__DarknetBoundingBoxes__are_equal(
      &(lhs->bounding_boxes), &(rhs->bounding_boxes)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Result * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // bounding_boxes
  if (!citrack_ros_msgs__msg__DarknetBoundingBoxes__copy(
      &(input->bounding_boxes), &(output->bounding_boxes)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_Result *
citrack_ros_msgs__action__DarknetCheckForObjects_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_Result *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Result));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Result * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_Result *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_Result * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_Feedback *
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_Feedback *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_Feedback *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_Feedback * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__init(&msg->goal)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  citrack_ros_msgs__action__DarknetCheckForObjects_Goal__fini(&msg->goal);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__init(&msg->result)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  citrack_ros_msgs__action__DarknetCheckForObjects_Result__fini(&msg->result);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__functions.h"

bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__init(&msg->feedback)) {
    citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__fini(&msg->feedback);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!citrack_ros_msgs__action__DarknetCheckForObjects_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage *
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg = (citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage));
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__init(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(&data[i - 1]);
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
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__fini(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array)
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
      citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(&array->data[i]);
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

citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence *
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array = (citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__destroy(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__are_equal(const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * lhs, const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence__copy(
  const citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * input,
  citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage * data =
      (citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__action__DarknetCheckForObjects_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
