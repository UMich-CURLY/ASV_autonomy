// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from citrack_ros_msgs:msg/DarknetBoundingBox.idl
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
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__struct.h"
#include "citrack_ros_msgs/msg/detail/darknet_bounding_box__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool citrack_ros_msgs__msg__darknet_bounding_box__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
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
    assert(strncmp("citrack_ros_msgs.msg._darknet_bounding_box.DarknetBoundingBox", full_classname_dest, 61) == 0);
  }
  citrack_ros_msgs__msg__DarknetBoundingBox * ros_message = _ros_message;
  {  // probability
    PyObject * field = PyObject_GetAttrString(_pymsg, "probability");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->probability = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // xmin
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmin = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // ymin
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymin");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymin = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // xmax
    PyObject * field = PyObject_GetAttrString(_pymsg, "xmax");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->xmax = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // ymax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ymax");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ymax = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // class_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "class_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->class_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * citrack_ros_msgs__msg__darknet_bounding_box__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DarknetBoundingBox */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("citrack_ros_msgs.msg._darknet_bounding_box");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DarknetBoundingBox");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  citrack_ros_msgs__msg__DarknetBoundingBox * ros_message = (citrack_ros_msgs__msg__DarknetBoundingBox *)raw_ros_message;
  {  // probability
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->probability);
    {
      int rc = PyObject_SetAttrString(_pymessage, "probability", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmin
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->xmin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymin
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->ymin);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymin", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // xmax
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->xmax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "xmax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ymax
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->ymax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ymax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // class_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->class_name.data,
      strlen(ros_message->class_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "class_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
