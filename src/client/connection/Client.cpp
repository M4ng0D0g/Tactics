#include "Client.h"
#include "PacketHandler.h"

#include <iostream>

bool Client::initENet() {
	if(enet_initialize() != 0) {
		std::cerr << "[X] Failed to initialize ENet!" << std::endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

void Client::setAddress(const char* host, enet_uint16 port) {
	enet_address_set_host(&_address, host);
	_address.port = port;
};

bool Client::createClient() {
	_client = enet_host_create(NULL, 1, 1, 0, 0);
	if(!_client) {
		std::cerr << "[X] Failed to create Client." << std::endl;
		return false;
	}
	std::cout << "[O] Successed to create Client." << std::endl;
	return true;
}

bool Client::connect() {
	ENetEvent event;
	if(_peer == nullptr) {
		std::cerr << "[X] No available peers for initiating an ENet connection." << std::endl;
		return false;
	}
	if(enet_host_service(_client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
		std::cout << "[+] Connected to " << _address.host << ":" << _address.port
		<< " successfully." << std::endl;

		Client::getInstance().setServerRunning(true);
		return true;
	}
	else {
		enet_peer_reset(_peer);
		std::cout << "[X] Failed to connect to " << _address.host << ":" << _address.port << std::endl;
		return false;
	}
}

void Client::disconnect() {
	ENetEvent event;
	enet_peer_disconnect(_peer, 0);

	while(enet_host_service(_client, &event, 3000) > 0) {
		switch(event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				enet_packet_destroy(event.packet);
				break;

			case ENET_EVENT_TYPE_DISCONNECT:
				std::cout << "[-] Disconnected from Server successfully." << std::endl;
				break;

			default:
				break;
		}
	}
}

bool Client::createPeer() {
	_peer = enet_host_connect(_client, &_address, 1, 0);
	if(!_peer) return false;
	return true;
}

ENetPeer* Client::getPeer() {
	return _peer;
}

void Client::setServerRunning(bool state) {
	_serverRunning = state;
}

void Client::handleEvents() {
	static ENetEvent event;

	while(enet_host_service(_client, &event, 1000) > 0) {
		switch(event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				PacketHandler::getInstance().receive(event);
				break;

			default:
				break;
		}
	}
}

void Client::runClient() {
	while(_serverRunning) {
		handleEvents();
	}
}