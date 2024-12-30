// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from drone_interfaces:srv/TaskPush.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__BUILDER_HPP_
#define DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "drone_interfaces/srv/detail/task_push__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskPush_Request_task
{
public:
  Init_TaskPush_Request_task()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::drone_interfaces::srv::TaskPush_Request task(::drone_interfaces::srv::TaskPush_Request::_task_type arg)
  {
    msg_.task = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::srv::TaskPush_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::srv::TaskPush_Request>()
{
  return drone_interfaces::srv::builder::Init_TaskPush_Request_task();
}

}  // namespace drone_interfaces


namespace drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_TaskPush_Response_success
{
public:
  Init_TaskPush_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::drone_interfaces::srv::TaskPush_Response success(::drone_interfaces::srv::TaskPush_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::srv::TaskPush_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::srv::TaskPush_Response>()
{
  return drone_interfaces::srv::builder::Init_TaskPush_Response_success();
}

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__BUILDER_HPP_
