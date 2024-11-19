// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from drone_interfaces:action/ExecuteWaypoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_Goal_type_support_ids_t;

static const _ExecuteWaypoint_Goal_type_support_ids_t _ExecuteWaypoint_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_Goal_type_support_symbol_names_t _ExecuteWaypoint_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_Goal)),
  }
};

typedef struct _ExecuteWaypoint_Goal_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_Goal_type_support_data_t;

static _ExecuteWaypoint_Goal_type_support_data_t _ExecuteWaypoint_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_Goal_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Goal>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_Goal)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_Result_type_support_ids_t;

static const _ExecuteWaypoint_Result_type_support_ids_t _ExecuteWaypoint_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_Result_type_support_symbol_names_t _ExecuteWaypoint_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_Result)),
  }
};

typedef struct _ExecuteWaypoint_Result_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_Result_type_support_data_t;

static _ExecuteWaypoint_Result_type_support_data_t _ExecuteWaypoint_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_Result_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_Result_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_Result_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Result>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_Result)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_Feedback_type_support_ids_t;

static const _ExecuteWaypoint_Feedback_type_support_ids_t _ExecuteWaypoint_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_Feedback_type_support_symbol_names_t _ExecuteWaypoint_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_Feedback)),
  }
};

typedef struct _ExecuteWaypoint_Feedback_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_Feedback_type_support_data_t;

static _ExecuteWaypoint_Feedback_type_support_data_t _ExecuteWaypoint_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_Feedback_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Feedback>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_Feedback)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_SendGoal_Request_type_support_ids_t;

static const _ExecuteWaypoint_SendGoal_Request_type_support_ids_t _ExecuteWaypoint_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_SendGoal_Request_type_support_symbol_names_t _ExecuteWaypoint_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Request)),
  }
};

typedef struct _ExecuteWaypoint_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_SendGoal_Request_type_support_data_t;

static _ExecuteWaypoint_SendGoal_Request_type_support_data_t _ExecuteWaypoint_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_SendGoal_Request_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_SendGoal_Request>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Request)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_SendGoal_Response_type_support_ids_t;

static const _ExecuteWaypoint_SendGoal_Response_type_support_ids_t _ExecuteWaypoint_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_SendGoal_Response_type_support_symbol_names_t _ExecuteWaypoint_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Response)),
  }
};

typedef struct _ExecuteWaypoint_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_SendGoal_Response_type_support_data_t;

static _ExecuteWaypoint_SendGoal_Response_type_support_data_t _ExecuteWaypoint_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_SendGoal_Response_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_SendGoal_Response>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal_Response)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_SendGoal_type_support_ids_t;

static const _ExecuteWaypoint_SendGoal_type_support_ids_t _ExecuteWaypoint_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_SendGoal_type_support_symbol_names_t _ExecuteWaypoint_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_SendGoal)),
  }
};

typedef struct _ExecuteWaypoint_SendGoal_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_SendGoal_type_support_data_t;

static _ExecuteWaypoint_SendGoal_type_support_data_t _ExecuteWaypoint_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_SendGoal_service_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteWaypoint_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<drone_interfaces::action::ExecuteWaypoint_SendGoal>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_GetResult_Request_type_support_ids_t;

static const _ExecuteWaypoint_GetResult_Request_type_support_ids_t _ExecuteWaypoint_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_GetResult_Request_type_support_symbol_names_t _ExecuteWaypoint_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Request)),
  }
};

typedef struct _ExecuteWaypoint_GetResult_Request_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_GetResult_Request_type_support_data_t;

static _ExecuteWaypoint_GetResult_Request_type_support_data_t _ExecuteWaypoint_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_GetResult_Request_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_GetResult_Request>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Request)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_GetResult_Response_type_support_ids_t;

static const _ExecuteWaypoint_GetResult_Response_type_support_ids_t _ExecuteWaypoint_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_GetResult_Response_type_support_symbol_names_t _ExecuteWaypoint_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Response)),
  }
};

typedef struct _ExecuteWaypoint_GetResult_Response_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_GetResult_Response_type_support_data_t;

static _ExecuteWaypoint_GetResult_Response_type_support_data_t _ExecuteWaypoint_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_GetResult_Response_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_GetResult_Response>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult_Response)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_GetResult_type_support_ids_t;

static const _ExecuteWaypoint_GetResult_type_support_ids_t _ExecuteWaypoint_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_GetResult_type_support_symbol_names_t _ExecuteWaypoint_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_GetResult)),
  }
};

typedef struct _ExecuteWaypoint_GetResult_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_GetResult_type_support_data_t;

static _ExecuteWaypoint_GetResult_type_support_data_t _ExecuteWaypoint_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_GetResult_service_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteWaypoint_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<drone_interfaces::action::ExecuteWaypoint_GetResult>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteWaypoint_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteWaypoint_FeedbackMessage_type_support_ids_t;

static const _ExecuteWaypoint_FeedbackMessage_type_support_ids_t _ExecuteWaypoint_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteWaypoint_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteWaypoint_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteWaypoint_FeedbackMessage_type_support_symbol_names_t _ExecuteWaypoint_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, drone_interfaces, action, ExecuteWaypoint_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, action, ExecuteWaypoint_FeedbackMessage)),
  }
};

typedef struct _ExecuteWaypoint_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _ExecuteWaypoint_FeedbackMessage_type_support_data_t;

static _ExecuteWaypoint_FeedbackMessage_type_support_data_t _ExecuteWaypoint_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteWaypoint_FeedbackMessage_message_typesupport_map = {
  2,
  "drone_interfaces",
  &_ExecuteWaypoint_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteWaypoint_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteWaypoint_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteWaypoint_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteWaypoint_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_FeedbackMessage>()
{
  return &::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, drone_interfaces, action, ExecuteWaypoint_FeedbackMessage)() {
  return get_message_type_support_handle<drone_interfaces::action::ExecuteWaypoint_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "drone_interfaces/action/detail/execute_waypoint__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace drone_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t ExecuteWaypoint_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace drone_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<drone_interfaces::action::ExecuteWaypoint>()
{
  using ::drone_interfaces::action::rosidl_typesupport_cpp::ExecuteWaypoint_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  ExecuteWaypoint_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::drone_interfaces::action::ExecuteWaypoint::Impl::SendGoalService>();
  ExecuteWaypoint_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::drone_interfaces::action::ExecuteWaypoint::Impl::GetResultService>();
  ExecuteWaypoint_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::drone_interfaces::action::ExecuteWaypoint::Impl::CancelGoalService>();
  ExecuteWaypoint_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::drone_interfaces::action::ExecuteWaypoint::Impl::FeedbackMessage>();
  ExecuteWaypoint_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::drone_interfaces::action::ExecuteWaypoint::Impl::GoalStatusMessage>();
  return &ExecuteWaypoint_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
