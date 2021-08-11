#pragma once

/* For storing the mapping */
#include "JavaClassLayout.hpp"
#include "JavaClassStructure.hpp"
#include "Logger.hpp"

class Mapper
{
public:
  static JavaClassLayout
  getClass (std::string className)
  {
    return classes.getClassLayout (className);
  }

  static std::string
  getNameOfClass (std::string className)
  {
    return getClass (className).getClassName ();
  }

  static void
  init ()
  {
    /*
    This feels very iffy
    Maybe use mcp mapping files to auto map?
    */

    // ave -> 1.8.9
    classes.addClass ("Minecraft", "ave")
        ->getClassAsContext ("Minecraft")
        ->addMethod ("getMinecraft", "A", "()Lnet/minecraft/client/Minecraft;",
                     true)
        ->addMethod ("stop", "g", "()V", false);

    Logger::logInfo ("MAPPER initialized");
  }

  inline static JavaClassStructure classes = JavaClassStructure ();
};
