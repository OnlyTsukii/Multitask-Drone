// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from drone_interfaces:msg/RawWaypoint.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__BUILDER_HPP_
#define DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "drone_interfaces/msg/detail/raw_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_RawWaypoint_yaw_rate
{
public:
  explicit Init_RawWaypoint_yaw_rate(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  ::drone_interfaces::msg::RawWaypoint yaw_rate(::drone_interfaces::msg::RawWaypoint::_yaw_rate_type arg)
  {
    msg_.yaw_rate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_yaw
{
public:
  explicit Init_RawWaypoint_yaw(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_yaw_rate yaw(::drone_interfaces::msg::RawWaypoint::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_RawWaypoint_yaw_rate(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_velocity
{
public:
  explicit Init_RawWaypoint_velocity(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_yaw velocity(::drone_interfaces::msg::RawWaypoint::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_RawWaypoint_yaw(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_altitude
{
public:
  explicit Init_RawWaypoint_altitude(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_velocity altitude(::drone_interfaces::msg::RawWaypoint::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_RawWaypoint_velocity(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_longitude
{
public:
  explicit Init_RawWaypoint_longitude(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_altitude longitude(::drone_interfaces::msg::RawWaypoint::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_RawWaypoint_altitude(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_latitude
{
public:
  explicit Init_RawWaypoint_latitude(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_longitude latitude(::drone_interfaces::msg::RawWaypoint::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_RawWaypoint_longitude(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_mission
{
public:
  explicit Init_RawWaypoint_mission(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_latitude mission(::drone_interfaces::msg::RawWaypoint::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_RawWaypoint_latitude(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_type
{
public:
  explicit Init_RawWaypoint_type(::drone_interfaces::msg::RawWaypoint & msg)
  : msg_(msg)
  {}
  Init_RawWaypoint_mission type(::drone_interfaces::msg::RawWaypoint::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_RawWaypoint_mission(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

class Init_RawWaypoint_id
{
public:
  Init_RawWaypoint_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RawWaypoint_type id(::drone_interfaces::msg::RawWaypoint::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_RawWaypoint_type(msg_);
  }

private:
  ::drone_interfaces::msg::RawWaypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::msg::RawWaypoint>()
{
  return drone_interfaces::msg::builder::Init_RawWaypoint_id();
}

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__BUILDER_HPP_
