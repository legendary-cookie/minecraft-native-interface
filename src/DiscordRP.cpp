#include <cstring>
#include <iostream>

#include "DiscordRP.hpp"
#include "discord_rpc.h"

using namespace std;

static void
handleDiscordReady (const DiscordUser *connectedUser)
{
  cout << "Discord: connected to user" << connectedUser->username << "#"
       << connectedUser->discriminator << "\n";
}

static void
handleDiscordDisconnected (int errcode, const char *message)
{
  cout << "Discord: disconnected " << errcode << " " << message << "\n";
}

static void
handleDiscordError (int errcode, const char *message)
{
  cout << "Discord: error " << errcode << " " << message;
}

static void
handleDiscordJoin (const char *secret)
{
}

static void
handleDiscordSpectate (const char *secret)
{
}

static void
handleDiscordJoinRequest (const DiscordUser *request)
{
}

void
startDiscordRPC ()
{
  cout << "start";
  DiscordEventHandlers handlers;
  cout << "handlers";
  memset (&handlers, 0, sizeof (handlers));
  cout << "memset";
  handlers.ready = handleDiscordReady;
  handlers.disconnected = handleDiscordDisconnected;
  handlers.errored = handleDiscordError;
  handlers.joinGame = handleDiscordJoin;
  handlers.spectateGame = handleDiscordSpectate;
  handlers.joinRequest = handleDiscordJoinRequest;
  Discord_Initialize ("875055005026111489", &handlers, 1, NULL);
}