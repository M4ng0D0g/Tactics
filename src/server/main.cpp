#include "./connection/Server.h"
#include "./connection/PacketHandler.h"
#include "./gui/ConsoleWindow.h"
// #include "./game/core/GameConfig.h"
// #include "./game/core/Game.h"

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int main(int argc, char** argv) {
	Server& server = Server::getInstance();
	PacketHandler& packetHandler = PacketHandler::getInstance();

	if(!server.initENet()) return EXIT_FAILURE;
	server.setAddress(ENET_HOST_ANY, 7777);
	if(!server.createServer(2)) return EXIT_FAILURE;

	thread serverThread([&server]() { server.runServer(); });
	if(serverThread.joinable()) serverThread.detach();

	ConsoleWindow console;
	console.run();
	
	
	return EXIT_SUCCESS;
}