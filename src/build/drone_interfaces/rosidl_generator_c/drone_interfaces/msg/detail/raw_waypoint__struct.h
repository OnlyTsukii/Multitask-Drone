// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_interfaces:msg/RawWaypoint.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_H_
#define DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RawWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__msg__RawWaypoint
{
  uint8_t id;
  int8_t type;
  int8_t mission;
  double latitude;
  double longitude;
  /// in meters, AMSL or above terrain
  float altitude;
  float velocity;
  double yaw;
  double yaw_rate;
} drone_interfaces__msg__RawWaypoint;

// Struct for a sequence of drone_interfaces__msg__RawWaypoint.
typedef struct drone_interfaces__msg__RawWaypoint__Sequence
{
  drone_interfaces__msg__RawWaypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__msg__RawWaypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_H_
