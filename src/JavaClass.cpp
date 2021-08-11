#include "JavaClass.hpp"
#include <jni.h>

JavaClass::JavaClass (InjectionClient *client, std::string className)
    : client (client), className (className)
{
  this->clazz = client->getENV ()->FindClass (
      Mapper::getNameOfClass (className).c_str ());
}

jmethodID
JavaClass::getMethod (std::string name)
{
  JavaClassMethod method = Mapper::getClass (className).getMethod (name);

  return getMethodRAW (
      method.getMethodName (),
      Mapper::getClass (className).getMethod (name).getDescription (),
      method.getWhetherMethodIsStatic ());
}

jfieldID
JavaClass::getField (std::string name)
{
  JavaClassMethod field = Mapper::getClass (className).getField (name);

  return getFieldRAW (field.getMethodName (), field.getDescription (),
                      field.getWhetherMethodIsStatic ());
}

jfieldID
JavaClass::getFieldRAW (std::string name, std::string description,
                        bool isMethodStatic)
{
  return isMethodStatic ? client->getENV ()->GetStaticFieldID (
             clazz, name.c_str (), description.c_str ())
                        : client->getENV ()->GetFieldID (clazz, name.c_str (),
                                                         description.c_str ());
}

jmethodID
JavaClass::getMethodRAW (std::string name, std::string description,
                         bool isMethodStatic)
{
  return isMethodStatic
             ? client->getENV ()->GetStaticMethodID (clazz, name.c_str (),
                                                     description.c_str ())
             : client->getENV ()->GetMethodID (clazz, name.c_str (),
                                               description.c_str ());
}

template <typename T>
jobject
JavaClass::getObject (jmethodID method, T values...)
{
  return client->getENV ()->CallStaticObjectMethod (clazz, method, values);
}

jobject
JavaClass::getObject (jmethodID method)
{
  return client->getENV ()->CallStaticObjectMethod (clazz, method);
}