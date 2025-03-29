#include "connection/PacketHandler.h"
#include "connection/Server.h"
#include <iostream>
#include <string>

using namespace std;

// void PacketHandler::registerObserver(std::shared_ptr<ClientManager> observer) {
// 	_observers.insert(observer);
// }

// void PacketHandler::unregisterObserver(std::shared_ptr<ClientManager> observer) {
// 	auto it = std::find_if(_observers.begin(), _observers.end(), [&observer](const std::weak_ptr<ClientManager>& ptr) {
// 		return !ptr.owner_before(observer) && !observer.owner_before(ptr);
// 	});
// 	if(it != _observers.end()) _observers.erase(it);
// }

void PacketHandler::receive(ENetEvent& event) {
	std::string dataString(reinterpret_cast<char*>(event.packet->data), event.packet->dataLength);
	receiveLog(event, dataString);
	nlohmann::json data = getPacketData(dataString);
	
	try {
		if(data.contains("event")) {
			if(data["event"] == "client:closeWindow") {
				Server::getInstance().shutdownServer();
			}
			else if(data["event"] == "client:managerEvent") {
				for(auto observer& : _observers) { observer->notice(event.peer, data); }
			}
		}
	}
	catch(const nlohmann::json::parse_error& e) {
		std::cerr << "JSON parsing error: " << e.what() << std::endl;
	}
	enet_packet_destroy(event.packet);
}

void PacketHandler::receiveLog(ENetEvent& event, std::string& dataString) {
	std::cout << "[Packet]----------------------"
	<< "\n" << dataString
	<< "\n------------------------------"
	<< "\nChannel: " << event.channelID
	<< "\nClient: " << event.peer->address.host << ":" <<  event.peer->address.port
	<< "\nLength: " << event.packet->dataLength << std::endl;
}

nlohmann::json PacketHandler::getPacketData(std::string& dataString) {
	return nlohmann::json::parse(dataString);
}

ENetPacket* PacketHandler::createPacket(const nlohmann::json& obj) {
	std::string jsonStr = obj.dump(4);
	return enet_packet_create(jsonStr.data(), jsonStr.size(), ENET_PACKET_FLAG_RELIABLE);
}

void PacketHandler::send(ENetPeer* peer, const nlohmann::json& obj) {
	ENetPacket* packet = createPacket(obj);
	enet_peer_send(peer, 0, packet);
}

void PacketHandler::broadcast(const nlohmann::json& obj) {
	ENetPacket* packet = createPacket(obj);
	ENetHost* server = Server::getInstance().getHost();
	enet_host_broadcast(server, 0, packet);
	enet_host_flush(server);
}
