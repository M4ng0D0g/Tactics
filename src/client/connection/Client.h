#ifndef CLIENT_H
#define CLIENT_H

#include <enet/enet.h>
#include <atomic>

class Client {
private:
	Client() {};
	~Client() {};

	ENetHost* _client = nullptr;
	ENetAddress _address;
	ENetPeer* _peer = nullptr;

	std::atomic<bool> _serverRunning = false;

public:
	static Client& getInstance() {
		static Client instance;
		return instance;
	}
	Client(const Client&) = delete;
	Client& operator=(const Client&) = delete;

	bool initENet();
	void setAddress(const char* host, enet_uint16 port);
	bool createClient();
	bool createPeer();
	bool connect();
	void disconnect();
	
	ENetPeer* getPeer();
	void setServerRunning(bool);

	void handleEvents();
	void runClient();
};


#endif