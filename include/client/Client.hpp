#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <enet/enet.h>
#include <atomic>
#include "event/PacketHandler.hpp"

class Client {
private:
	Client() : ServerRunning(false), client(nullptr), peer(nullptr) {};
	~Client() {};

	PacketHandler& packetHandler = PacketHandler::getInstance();

	ENetHost* client;
	ENetAddress address;
	ENetPeer* peer;
public:

	Client(const Client&) = delete;
	Client& operator=(const Client&) = delete;

	static Client& getInstance() {
		static Client instance;
		return instance;
	}

	std::atomic<bool> ServerRunning;
	
	bool initENet();
	void setAddress(const char* host, enet_uint16 port);
	bool createClient();
	bool createPeer();
	bool connect();
	void sendPacket(const char* data);
	void handleEvents();
	void disconnect();
	
};


#endif