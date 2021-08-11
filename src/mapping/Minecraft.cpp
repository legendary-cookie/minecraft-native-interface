#include "Minecraft.hpp"
#include "../InjectionClient.hpp"
#include <jni.h>

Minecraft::Minecraft (InjectionClient *client)
    : JavaClass::JavaClass (client, "Minecraft")
{
  this->methodGetMinecraft = getMethod ("getMinecraft");
  this->methodStop = getMethod ("stop");
}

jobject
Minecraft::getMinecraft ()
{
  return getObject (this->methodGetMinecraft);
}

void
Minecraft::stop ()
{
  
}