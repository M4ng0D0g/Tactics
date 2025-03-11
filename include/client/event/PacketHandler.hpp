#ifndef PACKETHANDLER_HPP
#define PACKETHANDLER_HPP

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

	std::unordered_map<std::string, std::vector<IEventListener*>> listeners;
	// TODO: client map to send.
	
public:
	static PacketHandler& getInstance() {
		static PacketHandler instance;
		return instance;
	}

	PacketHandler(const PacketHandler&) = delete;
    PacketHandler& operator=(const PacketHandler&) = delete;

	void registerListener(std::string eventType, IEventListener* listener) {
		// TODO:
	};
	void unregisterListener(std::string eventType) {
		// TODO:
	};

	void send(ENetPeer* peer, const char* data);
	void receive(ENetEvent& event);
};

#endif