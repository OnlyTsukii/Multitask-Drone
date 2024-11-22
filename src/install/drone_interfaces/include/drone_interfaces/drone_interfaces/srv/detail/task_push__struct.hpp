// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from drone_interfaces:srv/TaskPush.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__STRUCT_HPP_
#define DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'task'
#include "drone_interfaces/msg/detail/task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__drone_interfaces__srv__TaskPush_Request __attribute__((deprecated))
#else
# define DEPRECATED__drone_interfaces__srv__TaskPush_Request __declspec(deprecated)
#endif

namespace drone_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskPush_Request_
{
  using Type = TaskPush_Request_<ContainerAllocator>;

  explicit TaskPush_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_init)
  {
    (void)_init;
  }

  explicit TaskPush_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _task_type =
    drone_interfaces::msg::Task_<ContainerAllocator>;
  _task_type task;

  // setters for named parameter idiom
  Type & set__task(
    const drone_interfaces::msg::Task_<ContainerAllocator> & _arg)
  {
    this->task = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__drone_interfaces__srv__TaskPush_Request
    std::shared_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__drone_interfaces__srv__TaskPush_Request
    std::shared_ptr<drone_interfaces::srv::TaskPush_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskPush_Request_ & other) const
  {
    if (this->task != other.task) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskPush_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskPush_Request_

// alias to use template instance with default allocator
using TaskPush_Request =
  drone_interfaces::srv::TaskPush_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace drone_interfaces


#ifndef _WIN32
# define DEPRECATED__drone_interfaces__srv__TaskPush_Response __attribute__((deprecated))
#else
# define DEPRECATED__drone_interfaces__srv__TaskPush_Response __declspec(deprecated)
#endif

namespace drone_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskPush_Response_
{
  using Type = TaskPush_Response_<ContainerAllocator>;

  explicit TaskPush_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit TaskPush_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__drone_interfaces__srv__TaskPush_Response
    std::shared_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__drone_interfaces__srv__TaskPush_Response
    std::shared_ptr<drone_interfaces::srv::TaskPush_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskPush_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskPush_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskPush_Response_

// alias to use template instance with default allocator
using TaskPush_Response =
  drone_interfaces::srv::TaskPush_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace drone_interfaces

namespace drone_interfaces
{

namespace srv
{

struct TaskPush
{
  using Request = drone_interfaces::srv::TaskPush_Request;
  using Response = drone_interfaces::srv::TaskPush_Response;
};

}  // namespace srv

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__SRV__DETAIL__TASK_PUSH__STRUCT_HPP_