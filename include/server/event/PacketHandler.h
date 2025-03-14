#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include <enet/enet.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include "./interface/IEventListener.h"

class PacketHandler {
private:
	PacketHandler() {};
	~PacketHandler() {};

	std::unordered_map<std::string, std::vector<EventListener*>> listeners;
	std::unordered_map<int, ENetPeer*> peers;
	// [TODO] client map to send.
	
public:
	static PacketHandler& getInstance() {
		static PacketHandler instance;
		return instance;
	}

	PacketHandler(const PacketHandler&) = delete;
    PacketHandler& operator=(const PacketHandler&) = delete;

	void registerListener(std::string eventType, EventListener* listener) {
		// [TODO]
	};
	void unregisterListener(std::string eventType) {
		// [TODO]
	};
	
    void receive(ENetEvent& event);
	void send(ENetPeer* peer, const char* data);
	void broadcast(ENetHost* server, const char* data);
};

#endif