#include "Logger.hpp"
#include "InjectionClient.hpp"
#include <chrono>
#include <stdio.h>
#include <thread>

void f1() __attribute__((constructor(101)));
void f1() {
  std::ios_base::Init i;
  Logger::logInfo("Initialized ios_base");
}

static void init(void) __attribute__((constructor));

void start() {
  Logger::logInfo("Starting...");
  InjectionClient();
  return;
}

static void init(void) {
  std::thread t(start);
  t.join();
}
