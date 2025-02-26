// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice

#ifndef CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__BUILDER_HPP_
#define CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_Goal_image
{
public:
  explicit Init_DarknetCheckForObjects_Goal_image(::citrack_ros_msgs::action::DarknetCheckForObjects_Goal & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Goal image(::citrack_ros_msgs::action::DarknetCheckForObjects_Goal::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Goal msg_;
};

class Init_DarknetCheckForObjects_Goal_id
{
public:
  Init_DarknetCheckForObjects_Goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_Goal_image id(::citrack_ros_msgs::action::DarknetCheckForObjects_Goal::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DarknetCheckForObjects_Goal_image(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_Goal>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_Goal_id();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_Result_bounding_boxes
{
public:
  explicit Init_DarknetCheckForObjects_Result_bounding_boxes(::citrack_ros_msgs::action::DarknetCheckForObjects_Result & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Result bounding_boxes(::citrack_ros_msgs::action::DarknetCheckForObjects_Result::_bounding_boxes_type arg)
  {
    msg_.bounding_boxes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Result msg_;
};

class Init_DarknetCheckForObjects_Result_id
{
public:
  Init_DarknetCheckForObjects_Result_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_Result_bounding_boxes id(::citrack_ros_msgs::action::DarknetCheckForObjects_Result::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DarknetCheckForObjects_Result_bounding_boxes(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_Result>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_Result_id();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_Feedback>()
{
  return ::citrack_ros_msgs::action::DarknetCheckForObjects_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_SendGoal_Request_goal
{
public:
  explicit Init_DarknetCheckForObjects_SendGoal_Request_goal(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request goal(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request msg_;
};

class Init_DarknetCheckForObjects_SendGoal_Request_goal_id
{
public:
  Init_DarknetCheckForObjects_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_SendGoal_Request_goal goal_id(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DarknetCheckForObjects_SendGoal_Request_goal(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_SendGoal_Request_goal_id();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_SendGoal_Response_stamp
{
public:
  explicit Init_DarknetCheckForObjects_SendGoal_Response_stamp(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response stamp(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response msg_;
};

class Init_DarknetCheckForObjects_SendGoal_Response_accepted
{
public:
  Init_DarknetCheckForObjects_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_SendGoal_Response_stamp accepted(::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_DarknetCheckForObjects_SendGoal_Response_stamp(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_SendGoal_Response_accepted();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_GetResult_Request_goal_id
{
public:
  Init_DarknetCheckForObjects_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request goal_id(::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_GetResult_Request_goal_id();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_GetResult_Response_result
{
public:
  explicit Init_DarknetCheckForObjects_GetResult_Response_result(::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response result(::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response msg_;
};

class Init_DarknetCheckForObjects_GetResult_Response_status
{
public:
  Init_DarknetCheckForObjects_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_GetResult_Response_result status(::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_DarknetCheckForObjects_GetResult_Response_result(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_GetResult_Response_status();
}

}  // namespace citrack_ros_msgs


namespace citrack_ros_msgs
{

namespace action
{

namespace builder
{

class Init_DarknetCheckForObjects_FeedbackMessage_feedback
{
public:
  explicit Init_DarknetCheckForObjects_FeedbackMessage_feedback(::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage feedback(::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage msg_;
};

class Init_DarknetCheckForObjects_FeedbackMessage_goal_id
{
public:
  Init_DarknetCheckForObjects_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DarknetCheckForObjects_FeedbackMessage_feedback goal_id(::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_DarknetCheckForObjects_FeedbackMessage_feedback(msg_);
  }

private:
  ::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage>()
{
  return citrack_ros_msgs::action::builder::Init_DarknetCheckForObjects_FeedbackMessage_goal_id();
}

}  // namespace citrack_ros_msgs

#endif  // CITRACK_ROS_MSGS__ACTION__DETAIL__DARKNET_CHECK_FOR_OBJECTS__BUILDER_HPP_
