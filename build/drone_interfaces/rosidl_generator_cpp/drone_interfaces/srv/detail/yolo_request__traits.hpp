// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from drone_interfaces:srv/YoloRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__TRAITS_HPP_
#define DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "drone_interfaces/srv/detail/yolo_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const YoloRequest_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloRequest_Request & msg, bool use_flow_style = false)
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
  const drone_interfaces::srv::YoloRequest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const drone_interfaces::srv::YoloRequest_Request & msg)
{
  return drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<drone_interfaces::srv::YoloRequest_Request>()
{
  return "drone_interfaces::srv::YoloRequest_Request";
}

template<>
inline const char * name<drone_interfaces::srv::YoloRequest_Request>()
{
  return "drone_interfaces/srv/YoloRequest_Request";
}

template<>
struct has_fixed_size<drone_interfaces::srv::YoloRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<drone_interfaces::srv::YoloRequest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<drone_interfaces::srv::YoloRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace drone_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const YoloRequest_Response & msg,
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
  const YoloRequest_Response & msg,
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

inline std::string to_yaml(const YoloRequest_Response & msg, bool use_flow_style = false)
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
  const drone_interfaces::srv::YoloRequest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  drone_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use drone_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const drone_interfaces::srv::YoloRequest_Response & msg)
{
  return drone_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<drone_interfaces::srv::YoloRequest_Response>()
{
  return "drone_interfaces::srv::YoloRequest_Response";
}

template<>
inline const char * name<drone_interfaces::srv::YoloRequest_Response>()
{
  return "drone_interfaces/srv/YoloRequest_Response";
}

template<>
struct has_fixed_size<drone_interfaces::srv::YoloRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<drone_interfaces::srv::YoloRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<drone_interfaces::srv::YoloRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<drone_interfaces::srv::YoloRequest>()
{
  return "drone_interfaces::srv::YoloRequest";
}

template<>
inline const char * name<drone_interfaces::srv::YoloRequest>()
{
  return "drone_interfaces/srv/YoloRequest";
}

template<>
struct has_fixed_size<drone_interfaces::srv::YoloRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<drone_interfaces::srv::YoloRequest_Request>::value &&
    has_fixed_size<drone_interfaces::srv::YoloRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<drone_interfaces::srv::YoloRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<drone_interfaces::srv::YoloRequest_Request>::value &&
    has_bounded_size<drone_interfaces::srv::YoloRequest_Response>::value
  >
{
};

template<>
struct is_service<drone_interfaces::srv::YoloRequest>
  : std::true_type
{
};

template<>
struct is_service_request<drone_interfaces::srv::YoloRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<drone_interfaces::srv::YoloRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__TRAITS_HPP_
