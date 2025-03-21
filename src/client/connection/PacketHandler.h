#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include <enet/enet.h>
#include <unordered_set>
#include <memory>
#include <json.hpp>

class PacketHandler {
private:
	PacketHandler() {};
	~PacketHandler() {};

	// std::unordered_set<std::weak_ptr<ClientManager>, std::owner_less<std::weak_ptr<ClientManager>>> _observers;
	
public:
	static PacketHandler& getInstance() {
		static PacketHandler instance;
		return instance;
	}
	PacketHandler(const PacketHandler&) = delete;
	PacketHandler& operator=(const PacketHandler&) = delete;

	// void registerObserver(std::shared_ptr<ClientManager>);
	// void unregisterObserver(std::shared_ptr<ClientManager>);

	void receive(ENetEvent&);
	void receiveLog(ENetEvent&, std::string&);
	nlohmann::json getPacketData(std::string&);

	ENetPacket* createPacket(const nlohmann::json&);
	void send(const nlohmann::json&);
};

#endif