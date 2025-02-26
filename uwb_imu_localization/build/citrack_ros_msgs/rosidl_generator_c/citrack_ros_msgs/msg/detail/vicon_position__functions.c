// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from citrack_ros_msgs:msg/ViconPosition.idl
// generated code does not contain a copyright notice
#include "citrack_ros_msgs/msg/detail/vicon_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `segment_name`
// Member `subject_name`
// Member `translation_type`
#include "rosidl_runtime_c/string_functions.h"

bool
citrack_ros_msgs__msg__ViconPosition__init(citrack_ros_msgs__msg__ViconPosition * msg)
{
  if (!msg) {
    return false;
  }
  // x_trans
  // y_trans
  // z_trans
  // x_rot
  // y_rot
  // z_rot
  // w
  // segment_name
  if (!rosidl_runtime_c__String__init(&msg->segment_name)) {
    citrack_ros_msgs__msg__ViconPosition__fini(msg);
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__init(&msg->subject_name)) {
    citrack_ros_msgs__msg__ViconPosition__fini(msg);
    return false;
  }
  // frame_number
  // translation_type
  if (!rosidl_runtime_c__String__init(&msg->translation_type)) {
    citrack_ros_msgs__msg__ViconPosition__fini(msg);
    return false;
  }
  return true;
}

void
citrack_ros_msgs__msg__ViconPosition__fini(citrack_ros_msgs__msg__ViconPosition * msg)
{
  if (!msg) {
    return;
  }
  // x_trans
  // y_trans
  // z_trans
  // x_rot
  // y_rot
  // z_rot
  // w
  // segment_name
  rosidl_runtime_c__String__fini(&msg->segment_name);
  // subject_name
  rosidl_runtime_c__String__fini(&msg->subject_name);
  // frame_number
  // translation_type
  rosidl_runtime_c__String__fini(&msg->translation_type);
}

bool
citrack_ros_msgs__msg__ViconPosition__are_equal(const citrack_ros_msgs__msg__ViconPosition * lhs, const citrack_ros_msgs__msg__ViconPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_trans
  if (lhs->x_trans != rhs->x_trans) {
    return false;
  }
  // y_trans
  if (lhs->y_trans != rhs->y_trans) {
    return false;
  }
  // z_trans
  if (lhs->z_trans != rhs->z_trans) {
    return false;
  }
  // x_rot
  if (lhs->x_rot != rhs->x_rot) {
    return false;
  }
  // y_rot
  if (lhs->y_rot != rhs->y_rot) {
    return false;
  }
  // z_rot
  if (lhs->z_rot != rhs->z_rot) {
    return false;
  }
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  // segment_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->segment_name), &(rhs->segment_name)))
  {
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->subject_name), &(rhs->subject_name)))
  {
    return false;
  }
  // frame_number
  if (lhs->frame_number != rhs->frame_number) {
    return false;
  }
  // translation_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->translation_type), &(rhs->translation_type)))
  {
    return false;
  }
  return true;
}

bool
citrack_ros_msgs__msg__ViconPosition__copy(
  const citrack_ros_msgs__msg__ViconPosition * input,
  citrack_ros_msgs__msg__ViconPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // x_trans
  output->x_trans = input->x_trans;
  // y_trans
  output->y_trans = input->y_trans;
  // z_trans
  output->z_trans = input->z_trans;
  // x_rot
  output->x_rot = input->x_rot;
  // y_rot
  output->y_rot = input->y_rot;
  // z_rot
  output->z_rot = input->z_rot;
  // w
  output->w = input->w;
  // segment_name
  if (!rosidl_runtime_c__String__copy(
      &(input->segment_name), &(output->segment_name)))
  {
    return false;
  }
  // subject_name
  if (!rosidl_runtime_c__String__copy(
      &(input->subject_name), &(output->subject_name)))
  {
    return false;
  }
  // frame_number
  output->frame_number = input->frame_number;
  // translation_type
  if (!rosidl_runtime_c__String__copy(
      &(input->translation_type), &(output->translation_type)))
  {
    return false;
  }
  return true;
}

citrack_ros_msgs__msg__ViconPosition *
citrack_ros_msgs__msg__ViconPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__ViconPosition * msg = (citrack_ros_msgs__msg__ViconPosition *)allocator.allocate(sizeof(citrack_ros_msgs__msg__ViconPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(citrack_ros_msgs__msg__ViconPosition));
  bool success = citrack_ros_msgs__msg__ViconPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
citrack_ros_msgs__msg__ViconPosition__destroy(citrack_ros_msgs__msg__ViconPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    citrack_ros_msgs__msg__ViconPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
citrack_ros_msgs__msg__ViconPosition__Sequence__init(citrack_ros_msgs__msg__ViconPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__ViconPosition * data = NULL;

  if (size) {
    data = (citrack_ros_msgs__msg__ViconPosition *)allocator.zero_allocate(size, sizeof(citrack_ros_msgs__msg__ViconPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = citrack_ros_msgs__msg__ViconPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        citrack_ros_msgs__msg__ViconPosition__fini(&data[i - 1]);
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
citrack_ros_msgs__msg__ViconPosition__Sequence__fini(citrack_ros_msgs__msg__ViconPosition__Sequence * array)
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
      citrack_ros_msgs__msg__ViconPosition__fini(&array->data[i]);
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

citrack_ros_msgs__msg__ViconPosition__Sequence *
citrack_ros_msgs__msg__ViconPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  citrack_ros_msgs__msg__ViconPosition__Sequence * array = (citrack_ros_msgs__msg__ViconPosition__Sequence *)allocator.allocate(sizeof(citrack_ros_msgs__msg__ViconPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = citrack_ros_msgs__msg__ViconPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
citrack_ros_msgs__msg__ViconPosition__Sequence__destroy(citrack_ros_msgs__msg__ViconPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    citrack_ros_msgs__msg__ViconPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
citrack_ros_msgs__msg__ViconPosition__Sequence__are_equal(const citrack_ros_msgs__msg__ViconPosition__Sequence * lhs, const citrack_ros_msgs__msg__ViconPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!citrack_ros_msgs__msg__ViconPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
citrack_ros_msgs__msg__ViconPosition__Sequence__copy(
  const citrack_ros_msgs__msg__ViconPosition__Sequence * input,
  citrack_ros_msgs__msg__ViconPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(citrack_ros_msgs__msg__ViconPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    citrack_ros_msgs__msg__ViconPosition * data =
      (citrack_ros_msgs__msg__ViconPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!citrack_ros_msgs__msg__ViconPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          citrack_ros_msgs__msg__ViconPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!citrack_ros_msgs__msg__ViconPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
