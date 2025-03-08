#include <enet/enet.h>
#include <iostream>
#include "Client.hpp"
#include "event/PacketHandler.hpp"

using namespace std;

bool initENet() {
	if(enet_initialize() != 0) {
		cout << "[X] Failed to initialize ENet!" << endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

ENetHost* createClient() {
    ENetHost* client = enet_host_create(NULL, 1, 1, 0, 0);
    
    if(client == NULL) {
        cout << "[X] Failed to create Client!" << endl;
		return nullptr;
    }
    cout << "[O] Successed to create Client." << endl;
    return client;
}

// bool createPeer(ENetPeer*& peer) {}

bool connect(ENetHost* client, const ENetAddress& address, ENetPeer* peer) {
    ENetEvent event;

    if(peer == nullptr) {
        cout << "[X] No available peers for initiating an ENet connection." << endl;
        return false;
    }

    if(enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        cout << "[+] Connected to " << address.host << ":" << address.port << " successfully." << endl;
        return true;
    } else {
        enet_peer_reset(peer);
        cout << "[X] Failed to connect to " << address.host << ":" << address.port <<  endl;
        return false;
    }
}

void handleEvents(ENetHost* client) {
    static ENetEvent event;

    while(enet_host_service(client, &event, 1000) > 0) {
        switch(event.type) {
            case ENET_EVENT_TYPE_RECEIVE:
                PacketHandler::getInstance().receive(event);
                break;

            default:
                break;
        }
    }
}

void disconnect(ENetHost* client, ENetPeer* peer) {
    ENetEvent event;
    enet_peer_disconnect(peer, 0);
    
    while(enet_host_service(client, &event, 3000) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                cout << "[-] Disconnected from Server successfully." << endl;
                return;
            default:
                break;
        }
    }
}