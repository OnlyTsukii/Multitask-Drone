// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from drone_interfaces:srv/TaskPush.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__TRAITS_HPP_
#define DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "drone_interfaces/srv/detail/task_push__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'task'
#include "drone_interfaces/msg/detail/task__traits.hpp"

namespace drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskPush_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: task
  {
    out << "task: ";
    to_flow_style_yaml(msg.task, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskPush_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task:\n";
    to_block_style_yaml(msg.task, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskPush_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use drone_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const drone_interfaces::srv::TaskPush_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const drone_interfaces::srv::TaskPush_Request & msg)
{
  return drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<drone_interfaces::srv::TaskPush_Request>()
{
  return "drone_interfaces::srv::TaskPush_Request";
}

template<>
inline const char * name<drone_interfaces::srv::TaskPush_Request>()
{
  return "drone_interfaces/srv/TaskPush_Request";
}

template<>
struct has_fixed_size<drone_interfaces::srv::TaskPush_Request>
  : std::integral_constant<bool, has_fixed_size<drone_interfaces::msg::Task>::value> {};

template<>
struct has_bounded_size<drone_interfaces::srv::TaskPush_Request>
  : std::integral_constant<bool, has_bounded_size<drone_interfaces::msg::Task>::value> {};

template<>
struct is_message<drone_interfaces::srv::TaskPush_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskPush_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskPush_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskPush_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use drone_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const drone_interfaces::srv::TaskPush_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const drone_interfaces::srv::TaskPush_Response & msg)
{
  return drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<drone_interfaces::srv::TaskPush_Response>()
{
  return "drone_interfaces::srv::TaskPush_Response";
}

template<>
inline const char * name<drone_interfaces::srv::TaskPush_Response>()
{
  return "drone_interfaces/srv/TaskPush_Response";
}

template<>
struct has_fixed_size<drone_interfaces::srv::TaskPush_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<drone_interfaces::srv::TaskPush_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<drone_interfaces::srv::TaskPush_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<drone_interfaces::srv::TaskPush>()
{
  return "drone_interfaces::srv::TaskPush";
}

template<>
inline const char * name<drone_interfaces::srv::TaskPush>()
{
  return "drone_interfaces/srv/TaskPush";
}

template<>
struct has_fixed_size<drone_interfaces::srv::TaskPush>
  : std::integral_constant<
    bool,
    has_fixed_size<drone_interfaces::srv::TaskPush_Request>::value &&
    has_fixed_size<drone_interfaces::srv::TaskPush_Response>::value
  >
{
};

template<>
struct has_bounded_size<drone_interfaces::srv::TaskPush>
  : std::integral_constant<
    bool,
    has_bounded_size<drone_interfaces::srv::TaskPush_Request>::value &&
    has_bounded_size<drone_interfaces::srv::TaskPush_Response>::value
  >
{
};

template<>
struct is_service<drone_interfaces::srv::TaskPush>
  : std::true_type
{
};

template<>
struct is_service_request<drone_interfaces::srv::TaskPush_Request>
  : std::true_type
{
};

template<>
struct is_service_response<drone_interfaces::srv::TaskPush_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__TRAITS_HPP_
