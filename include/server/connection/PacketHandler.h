#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include "interface/IClientEvent.h"
#include "game/manager/ClientManager.h"
#include <enet/enet.h>
#include <string>
#include <vector>
#include <memory>
#include <json.hpp>

// ***************************************************************************/

class PacketHandler : public IClientEvent {
private:
	PacketHandler() {};
	~PacketHandler() {};
	
	std::vector<std::shared_ptr<ClientManager>> _managers;

public:
	static PacketHandler& getInstance() {
		static PacketHandler instance;
		return instance;
	}
	PacketHandler(const PacketHandler&) = delete;
	PacketHandler& operator=(const PacketHandler&) = delete;

	void registerManager(std::shared_ptr<ClientManager>);
	void unregisterManager(std::shared_ptr<ClientManager>);
	
	void receive(ENetEvent&);
	void receiveLog(ENetEvent&, const std::string&);
	nlohmann::json parseData(const std::string&);

	ENetPacket* createPacket(const nlohmann::json&);
	void send(ENetPeer*, const nlohmann::json&);
	void broadcast(const nlohmann::json&);
};

#endif