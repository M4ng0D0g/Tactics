#include <enet/enet.h>
#include <iostream>
#include "Server.hpp"

using namespace std;

bool Server::initENet() {
	if(enet_initialize() != 0) {
		cout << "Failed to initialize ENet!" << endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

void Server::setAddress(enet_uint32 host, enet_uint16 port) {
    address.host = host;
	address.port = port;
};

bool Server::createServer(int maxClients) {
    server = enet_host_create(&address, maxClients, 1, 0, 0);

    if(server == nullptr) {
        cout << "[X] Failed to create Server!" << endl;
        return false;
    }
    ServerRunning = true;

    cout << "[O] Successed to create Server on port:" << address.port << endl;
    return true;
}

void Server::sendPacket(ENetPeer* peer, const char* data) {
    packetHandler.send(peer, data);
}

void Server::broadcast(const char* data) {
    packetHandler.broadcast(server, data);
}

void Server::handleEvents() {
    static ENetEvent event;

    while(enet_host_service(server, &event, 1000) > 0) {
        switch(event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "[+] Client " << event.peer->address.host << ":" << event.peer->address.port
                << " connected." << endl;
                //區隔
                peers.insert(event.peer);
                if(peers.size() == 2)
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                PacketHandler::getInstance().receive(event);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                cout << "[-] Client " << event.peer->address.host << ":" << event.peer->address.port
                << " disconnected." << endl;
                peers.extract(event.peer);
                break;

            default:
                break;
        }
    }
}

void Server::shutdownServer() {
    if(server){
        ServerRunning = false;
        packetHandler.broadcast(server, "server:shutdown");
        //TODO: 優化斷線方式
        static ENetEvent event;
        while(enet_host_service(server, &event, 3000) > 0) {
            switch(event.type){
                case ENET_EVENT_TYPE_DISCONNECT:
                    cout << "[-] Client " << event.peer->address.host << ":" << event.peer->address.port
                    << " disconnected." << endl;
                    break;

                default:
                    break;
            }
        }

        enet_host_destroy(server);
        cout << "[O] Server shutdown completed." << endl;
    }
}
