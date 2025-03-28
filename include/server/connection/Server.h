#ifndef SERVER_H
#define SERVER_H

#include <enet/enet.h>
#include <atomic>
#include <mutex>
#include <unordered_map>
#include <string>

class Server {
private:
	Server() {};
	~Server() {};

	ENetHost* _server = nullptr;
	ENetAddress _address;
	std::unordered_map<ENetPeer*, std::string> _peers;

	std::atomic<bool> _serverRunning = false;

public:
	static Server& getInstance() {
		static Server instance;
		return instance;
	}
	Server(const Server&) = delete;
	Server& operator=(const Server&) = delete;

	bool initENet();
	void setAddress(enet_uint32, enet_uint16);
	bool createServer(int);

	ENetHost* getHost();

	void handleEvents();
	void runServer();
	void shutdownServer();

	void registerPeer(ENetPeer*, std::string);
	void unregisterPeer(ENetPeer*);
	std::string getPeerId(ENetPeer*);
};

#endif