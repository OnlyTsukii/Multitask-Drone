// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_interfaces:srv/YoloRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__STRUCT_H_
#define DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/YoloRequest in the package drone_interfaces.
typedef struct drone_interfaces__srv__YoloRequest_Request
{
  bool start;
} drone_interfaces__srv__YoloRequest_Request;

// Struct for a sequence of drone_interfaces__srv__YoloRequest_Request.
typedef struct drone_interfaces__srv__YoloRequest_Request__Sequence
{
  drone_interfaces__srv__YoloRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__srv__YoloRequest_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/YoloRequest in the package drone_interfaces.
typedef struct drone_interfaces__srv__YoloRequest_Response
{
  bool success;
} drone_interfaces__srv__YoloRequest_Response;

// Struct for a sequence of drone_interfaces__srv__YoloRequest_Response.
typedef struct drone_interfaces__srv__YoloRequest_Response__Sequence
{
  drone_interfaces__srv__YoloRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__srv__YoloRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__STRUCT_H_
