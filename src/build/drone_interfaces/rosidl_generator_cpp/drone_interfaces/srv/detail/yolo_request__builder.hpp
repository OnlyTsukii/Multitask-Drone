// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from drone_interfaces:srv/YoloRequest.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__BUILDER_HPP_
#define DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "drone_interfaces/srv/detail/yolo_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_YoloRequest_Request_start
{
public:
  Init_YoloRequest_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::drone_interfaces::srv::YoloRequest_Request start(::drone_interfaces::srv::YoloRequest_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::srv::YoloRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::srv::YoloRequest_Request>()
{
  return drone_interfaces::srv::builder::Init_YoloRequest_Request_start();
}

}  // namespace drone_interfaces


namespace drone_interfaces
{

namespace srv
{

namespace builder
{

class Init_YoloRequest_Response_success
{
public:
  Init_YoloRequest_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::drone_interfaces::srv::YoloRequest_Response success(::drone_interfaces::srv::YoloRequest_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::srv::YoloRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::srv::YoloRequest_Response>()
{
  return drone_interfaces::srv::builder::Init_YoloRequest_Response_success();
}

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__SRV__DETAIL__YOLO_REQUEST__BUILDER_HPP_
