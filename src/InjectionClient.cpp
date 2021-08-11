#include "InjectionClient.hpp"

#include "mapping/Minecraft.hpp"

InjectionClient::InjectionClient ()
{
  jsize vmCount;

  if (JNI_GetCreatedJavaVMs (&JVM, 1, &vmCount) != JNI_OK || vmCount == 0)
    {
      Logger::logError ("Failed to get the VM");

      return;
    }

  jint result = JVM->GetEnv ((void **)&ENV, JNI_VERSION_1_8);

  if (result == JNI_EDETACHED)
    {
      result = JVM->AttachCurrentThread ((void **)&ENV, nullptr);
    }
  if (result != JNI_OK)
    {
      Logger::logError ("Failed to attach to thread");
      return;
    }

  Logger::logSuccess ("Attached to JVM");
  Logger::logSuccess ("Masochist client was loaded, and Minecraft was found");
  Logger::logSuccess ("Starting MAPPER V1.0.0");

  Mapper::init ();

  Minecraft *mc = new Minecraft (this);
}

JavaVM *
InjectionClient::getJVM ()
{
  return this->JVM;
}

JNIEnv *
InjectionClient::getENV ()
{
  return this->ENV;
}