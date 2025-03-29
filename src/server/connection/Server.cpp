#include "connection/Server.h"
#include "connection/PacketHandler.h"
#include <iostream>
#include <json.hpp>

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

void Server::handleEvents() {
	static ENetEvent event;
	while(enet_host_service(_server, &event, 1000) > 0) {
		switch(event.type) {
			case ENET_EVENT_TYPE_CONNECT:
				std::cout << "[+] Client "<< event.peer->address.host
				<< ":" << event.peer->address.port
				<< " connected." << std::endl;

				// _peers.insert(event.peer);
				// if(_peers.size() == 2)
				break;

			case ENET_EVENT_TYPE_RECEIVE:
				PacketHandler::getInstance().receive(event);
				break;

			case ENET_EVENT_TYPE_DISCONNECT:
				std::cout << "[-] Client " << event.peer->address.host
				<< ":" << event.peer->address.port
				<< " disconnected." << std::endl;

				// _peers.extract(event.peer);
				break;

			default:
				break;
		}
	}
}

void Server::runServer() {
	while(_serverRunning) {
		handleEvents();
	}
}

void Server::shutdownServer() {
	if(_server){
		_serverRunning = false;

		nlohmann::json jsonObj;
		jsonObj["event"] = "server:shutdown";
		PacketHandler::getInstance().broadcast(jsonObj);

		//TODO: 優化斷線方式
		static ENetEvent event;
		while(enet_host_service(_server, &event, 3000) > 0) {
			switch(event.type){
				case ENET_EVENT_TYPE_DISCONNECT:
					std::cout << "[-] Client " << event.peer->address.host
					<< ":" << event.peer->address.port
					<< " disconnected." << std::endl;
					break;

				default:
					break;
			}
		}

		enet_host_destroy(_server);
		std::cout << "[O] Server shutdown completed." << std::endl;
	}
}
