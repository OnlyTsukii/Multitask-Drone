// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_
#define DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TaskState in the package drone_interfaces.
typedef struct drone_interfaces__msg__TaskState
{
  /// Support Task States:
  /// RUNNING   = 0
  /// SUCCEED   = 1
  uint8_t state;
} drone_interfaces__msg__TaskState;

// Struct for a sequence of drone_interfaces__msg__TaskState.
typedef struct drone_interfaces__msg__TaskState__Sequence
{
  drone_interfaces__msg__TaskState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__msg__TaskState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__STRUCT_H_
