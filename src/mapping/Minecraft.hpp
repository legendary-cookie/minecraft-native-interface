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

private:
  jmethodID methodGetMinecraft;
  jfieldID fieldIs64bit;
};