#include "PacketHandler.h"
#include "Client.h"

#include <iostream>
#include <string>

void PacketHandler::receive(ENetEvent& event) {
	std::string dataString(reinterpret_cast<char*>(event.packet->data), event.packet->dataLength);
	receiveLog(event, dataString);
	nlohmann::json jsonObj = getPacketData(dataString);
	
	try {
		if(jsonObj.contains("event")) {
			if(jsonObj["event"] == "server:shutdown") {
				Client::getInstance().setServerRunning(false);
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

void PacketHandler::send(const nlohmann::json& obj) {
	ENetPacket* packet = createPacket(obj);
	ENetPeer* peer = Client::getInstance().getPeer();
	enet_peer_send(peer, 0, packet);
}


