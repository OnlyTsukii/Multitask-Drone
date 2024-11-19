// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from drone_interfaces:srv/TaskDispatch.idl
// generated code does not contain a copyright notice
#include "drone_interfaces/srv/detail/task_dispatch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `task`
#include "drone_interfaces/msg/detail/task__functions.h"

bool
drone_interfaces__srv__TaskDispatch_Request__init(drone_interfaces__srv__TaskDispatch_Request * msg)
{
  if (!msg) {
    return false;
  }
  // task
  if (!drone_interfaces__msg__Task__init(&msg->task)) {
    drone_interfaces__srv__TaskDispatch_Request__fini(msg);
    return false;
  }
  return true;
}

void
drone_interfaces__srv__TaskDispatch_Request__fini(drone_interfaces__srv__TaskDispatch_Request * msg)
{
  if (!msg) {
    return;
  }
  // task
  drone_interfaces__msg__Task__fini(&msg->task);
}

bool
drone_interfaces__srv__TaskDispatch_Request__are_equal(const drone_interfaces__srv__TaskDispatch_Request * lhs, const drone_interfaces__srv__TaskDispatch_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task
  if (!drone_interfaces__msg__Task__are_equal(
      &(lhs->task), &(rhs->task)))
  {
    return false;
  }
  return true;
}

bool
drone_interfaces__srv__TaskDispatch_Request__copy(
  const drone_interfaces__srv__TaskDispatch_Request * input,
  drone_interfaces__srv__TaskDispatch_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // task
  if (!drone_interfaces__msg__Task__copy(
      &(input->task), &(output->task)))
  {
    return false;
  }
  return true;
}

drone_interfaces__srv__TaskDispatch_Request *
drone_interfaces__srv__TaskDispatch_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Request * msg = (drone_interfaces__srv__TaskDispatch_Request *)allocator.allocate(sizeof(drone_interfaces__srv__TaskDispatch_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(drone_interfaces__srv__TaskDispatch_Request));
  bool success = drone_interfaces__srv__TaskDispatch_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
drone_interfaces__srv__TaskDispatch_Request__destroy(drone_interfaces__srv__TaskDispatch_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    drone_interfaces__srv__TaskDispatch_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
drone_interfaces__srv__TaskDispatch_Request__Sequence__init(drone_interfaces__srv__TaskDispatch_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Request * data = NULL;

  if (size) {
    data = (drone_interfaces__srv__TaskDispatch_Request *)allocator.zero_allocate(size, sizeof(drone_interfaces__srv__TaskDispatch_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = drone_interfaces__srv__TaskDispatch_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        drone_interfaces__srv__TaskDispatch_Request__fini(&data[i - 1]);
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
drone_interfaces__srv__TaskDispatch_Request__Sequence__fini(drone_interfaces__srv__TaskDispatch_Request__Sequence * array)
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
      drone_interfaces__srv__TaskDispatch_Request__fini(&array->data[i]);
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

drone_interfaces__srv__TaskDispatch_Request__Sequence *
drone_interfaces__srv__TaskDispatch_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Request__Sequence * array = (drone_interfaces__srv__TaskDispatch_Request__Sequence *)allocator.allocate(sizeof(drone_interfaces__srv__TaskDispatch_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = drone_interfaces__srv__TaskDispatch_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
drone_interfaces__srv__TaskDispatch_Request__Sequence__destroy(drone_interfaces__srv__TaskDispatch_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    drone_interfaces__srv__TaskDispatch_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
drone_interfaces__srv__TaskDispatch_Request__Sequence__are_equal(const drone_interfaces__srv__TaskDispatch_Request__Sequence * lhs, const drone_interfaces__srv__TaskDispatch_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!drone_interfaces__srv__TaskDispatch_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
drone_interfaces__srv__TaskDispatch_Request__Sequence__copy(
  const drone_interfaces__srv__TaskDispatch_Request__Sequence * input,
  drone_interfaces__srv__TaskDispatch_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(drone_interfaces__srv__TaskDispatch_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    drone_interfaces__srv__TaskDispatch_Request * data =
      (drone_interfaces__srv__TaskDispatch_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!drone_interfaces__srv__TaskDispatch_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          drone_interfaces__srv__TaskDispatch_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!drone_interfaces__srv__TaskDispatch_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
drone_interfaces__srv__TaskDispatch_Response__init(drone_interfaces__srv__TaskDispatch_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
drone_interfaces__srv__TaskDispatch_Response__fini(drone_interfaces__srv__TaskDispatch_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
drone_interfaces__srv__TaskDispatch_Response__are_equal(const drone_interfaces__srv__TaskDispatch_Response * lhs, const drone_interfaces__srv__TaskDispatch_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
drone_interfaces__srv__TaskDispatch_Response__copy(
  const drone_interfaces__srv__TaskDispatch_Response * input,
  drone_interfaces__srv__TaskDispatch_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

drone_interfaces__srv__TaskDispatch_Response *
drone_interfaces__srv__TaskDispatch_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Response * msg = (drone_interfaces__srv__TaskDispatch_Response *)allocator.allocate(sizeof(drone_interfaces__srv__TaskDispatch_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(drone_interfaces__srv__TaskDispatch_Response));
  bool success = drone_interfaces__srv__TaskDispatch_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
drone_interfaces__srv__TaskDispatch_Response__destroy(drone_interfaces__srv__TaskDispatch_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    drone_interfaces__srv__TaskDispatch_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
drone_interfaces__srv__TaskDispatch_Response__Sequence__init(drone_interfaces__srv__TaskDispatch_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Response * data = NULL;

  if (size) {
    data = (drone_interfaces__srv__TaskDispatch_Response *)allocator.zero_allocate(size, sizeof(drone_interfaces__srv__TaskDispatch_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = drone_interfaces__srv__TaskDispatch_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        drone_interfaces__srv__TaskDispatch_Response__fini(&data[i - 1]);
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
drone_interfaces__srv__TaskDispatch_Response__Sequence__fini(drone_interfaces__srv__TaskDispatch_Response__Sequence * array)
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
      drone_interfaces__srv__TaskDispatch_Response__fini(&array->data[i]);
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

drone_interfaces__srv__TaskDispatch_Response__Sequence *
drone_interfaces__srv__TaskDispatch_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  drone_interfaces__srv__TaskDispatch_Response__Sequence * array = (drone_interfaces__srv__TaskDispatch_Response__Sequence *)allocator.allocate(sizeof(drone_interfaces__srv__TaskDispatch_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = drone_interfaces__srv__TaskDispatch_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
drone_interfaces__srv__TaskDispatch_Response__Sequence__destroy(drone_interfaces__srv__TaskDispatch_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    drone_interfaces__srv__TaskDispatch_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
drone_interfaces__srv__TaskDispatch_Response__Sequence__are_equal(const drone_interfaces__srv__TaskDispatch_Response__Sequence * lhs, const drone_interfaces__srv__TaskDispatch_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!drone_interfaces__srv__TaskDispatch_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
drone_interfaces__srv__TaskDispatch_Response__Sequence__copy(
  const drone_interfaces__srv__TaskDispatch_Response__Sequence * input,
  drone_interfaces__srv__TaskDispatch_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(drone_interfaces__srv__TaskDispatch_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    drone_interfaces__srv__TaskDispatch_Response * data =
      (drone_interfaces__srv__TaskDispatch_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!drone_interfaces__srv__TaskDispatch_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          drone_interfaces__srv__TaskDispatch_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!drone_interfaces__srv__TaskDispatch_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
