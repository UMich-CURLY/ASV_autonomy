// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from citrack_ros_msgs:msg/CustomTag.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "citrack_ros_msgs/msg/detail/custom_tag__struct.h"
#include "citrack_ros_msgs/msg/detail/custom_tag__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool citrack_ros_msgs__msg__custom_tag__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("citrack_ros_msgs.msg._custom_tag.CustomTag", full_classname_dest, 42) == 0);
  }
  citrack_ros_msgs__msg__CustomTag * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // pose_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pose_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // orientation_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "orientation_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->orientation_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * citrack_ros_msgs__msg__custom_tag__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CustomTag */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("citrack_ros_msgs.msg._custom_tag");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CustomTag");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  citrack_ros_msgs__msg__CustomTag * ros_message = (citrack_ros_msgs__msg__CustomTag *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pose_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // orientation_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->orientation_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "orientation_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
