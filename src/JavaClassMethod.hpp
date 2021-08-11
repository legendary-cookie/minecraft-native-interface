#pragma once

/* Util */
#include <string>

class JavaClassMethod
{
public:
  JavaClassMethod () {}

  JavaClassMethod (std::string methodName, std::string description,
                   bool isMethodStatic)
      : methodName (methodName), description (description),
        isMethodStatic (isMethodStatic)
  {
  }

  std::string &
  getMethodName ()
  {
    return methodName;
  }

  std::string &
  getDescription ()
  {
    return description;
  }

  bool
  getWhetherMethodIsStatic ()
  {
    return isMethodStatic;
  }

private:
  std::string methodName;
  std::string description;

  bool isMethodStatic;
};