#include "DiscordRP.hpp"
#include "discord_rpc.h"
#include <cstdio>
#include <cstring>

static void
handleDiscordReady (const DiscordUser *connectedUser)
{
  printf ("\nDiscord: connected to user %s#%s - %s\n", connectedUser->username,
          connectedUser->discriminator, connectedUser->userId);
}

static void
handleDiscordDisconnected (int errcode, const char *message)
{
  printf ("\nDiscord: disconnected (%d: %s)\n", errcode, message);
}

static void
handleDiscordError (int errcode, const char *message)
{
  printf ("\nDiscord: error (%d: %s)\n", errcode, message);
}

static void
handleDiscordJoin (const char *secret)
{
  printf ("\nDiscord: join (%s)\n", secret);
}

static void
handleDiscordSpectate (const char *secret)
{
  printf ("\nDiscord: spectate (%s)\n", secret);
}

static void
handleDiscordJoinRequest (const DiscordUser *request)
{
  int response = -1;
  char yn[4];
  printf ("\nDiscord: join request from %s#%s - %s\n", request->username,
          request->discriminator, request->userId);
}

void
startDiscordRPC ()
{
  DiscordEventHandlers handlers;
  memset (&handlers, 0, sizeof (handlers));
  handlers.ready = handleDiscordReady;
  handlers.disconnected = handleDiscordDisconnected;
  handlers.errored = handleDiscordError;
  handlers.joinGame = handleDiscordJoin;
  handlers.spectateGame = handleDiscordSpectate;
  handlers.joinRequest = handleDiscordJoinRequest;
  Discord_Initialize ("875055005026111489", &handlers, 1, NULL);
}