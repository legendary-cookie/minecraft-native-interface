#include "InjectionClient.hpp"
#include "Logger.hpp"

#ifdef __linux__

#include <chrono>
#include <stdio.h>
#include <thread>

void f1 () __attribute__ ((constructor (101)));
void
f1 ()
{
  std::ios_base::Init i;
  Logger::logInfo ("Initialized ios_base");
}

static void init (void) __attribute__ ((constructor));
static void
start ()
{
  Logger::logInfo ("Starting...");
  InjectionClient ();
  return;
}

static void
init (void)
{
  std::thread t (start);
}

#elif _WIN32
#include <Windows.h>
using namespace std;
void
injectDLL ()
{
  AllocConsole ();
  SetConsoleCtrlHandler (NULL, true);
  FILE *fileIn;
  FILE *fileOut;

  freopen_s (&fileIn, "CONIN$", "r", stdin);
  freopen_s (&fileOut, "CONOUT$", "w", stdout);
  freopen_s (&fileOut, "CONOUT$", "w", stderr);
  Logger::logSuccess ("Injection succesfull");

  InjectionClient ();
}

BOOL APIENTRY
DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if (fdwReason == DLL_PROCESS_ATTACH)
    {
      CreateThread (nullptr, 0, (LPTHREAD_START_ROUTINE)injectDLL, nullptr, 0,
                    nullptr);
    }

  return TRUE;
}
#else
#error Your OS is not supported
#endif
