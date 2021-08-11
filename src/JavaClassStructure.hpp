#pragma once

/* For storing the structure */
#include "JavaClassLayout.hpp"
#include "JavaClassMethod.hpp"

/* For logging mappings */
#include "Logger.hpp"

/* Util */
#include <iostream>
#include <map>
#include <string>

class JavaClassStructure
{
public:
  JavaClassStructure (){};

  JavaClassStructure *
  getClassAsContext (std::string name)
  {
    this->context = name;

    return this;
  }

  JavaClassStructure *
  addField (std::string name, std::string obfName, std::string description,
            bool isMethodStatic)
  {
    Logger::logInfo ("OBF NAME \"" + obfName
                     + " (field) is being mapped to: " + name);
    nameToClassLayout[context].addField (std::make_pair (
        name, JavaClassMethod (obfName, description, isMethodStatic)));

    return this;
  }

  JavaClassStructure *
  addMethod (std::string name, std::string obfName, std::string description,
             bool isMethodStatic)
  {
    Logger::logInfo ("OBF NAME \"" + obfName
                     + "\" (method) is being mapped to: " + name);
    JavaClassMethod mth
        = JavaClassMethod (obfName, description, isMethodStatic);
    nameToClassLayout[context].addMethod (std::make_pair (name, mth));

    return this;
  }

  JavaClassStructure *
  addClass (std::string className, std::string obfName)
  {
    JavaClassLayout classLayout = JavaClassLayout (obfName);

    nameToClassLayout.insert (std::make_pair (className, classLayout));

    return this;
  }

  JavaClassLayout
  getClassLayout (std::string className)
  {
    for (auto const &x : nameToClassLayout)
      {
        std::cout << x.first << std::endl;
      }

    return nameToClassLayout[className];
  }

private:
  std::map<std::string, JavaClassLayout> nameToClassLayout;
  std::string context;
};