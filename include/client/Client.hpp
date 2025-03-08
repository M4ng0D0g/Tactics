#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <enet/enet.h>

bool initENet();
ENetHost* createClient();
bool connect(ENetHost* client, const ENetAddress& address, ENetPeer* peer);
void handleEvents(ENetHost* client);
void disconnect(ENetHost* client, ENetPeer* peer);

#endif