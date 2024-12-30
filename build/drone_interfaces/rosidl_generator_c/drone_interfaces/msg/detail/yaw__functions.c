// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from drone_interfaces:msg/Yaw.idl
// generated code does not contain a copyright notice
#include "drone_interfaces/msg/detail/yaw__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
drone_interfaces__msg__Yaw__init(drone_interfaces__msg__Yaw * msg)
{
  if (!msg) {
    return false;
  }
  // yaw
  return true;
}

void
drone_interfaces__msg__Yaw__fini(drone_interfaces__msg__Yaw * msg)
{
  if (!msg) {
    return;
  }
  // yaw
}

bool
drone_interfaces__msg__Yaw__are_equal(const drone_interfaces__msg__Yaw * lhs, const drone_interfaces__msg__Yaw * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
drone_interfaces__msg__Yaw__copy(
  const drone_interfaces__msg__Yaw * input,
  drone_interfaces__msg__Yaw * output)
{
  if (!input || !output) {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  return true;
}

drone_interfaces__msg__Yaw *
drone_interfaces__msg__Yaw__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__msg__Yaw * msg = (drone_interfaces__msg__Yaw *)allocator.allocate(sizeof(drone_interfaces__msg__Yaw), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(drone_interfaces__msg__Yaw));
  bool success = drone_interfaces__msg__Yaw__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
drone_interfaces__msg__Yaw__destroy(drone_interfaces__msg__Yaw * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    drone_interfaces__msg__Yaw__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
drone_interfaces__msg__Yaw__Sequence__init(drone_interfaces__msg__Yaw__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__msg__Yaw * data = NULL;

  if (size) {
    data = (drone_interfaces__msg__Yaw *)allocator.zero_allocate(size, sizeof(drone_interfaces__msg__Yaw), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = drone_interfaces__msg__Yaw__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        drone_interfaces__msg__Yaw__fini(&data[i - 1]);
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
drone_interfaces__msg__Yaw__Sequence__fini(drone_interfaces__msg__Yaw__Sequence * array)
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
      drone_interfaces__msg__Yaw__fini(&array->data[i]);
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

drone_interfaces__msg__Yaw__Sequence *
drone_interfaces__msg__Yaw__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__msg__Yaw__Sequence * array = (drone_interfaces__msg__Yaw__Sequence *)allocator.allocate(sizeof(drone_interfaces__msg__Yaw__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = drone_interfaces__msg__Yaw__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
drone_interfaces__msg__Yaw__Sequence__destroy(drone_interfaces__msg__Yaw__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    drone_interfaces__msg__Yaw__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
drone_interfaces__msg__Yaw__Sequence__are_equal(const drone_interfaces__msg__Yaw__Sequence * lhs, const drone_interfaces__msg__Yaw__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!drone_interfaces__msg__Yaw__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
drone_interfaces__msg__Yaw__Sequence__copy(
  const drone_interfaces__msg__Yaw__Sequence * input,
  drone_interfaces__msg__Yaw__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(drone_interfaces__msg__Yaw);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    drone_interfaces__msg__Yaw * data =
      (drone_interfaces__msg__Yaw *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!drone_interfaces__msg__Yaw__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          drone_interfaces__msg__Yaw__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!drone_interfaces__msg__Yaw__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
