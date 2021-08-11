#pragma once

/* Java mapped classes */
#include "../JavaClass.hpp"

#include "../InjectionClient.hpp"
#include <jni.h>

class InjectionClient;

class Minecraft : public JavaClass
{
public:
  Minecraft (InjectionClient *client);

  jobject getMinecraft ();
  void stop();

private:
  jmethodID methodGetMinecraft;
  jmethodID methodStop;
};