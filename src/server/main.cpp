#include <iostream>
#include <enet/enet.h>
#include "Server.hpp"

using namespace std;

int main(int argc, char** argv) {
	Server& server = Server::getInstance();

	if(!server.initENet()) return EXIT_FAILURE;
	server.setAddress(ENET_HOST_ANY, 7777);
	if(!server.createServer(2)) return EXIT_FAILURE;

	//TODO: 抽出分工、排隊
	thread mainLoop([&server]() {
		while(server.ServerRunning) {
			server.handleEvents();
		}
	});
	mainLoop.join();
	
	return EXIT_SUCCESS;
}