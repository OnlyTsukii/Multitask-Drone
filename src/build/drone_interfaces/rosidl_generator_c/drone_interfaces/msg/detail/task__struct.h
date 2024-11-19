// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
#define DRONE_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "drone_interfaces/msg/detail/raw_waypoint__struct.h"

/// Struct defined in msg/Task in the package drone_interfaces.
typedef struct drone_interfaces__msg__Task
{
  drone_interfaces__msg__RawWaypoint__Sequence waypoints;
} drone_interfaces__msg__Task;

// Struct for a sequence of drone_interfaces__msg__Task.
typedef struct drone_interfaces__msg__Task__Sequence
{
  drone_interfaces__msg__Task * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__msg__Task__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_INTERFACES__MSG__DETAIL__TASK__STRUCT_H_
