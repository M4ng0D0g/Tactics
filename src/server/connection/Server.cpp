#include "connection/Server.h"
#include "connection/PacketHandler.h"
#include <iostream>

bool Server::initENet() {
	if(enet_initialize() != 0) {
		std::cerr << "Failed to initialize ENet!" << std::endl;
		return false;
	}
	atexit(enet_deinitialize);
	return true;
}

void Server::setAddress(enet_uint32 host, enet_uint16 port) {
	_address.host = host;
	_address.port = port;
};

bool Server::createServer(int maxClients) {
	_server = enet_host_create(&_address, maxClients, 1, 0, 0);

	if(_server == nullptr) {
		std::cerr << "[X] Failed to create Server!" << std::endl;
		return false;
	}
	_serverRunning = true;
	std::cout << "[O] Successed to create Server on port:" << _address.port << std::endl;
	return true;
}

ENetHost* Server::getHost() {
	return _server;
}

void Server::handleEvents(enet_uint32 time) {
	static ENetEvent event;
	static enet_uint32 timeout = 0;
	if(timeout != time) timeout = time;

	while(enet_host_service(_server, &event, timeout) > 0) {
		char ip[16];
		enet_address_get_host_ip(&event.peer->address, ip, sizeof(ip));
		std::string port = std::to_string(event.peer->address.port);
		std::string output;

		switch(event.type) {
			case ENET_EVENT_TYPE_CONNECT:
				if(_serverRunning) output = "[+] Client " + std::string(ip) + ":" + port + " connected.";
				else {
					output = "[-] Server is shutting down, rejecting new connection from " + std::string(ip) + ":" + port;
					enet_peer_disconnect_now(event.peer, 0);
				}
				std::cout << output << std::endl;
				break;
			
			case ENET_EVENT_TYPE_DISCONNECT:
				output = "[+] Client " + std::string(ip) + ":" + port + " disconnected.";
				std::cout << output << std::endl;
				break;

			case ENET_EVENT_TYPE_RECEIVE:
				PacketHandler::getInstance().receive(event);
				break;

			default:
				break;
		}
	}
}

void Server::runServer() {
	while(_serverRunning) {
		handleEvents(1000);
	}
}

void Server::shutdownServer() {
	if(_server && _serverRunning){
		_serverRunning = false;

		for(size_t i = 0; i < _server->peerCount; i++) {
			ENetPeer* peer = &_server->peers[i];
			if(peer->state != ENET_PEER_STATE_DISCONNECTED) enet_peer_disconnect(peer, 0);
		}
		handleEvents(3000);

		enet_host_destroy(_server);
		_server = nullptr;
		std::cout << "[O] Server shutdown completed." << std::endl;
	}
}