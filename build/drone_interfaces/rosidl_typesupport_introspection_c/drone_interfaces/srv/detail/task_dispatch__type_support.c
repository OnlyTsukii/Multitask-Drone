// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from drone_interfaces:srv/TaskDispatch.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "drone_interfaces/srv/detail/task_dispatch__rosidl_typesupport_introspection_c.h"
#include "drone_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "drone_interfaces/srv/detail/task_dispatch__functions.h"
#include "drone_interfaces/srv/detail/task_dispatch__struct.h"


// Include directives for member types
// Member `task`
#include "drone_interfaces/msg/task.h"
// Member `task`
#include "drone_interfaces/msg/detail/task__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  drone_interfaces__srv__TaskDispatch_Request__init(message_memory);
}

void drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_fini_function(void * message_memory)
{
  drone_interfaces__srv__TaskDispatch_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_member_array[1] = {
  {
    "task",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(drone_interfaces__srv__TaskDispatch_Request, task),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_members = {
  "drone_interfaces__srv",  // message namespace
  "TaskDispatch_Request",  // message name
  1,  // number of fields
  sizeof(drone_interfaces__srv__TaskDispatch_Request),
  drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_member_array,  // message members
  drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_type_support_handle = {
  0,
  &drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_drone_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Request)() {
  drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, msg, Task)();
  if (!drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_type_support_handle.typesupport_identifier) {
    drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &drone_interfaces__srv__TaskDispatch_Request__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "drone_interfaces/srv/detail/task_dispatch__rosidl_typesupport_introspection_c.h"
// already included above
// #include "drone_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "drone_interfaces/srv/detail/task_dispatch__functions.h"
// already included above
// #include "drone_interfaces/srv/detail/task_dispatch__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  drone_interfaces__srv__TaskDispatch_Response__init(message_memory);
}

void drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_fini_function(void * message_memory)
{
  drone_interfaces__srv__TaskDispatch_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(drone_interfaces__srv__TaskDispatch_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_members = {
  "drone_interfaces__srv",  // message namespace
  "TaskDispatch_Response",  // message name
  1,  // number of fields
  sizeof(drone_interfaces__srv__TaskDispatch_Response),
  drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_member_array,  // message members
  drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_type_support_handle = {
  0,
  &drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_drone_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Response)() {
  if (!drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_type_support_handle.typesupport_identifier) {
    drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &drone_interfaces__srv__TaskDispatch_Response__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "drone_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "drone_interfaces/srv/detail/task_dispatch__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_members = {
  "drone_interfaces__srv",  // service namespace
  "TaskDispatch",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_Request_message_type_support_handle,
  NULL  // response message
  // drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_Response_message_type_support_handle
};

static rosidl_service_type_support_t drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_type_support_handle = {
  0,
  &drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_drone_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch)() {
  if (!drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_type_support_handle.typesupport_identifier) {
    drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, drone_interfaces, srv, TaskDispatch_Response)()->data;
  }

  return &drone_interfaces__srv__detail__task_dispatch__rosidl_typesupport_introspection_c__TaskDispatch_service_type_support_handle;
}
