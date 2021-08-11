#pragma once

/* Util */
#include "Logger.hpp"
#include <map>
#include <string>
/* Individual methods */
#include "JavaClassMethod.hpp"

class JavaClassLayout {
public:
  JavaClassLayout() {}

  JavaClassLayout(std::string className) : className(className) {}

  JavaClassMethod getField(std::string name) { return this->fields[name]; }

  void addField(std::pair<std::string, JavaClassMethod> field) {
    this->fields.insert(field);
  }

  JavaClassMethod getMethod(std::string name) { return this->methods.at(name); }

  std::string getClassName() { return className; }

  void addMethod(std::pair<std::string, JavaClassMethod> method) {
    this->methods.insert(std::make_pair(method.first, method.second));
  }

private:
  std::map<std::string, JavaClassMethod> fields = {};
  std::map<std::string, JavaClassMethod> methods = {};

  std::string className;
};