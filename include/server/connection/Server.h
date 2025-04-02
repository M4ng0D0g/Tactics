#ifndef SERVER_H
#define SERVER_H

#include <enet/enet.h>

// ***************************************************************************/

class Server {
private:
	Server() {};
	~Server() {};
	ENetHost* _server = nullptr;
	ENetAddress _address;
	
	bool _serverRunning = false;

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

	void handleEvents(enet_uint32);
	void runServer();
	void shutdownServer();
};

#endif