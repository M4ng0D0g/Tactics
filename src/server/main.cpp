#include <iostream>
#include <enet/enet.h>
#include "Server.hpp"

using namespace std;

int main(int argc, char** argv) {
	if(!initENet()) return EXIT_FAILURE;

	ENetAddress address;
	address.host = ENET_HOST_ANY;
	address.port = 7777;

	ENetHost* server;
	if(!createServer(server, address, 32)) return EXIT_FAILURE;

	while(ServerRunning) {
		handleEvents(server);
	}

	shutdownServer(server);
	return EXIT_SUCCESS;
}