#include <iostream>
#include "event/PacketHandler.hpp"
#include "Server.hpp"

using namespace std;

void PacketHandler::receive(ENetEvent& event) {
	cout << "[P]"
	<< "\n | Data: " << event.packet->data
	<< "\n | Channel: " << event.channelID
	<< "\n | Client: " << event.peer->address.host << ":" <<  event.peer->address.port
	<< "\n | Length: " << event.packet->dataLength << endl;

	if(!strcmp(reinterpret_cast<char*>(event.packet->data), "client:closeWindow")) {
		Server::getInstance().shutdownServer();
	}

	enet_packet_destroy(event.packet);
}

void PacketHandler::send(ENetPeer* peer, const char* data) {
	ENetPacket* packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}

void PacketHandler::broadcast(ENetHost* server, const char* data) {
	ENetPacket* packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_host_broadcast(server, 0, packet);
	enet_host_flush(server);
}
