#include "Minecraft.hpp"
#include <jni.h>

Minecraft::Minecraft (InjectionClient *client)
    : JavaClass::JavaClass (client, "Minecraft")
{
  this->methodGetMinecraft = getMethod ("getMinecraft");
}

jobject
Minecraft::getMinecraft ()
{
  return getObject (this->methodGetMinecraft);
}