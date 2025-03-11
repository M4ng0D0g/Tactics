#include <iostream>
#include "event/PacketHandler.hpp"
#include "Client.hpp"

using namespace std;

void PacketHandler::send(ENetPeer* peer, const char* data) {
	ENetPacket* packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}

void PacketHandler::receive(ENetEvent& event) {
	cout << "[P]"
	<< "\n | Data: " << event.packet->data
	<< "\n | Channel: " << event.channelID
	<< "\n | Client: " << event.peer->address.host << ":" <<  event.peer->address.port
	<< "\n | Length: " << event.packet->dataLength << endl;

	if(!strcmp(reinterpret_cast<char*>(event.packet->data), "server:shutdown")) {
		Client::getInstance().ServerRunning = false;
	}

	enet_packet_destroy(event.packet);
}

