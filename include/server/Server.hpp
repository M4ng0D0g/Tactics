#ifndef SERVER_HPP
#define SERVER_HPP

#include <enet/enet.h>
#include <atomic>
#include <mutex>
#include <set>
#include "event/PacketHandler.hpp"

class Server {
private:
	Server() : ServerRunning(false), server(nullptr) {};
	~Server() {};

	PacketHandler& packetHandler = PacketHandler::getInstance();

	ENetHost* server;
	ENetAddress address;
	
	std::set<ENetPeer*> peers;

public:
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;

	static Server& getInstance() {
		static Server instance;
		return instance;
	}

	std::atomic<bool> ServerRunning;

	bool initENet();
	void setAddress(enet_uint32 host, enet_uint16 port);
	bool createServer(int maxClients);
	void sendPacket(ENetPeer* peer, const char* data);
	void broadcast(const char* data);
	void handleEvents();
	void shutdownServer();
};

#endif