#pragma once

/* JNI stuff */
#include <jvmti.h>

/* Needed for logging */
#include "Logger.hpp"

/* Util */
#include "Mapper.hpp"
#include <exception>
#include <sstream>
#include <string>
#include <vector>

class InjectionClient {
public:
  InjectionClient();

  JavaVM *getJVM();
  JNIEnv *getENV();

private:
  JavaVM *JVM;
  JNIEnv *ENV;
};