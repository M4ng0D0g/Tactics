#include <enet/enet.h>
#include <iostream>
#include "Server.hpp"
#include "event/PacketHandler.hpp"

using namespace std;

#define INET_ADDRSTRLEN 16
bool ServerRunning = false;

bool initENet() {
	if(enet_initialize() != 0) {
		cout << "Failed to initialize ENet!" << endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

bool createServer(ENetHost*& server, ENetAddress& address, int maxClients) {
    server = enet_host_create(&address, maxClients, 1, 0, 0);

    if(server == nullptr) {
        cout << "[X] Failed to create Server!" << endl;
        return false;
    }
    ServerRunning = true;

    cout << "[O] Successed to create Server on port:" << address.port << endl;
    return true;
}

void handleEvents(ENetHost* server) {
    static ENetEvent event;

    while(enet_host_service(server, &event, 1000) > 0) {
        switch(event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "[+] Client " << event.peer->address.host << ":" << event.peer->address.port
                << " connected." << endl;
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                PacketHandler::getInstance().receive(event);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << "[-] Client " << event.peer->address.host << ":" << event.peer->address.port
                << " disconnected." << endl;
                break;

            default:
                break;
        }
    }
}

void shutdownServer(ENetHost* server) {
    if(server) enet_host_destroy(server);
    ServerRunning = false;

    cout << "[O] Server shutdown completed." << endl;
}
