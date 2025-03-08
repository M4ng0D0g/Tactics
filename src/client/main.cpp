
#include <iostream>
#include <thread>
#include <atomic>
#include <enet/enet.h>
#include "Client.hpp"
#include "event/PacketHandler.hpp"

using namespace std;

// atomic<bool> windowClosed(false);

int main(int argc, char** argv) {
	if(!initENet()) return EXIT_FAILURE;
	
	ENetHost* client = createClient();

	ENetAddress address;
	enet_address_set_host(&address, "127.0.0.1");
	address.port = 7777;

	ENetPeer* peer = enet_host_connect(client, &address, 1, 0);
	if(!connect(client, address, peer)) return EXIT_FAILURE;

	PacketHandler::getInstance().send(peer, "This_is_some_test_data.");

	handleEvents(client);

	// std::thread guiThread([](){
    //     TestScreen::open();
    //     windowClosed.store(true);
    // });
    // guiThread.detach();

    disconnect(client, peer);
	
	return EXIT_SUCCESS;
}