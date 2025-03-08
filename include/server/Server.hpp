#ifndef SERVER_HPP
#define SERVER_HPP

#include <enet/enet.h>

extern bool ServerRunning;

bool initENet();
bool createServer(ENetHost*& server, ENetAddress& address, int maxClients);
void handleEvents(ENetHost* server);
void shutdownServer(ENetHost* server);

#endif