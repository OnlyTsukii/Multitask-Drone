// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from drone_interfaces:action/ExecuteWaypoint.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__ACTION__DETAIL__EXECUTE_WAYPOINT__STRUCT_H_
#define DRONE_INTERFACES__ACTION__DETAIL__EXECUTE_WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoint'
#include "drone_interfaces/msg/detail/raw_waypoint__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_Goal
{
  drone_interfaces__msg__RawWaypoint waypoint;
} drone_interfaces__action__ExecuteWaypoint_Goal;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_Goal.
typedef struct drone_interfaces__action__ExecuteWaypoint_Goal__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_Result
{
  bool success;
} drone_interfaces__action__ExecuteWaypoint_Result;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_Result.
typedef struct drone_interfaces__action__ExecuteWaypoint_Result__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_Feedback
{
  uint8_t feedback;
} drone_interfaces__action__ExecuteWaypoint_Feedback;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_Feedback.
typedef struct drone_interfaces__action__ExecuteWaypoint_Feedback__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "drone_interfaces/action/detail/execute_waypoint__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  drone_interfaces__action__ExecuteWaypoint_Goal goal;
} drone_interfaces__action__ExecuteWaypoint_SendGoal_Request;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_SendGoal_Request.
typedef struct drone_interfaces__action__ExecuteWaypoint_SendGoal_Request__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} drone_interfaces__action__ExecuteWaypoint_SendGoal_Response;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_SendGoal_Response.
typedef struct drone_interfaces__action__ExecuteWaypoint_SendGoal_Response__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} drone_interfaces__action__ExecuteWaypoint_GetResult_Request;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_GetResult_Request.
typedef struct drone_interfaces__action__ExecuteWaypoint_GetResult_Request__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_GetResult_Response
{
  int8_t status;
  drone_interfaces__action__ExecuteWaypoint_Result result;
} drone_interfaces__action__ExecuteWaypoint_GetResult_Response;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_GetResult_Response.
typedef struct drone_interfaces__action__ExecuteWaypoint_GetResult_Response__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.h"

/// Struct defined in action/ExecuteWaypoint in the package drone_interfaces.
typedef struct drone_interfaces__action__ExecuteWaypoint_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  drone_interfaces__action__ExecuteWaypoint_Feedback feedback;
} drone_interfaces__action__ExecuteWaypoint_FeedbackMessage;

// Struct for a sequence of drone_interfaces__action__ExecuteWaypoint_FeedbackMessage.
typedef struct drone_interfaces__action__ExecuteWaypoint_FeedbackMessage__Sequence
{
  drone_interfaces__action__ExecuteWaypoint_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} drone_interfaces__action__ExecuteWaypoint_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONE_INTERFACES__ACTION__DETAIL__EXECUTE_WAYPOINT__STRUCT_H_
