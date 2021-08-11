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

    // djz -> 1.16.5
    classes.addClass ("Minecraft", "djz")
        ->getClassAsContext ("Minecraft")
        ->addMethod ("getMinecraft", "C", "()Lnet/minecraft/client/Minecraft;",
                     true)
        ->addField ("is64bit", "ad", "java.lang.Boolean", false);

    Logger::logInfo ("MAPPER initialized");
  }

  inline static JavaClassStructure classes = JavaClassStructure ();
};
