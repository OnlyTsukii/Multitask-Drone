// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from drone_interfaces:msg/RawWaypoint.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_HPP_
#define DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__drone_interfaces__msg__RawWaypoint __attribute__((deprecated))
#else
# define DEPRECATED__drone_interfaces__msg__RawWaypoint __declspec(deprecated)
#endif

namespace drone_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RawWaypoint_
{
  using Type = RawWaypoint_<ContainerAllocator>;

  explicit RawWaypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->type = 0;
      this->mission = 0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0f;
      this->velocity = 0.0f;
      this->yaw = 0.0;
      this->yaw_rate = 0.0;
    }
  }

  explicit RawWaypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->type = 0;
      this->mission = 0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0f;
      this->velocity = 0.0f;
      this->yaw = 0.0;
      this->yaw_rate = 0.0;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;
  using _type_type =
    int8_t;
  _type_type type;
  using _mission_type =
    int8_t;
  _mission_type mission;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _altitude_type =
    float;
  _altitude_type altitude;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _yaw_rate_type =
    double;
  _yaw_rate_type yaw_rate;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__type(
    const int8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__mission(
    const int8_t & _arg)
  {
    this->mission = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const float & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__yaw_rate(
    const double & _arg)
  {
    this->yaw_rate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    drone_interfaces::msg::RawWaypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const drone_interfaces::msg::RawWaypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::msg::RawWaypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::msg::RawWaypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__drone_interfaces__msg__RawWaypoint
    std::shared_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__drone_interfaces__msg__RawWaypoint
    std::shared_ptr<drone_interfaces::msg::RawWaypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RawWaypoint_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->mission != other.mission) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->yaw_rate != other.yaw_rate) {
      return false;
    }
    return true;
  }
  bool operator!=(const RawWaypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RawWaypoint_

// alias to use template instance with default allocator
using RawWaypoint =
  drone_interfaces::msg::RawWaypoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__MSG__DETAIL__RAW_WAYPOINT__STRUCT_HPP_
