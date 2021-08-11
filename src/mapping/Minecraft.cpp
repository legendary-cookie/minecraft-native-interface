#include "Minecraft.hpp"
#include <jni.h>

Minecraft::Minecraft (InjectionClient *client)
    : JavaClass::JavaClass (client, "Minecraft")
{
  this->methodGetMinecraft = getMethod ("getMinecraft");
  this->fieldIs64bit = getField ("is64bit");
}

jobject
Minecraft::getMinecraft ()
{
  return getObject (this->methodGetMinecraft);
}