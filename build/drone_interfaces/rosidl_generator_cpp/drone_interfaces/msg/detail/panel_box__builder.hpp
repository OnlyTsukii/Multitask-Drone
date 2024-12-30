// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from drone_interfaces:msg/PanelBox.idl
// generated code does not contain a copyright notice

#ifndef DRONE_INTERFACES__MSG__DETAIL__PANEL_BOX__BUILDER_HPP_
#define DRONE_INTERFACES__MSG__DETAIL__PANEL_BOX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "drone_interfaces/msg/detail/panel_box__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_PanelBox_h
{
public:
  explicit Init_PanelBox_h(::drone_interfaces::msg::PanelBox & msg)
  : msg_(msg)
  {}
  ::drone_interfaces::msg::PanelBox h(::drone_interfaces::msg::PanelBox::_h_type arg)
  {
    msg_.h = std::move(arg);
    return std::move(msg_);
  }

private:
  ::drone_interfaces::msg::PanelBox msg_;
};

class Init_PanelBox_w
{
public:
  explicit Init_PanelBox_w(::drone_interfaces::msg::PanelBox & msg)
  : msg_(msg)
  {}
  Init_PanelBox_h w(::drone_interfaces::msg::PanelBox::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_PanelBox_h(msg_);
  }

private:
  ::drone_interfaces::msg::PanelBox msg_;
};

class Init_PanelBox_y
{
public:
  explicit Init_PanelBox_y(::drone_interfaces::msg::PanelBox & msg)
  : msg_(msg)
  {}
  Init_PanelBox_w y(::drone_interfaces::msg::PanelBox::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PanelBox_w(msg_);
  }

private:
  ::drone_interfaces::msg::PanelBox msg_;
};

class Init_PanelBox_x
{
public:
  Init_PanelBox_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanelBox_y x(::drone_interfaces::msg::PanelBox::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PanelBox_y(msg_);
  }

private:
  ::drone_interfaces::msg::PanelBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::drone_interfaces::msg::PanelBox>()
{
  return drone_interfaces::msg::builder::Init_PanelBox_x();
}

}  // namespace drone_interfaces

#endif  // DRONE_INTERFACES__MSG__DETAIL__PANEL_BOX__BUILDER_HPP_
