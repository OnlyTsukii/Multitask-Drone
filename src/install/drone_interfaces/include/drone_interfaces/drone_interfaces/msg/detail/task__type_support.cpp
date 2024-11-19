// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from drone_interfaces:msg/Task.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "drone_interfaces/msg/detail/task__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace drone_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Task_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) drone_interfaces::msg::Task(_init);
}

void Task_fini_function(void * message_memory)
{
  auto typed_message = static_cast<drone_interfaces::msg::Task *>(message_memory);
  typed_message->~Task();
}

size_t size_function__Task__waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<drone_interfaces::msg::RawWaypoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Task__waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<drone_interfaces::msg::RawWaypoint> *>(untyped_member);
  return &member[index];
}

void * get_function__Task__waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<drone_interfaces::msg::RawWaypoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__Task__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const drone_interfaces::msg::RawWaypoint *>(
    get_const_function__Task__waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<drone_interfaces::msg::RawWaypoint *>(untyped_value);
  value = item;
}

void assign_function__Task__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<drone_interfaces::msg::RawWaypoint *>(
    get_function__Task__waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const drone_interfaces::msg::RawWaypoint *>(untyped_value);
  item = value;
}

void resize_function__Task__waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<drone_interfaces::msg::RawWaypoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Task_message_member_array[1] = {
  {
    "waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<drone_interfaces::msg::RawWaypoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(drone_interfaces::msg::Task, waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__Task__waypoints,  // size() function pointer
    get_const_function__Task__waypoints,  // get_const(index) function pointer
    get_function__Task__waypoints,  // get(index) function pointer
    fetch_function__Task__waypoints,  // fetch(index, &value) function pointer
    assign_function__Task__waypoints,  // assign(index, value) function pointer
    resize_function__Task__waypoints  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Task_message_members = {
  "drone_interfaces::msg",  // message namespace
  "Task",  // message name
  1,  // number of fields
  sizeof(drone_interfaces::msg::Task),
  Task_message_member_array,  // message members
  Task_init_function,  // function to initialize message memory (memory has to be allocated)
  Task_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Task_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Task_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace drone_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<drone_interfaces::msg::Task>()
{
  return &::drone_interfaces::msg::rosidl_typesupport_introspection_cpp::Task_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, drone_interfaces, msg, Task)() {
  return &::drone_interfaces::msg::rosidl_typesupport_introspection_cpp::Task_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
