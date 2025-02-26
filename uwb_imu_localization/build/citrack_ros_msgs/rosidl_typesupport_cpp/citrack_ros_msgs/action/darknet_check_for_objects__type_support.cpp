// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from citrack_ros_msgs:action/DarknetCheckForObjects.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_Goal_type_support_ids_t;

static const _DarknetCheckForObjects_Goal_type_support_ids_t _DarknetCheckForObjects_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_Goal_type_support_symbol_names_t _DarknetCheckForObjects_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Goal)),
  }
};

typedef struct _DarknetCheckForObjects_Goal_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_Goal_type_support_data_t;

static _DarknetCheckForObjects_Goal_type_support_data_t _DarknetCheckForObjects_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_Goal_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Goal>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Goal)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_Result_type_support_ids_t;

static const _DarknetCheckForObjects_Result_type_support_ids_t _DarknetCheckForObjects_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_Result_type_support_symbol_names_t _DarknetCheckForObjects_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Result)),
  }
};

typedef struct _DarknetCheckForObjects_Result_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_Result_type_support_data_t;

static _DarknetCheckForObjects_Result_type_support_data_t _DarknetCheckForObjects_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_Result_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_Result_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_Result_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Result>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Result)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_Feedback_type_support_ids_t;

static const _DarknetCheckForObjects_Feedback_type_support_ids_t _DarknetCheckForObjects_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_Feedback_type_support_symbol_names_t _DarknetCheckForObjects_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Feedback)),
  }
};

typedef struct _DarknetCheckForObjects_Feedback_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_Feedback_type_support_data_t;

static _DarknetCheckForObjects_Feedback_type_support_data_t _DarknetCheckForObjects_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_Feedback_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Feedback>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_Feedback)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_SendGoal_Request_type_support_ids_t;

static const _DarknetCheckForObjects_SendGoal_Request_type_support_ids_t _DarknetCheckForObjects_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_SendGoal_Request_type_support_symbol_names_t _DarknetCheckForObjects_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Request)),
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_SendGoal_Request_type_support_data_t;

static _DarknetCheckForObjects_SendGoal_Request_type_support_data_t _DarknetCheckForObjects_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_SendGoal_Request_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Request)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_SendGoal_Response_type_support_ids_t;

static const _DarknetCheckForObjects_SendGoal_Response_type_support_ids_t _DarknetCheckForObjects_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_SendGoal_Response_type_support_symbol_names_t _DarknetCheckForObjects_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Response)),
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_SendGoal_Response_type_support_data_t;

static _DarknetCheckForObjects_SendGoal_Response_type_support_data_t _DarknetCheckForObjects_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_SendGoal_Response_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal_Response)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_SendGoal_type_support_ids_t;

static const _DarknetCheckForObjects_SendGoal_type_support_ids_t _DarknetCheckForObjects_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_SendGoal_type_support_symbol_names_t _DarknetCheckForObjects_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal)),
  }
};

typedef struct _DarknetCheckForObjects_SendGoal_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_SendGoal_type_support_data_t;

static _DarknetCheckForObjects_SendGoal_type_support_data_t _DarknetCheckForObjects_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_SendGoal_service_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t DarknetCheckForObjects_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_GetResult_Request_type_support_ids_t;

static const _DarknetCheckForObjects_GetResult_Request_type_support_ids_t _DarknetCheckForObjects_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_GetResult_Request_type_support_symbol_names_t _DarknetCheckForObjects_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Request)),
  }
};

typedef struct _DarknetCheckForObjects_GetResult_Request_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_GetResult_Request_type_support_data_t;

static _DarknetCheckForObjects_GetResult_Request_type_support_data_t _DarknetCheckForObjects_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_GetResult_Request_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Request)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_GetResult_Response_type_support_ids_t;

static const _DarknetCheckForObjects_GetResult_Response_type_support_ids_t _DarknetCheckForObjects_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_GetResult_Response_type_support_symbol_names_t _DarknetCheckForObjects_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Response)),
  }
};

typedef struct _DarknetCheckForObjects_GetResult_Response_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_GetResult_Response_type_support_data_t;

static _DarknetCheckForObjects_GetResult_Response_type_support_data_t _DarknetCheckForObjects_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_GetResult_Response_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult_Response)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_GetResult_type_support_ids_t;

static const _DarknetCheckForObjects_GetResult_type_support_ids_t _DarknetCheckForObjects_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_GetResult_type_support_symbol_names_t _DarknetCheckForObjects_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult)),
  }
};

typedef struct _DarknetCheckForObjects_GetResult_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_GetResult_type_support_data_t;

static _DarknetCheckForObjects_GetResult_type_support_data_t _DarknetCheckForObjects_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_GetResult_service_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t DarknetCheckForObjects_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _DarknetCheckForObjects_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _DarknetCheckForObjects_FeedbackMessage_type_support_ids_t;

static const _DarknetCheckForObjects_FeedbackMessage_type_support_ids_t _DarknetCheckForObjects_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _DarknetCheckForObjects_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _DarknetCheckForObjects_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _DarknetCheckForObjects_FeedbackMessage_type_support_symbol_names_t _DarknetCheckForObjects_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_FeedbackMessage)),
  }
};

typedef struct _DarknetCheckForObjects_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _DarknetCheckForObjects_FeedbackMessage_type_support_data_t;

static _DarknetCheckForObjects_FeedbackMessage_type_support_data_t _DarknetCheckForObjects_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _DarknetCheckForObjects_FeedbackMessage_message_typesupport_map = {
  2,
  "citrack_ros_msgs",
  &_DarknetCheckForObjects_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_DarknetCheckForObjects_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_DarknetCheckForObjects_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t DarknetCheckForObjects_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_DarknetCheckForObjects_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage>()
{
  return &::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects_FeedbackMessage)() {
  return get_message_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "citrack_ros_msgs/action/detail/darknet_check_for_objects__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace citrack_ros_msgs
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t DarknetCheckForObjects_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace citrack_ros_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects>()
{
  using ::citrack_ros_msgs::action::rosidl_typesupport_cpp::DarknetCheckForObjects_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  DarknetCheckForObjects_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::citrack_ros_msgs::action::DarknetCheckForObjects::Impl::SendGoalService>();
  DarknetCheckForObjects_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::citrack_ros_msgs::action::DarknetCheckForObjects::Impl::GetResultService>();
  DarknetCheckForObjects_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::citrack_ros_msgs::action::DarknetCheckForObjects::Impl::CancelGoalService>();
  DarknetCheckForObjects_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::citrack_ros_msgs::action::DarknetCheckForObjects::Impl::FeedbackMessage>();
  DarknetCheckForObjects_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::citrack_ros_msgs::action::DarknetCheckForObjects::Impl::GoalStatusMessage>();
  return &DarknetCheckForObjects_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, citrack_ros_msgs, action, DarknetCheckForObjects)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<citrack_ros_msgs::action::DarknetCheckForObjects>();
}

#ifdef __cplusplus
}
#endif
