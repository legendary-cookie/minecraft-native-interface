#pragma once

/* Client */
#include "InjectionClient.hpp"

/* JNI stuff */
#include <jni.h>
#include <jvmti.h>

/* Util */
#include <string>

/* For mapping classes and methods*/
#include "Mapper.hpp"

#include "Logger.hpp"

class InjectionClient;

class JavaClass {
public:
  JavaClass(InjectionClient *client, std::string className);

  /* Objects */
  template <typename T> jobject getObject(jmethodID method, T values...);

  jobject getObject(jmethodID method);

  jobject getObject(jfieldID field);
  jboolean getBooleanField(jfieldID field, jobject object);

protected:
  jfieldID getField(std::string name);

  jmethodID getMethod(std::string name);

  std::string className;
  InjectionClient *client;
  jclass clazz;

private:
  /* Raw JNI stuff*/
  jfieldID getFieldRAW(std::string name, std::string description,
                       bool isMethodStatic);

  jmethodID getMethodRAW(std::string name, std::string description,
                         bool isMethodStatic);
};