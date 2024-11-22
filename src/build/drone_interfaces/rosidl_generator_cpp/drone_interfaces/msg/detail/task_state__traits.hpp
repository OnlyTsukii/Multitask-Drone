// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from drone_interfaces:msg/TaskState.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__TRAITS_HPP_
#define DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "drone_interfaces/msg/detail/task_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace drone_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskState & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace drone_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use drone_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const drone_interfaces::msg::TaskState & msg,
  std::ostream & out, size_t indentation = 0)
{
  drone_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use drone_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const drone_interfaces::msg::TaskState & msg)
{
  return drone_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<drone_interfaces::msg::TaskState>()
{
  return "drone_interfaces::msg::TaskState";
}

template<>
inline const char * name<drone_interfaces::msg::TaskState>()
{
  return "drone_interfaces/msg/TaskState";
}

template<>
struct has_fixed_size<drone_interfaces::msg::TaskState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<drone_interfaces::msg::TaskState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<drone_interfaces::msg::TaskState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONE_INTERFACES__MSG__DETAIL__TASK_STATE__TRAITS_HPP_
