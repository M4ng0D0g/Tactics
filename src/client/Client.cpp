#include "Client.h"
#include "event/PacketHandler.h"

#include <iostream>

using namespace std;

bool Client::initENet() {
	if(enet_initialize() != 0) {
		cout << "[X] Failed to initialize ENet!" << endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

void Client::setAddress(const char* host, enet_uint16 port) {
    enet_address_set_host(&address, host);
	address.port = port;
};

bool Client::createClient() {
    client = enet_host_create(NULL, 1, 1, 0, 0);
    if(!client) {
        cout << "[X] Failed to create Client." << endl;
		return false;
    }
    cout << "[O] Successed to create Client." << endl;
    return true;
}

bool Client::createPeer() {
    peer = enet_host_connect(client, &address, 1, 0);
    if(!peer) {
        // cout << "[X] Failed to create Peer." << endl;
        return false;
    }
    // cout << "[O] Successed to create Peer." << endl;
    return true;
}

bool Client::connect() {
    ENetEvent event;

    if(peer == nullptr) {
        cout << "[X] No available peers for initiating an ENet connection." << endl;
        return false;
    }

    if(enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        cout << "[+] Connected to " << address.host << ":" << address.port << " successfully." << endl;
        Client::getInstance().ServerRunning = true;
        return true;
    } else {
        enet_peer_reset(peer);
        cout << "[X] Failed to connect to " << address.host << ":" << address.port <<  endl;
        return false;
    }
}

void Client::sendPacket(const char* data) {
    packetHandler.send(peer, data);
};

void Client::handleEvents() {
    static ENetEvent event;

    while(enet_host_service(client, &event, 1000) > 0) {
        switch(event.type) {
            case ENET_EVENT_TYPE_RECEIVE:
                packetHandler.receive(event);
                break;

            default:
                break;
        }
    }
}

void Client::disconnect() {
    ENetEvent event;
    enet_peer_disconnect(peer, 0);
    
    while(enet_host_service(client, &event, 3000) > 0) {
        switch(event.type) {
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

