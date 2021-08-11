#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Logger
{
public:
  static void
  logError (std::string message)
  {
    std::cout << "[ERROR] " << message << std::endl;
  }

  static void
  logSuccess (std::string message)
  {
    std::cout << "[SUCCESS] " << message << std::endl;
  }

  static void
  logInfo (std::string message)
  {
    std::cout << "[INFO] " << message << std::endl;
  }

  static void
  logFancy (std::string message)
  {
    std::cout << message << std::endl;
  }

  static void
  logSequential ()
  {
    std::cout << count << std::endl;
    count += 1;
  }

private:
  inline static int count = 0;
};
