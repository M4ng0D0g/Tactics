
#include <enet/enet.h>
#include <iostream>
#include <thread>
#include <atomic>
#include "./gui/TestScreen.h"

using namespace std;

atomic<bool> windowClosed(false);

int main(int argc, char** argv) {
	if(enet_initialize() != 0) {
		cout << "An error occurred while initializing ENet." << endl;
		return EXIT_FAILURE;
	}
	atexit(enet_deinitialize);
	
	ENetHost* client = enet_host_create(NULL, 1, 1, 0, 0);

	if(client == NULL) {
		cout << "An error occurred while trying to create an ENet server host." << endl;
		return EXIT_FAILURE;
	}

	ENetAddress address;
	ENetEvent event;
	ENetPeer* peer;

	enet_address_set_host(&address, "127.0.0.1");
	address.port = 7777;

	peer = enet_host_connect(client, &address, 1, 0);
	if(peer == NULL) {
		cout << "No available peers for initiating an ENet connection." << endl;
		return EXIT_FAILURE;
	}

	if(enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
		puts("Connection to 127.0.0.1:7777 successed.");
	} else {
		enet_peer_reset(peer);
		puts("Connection to 127.0.0.1:7777 failed.");
		return EXIT_SUCCESS;
	}

	while(enet_host_service(client, &event, 1000) > 0) {
		switch(event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				cout << "A packet of length" << event.packet->dataLength 
				<< "containing" << event.packet->data
				<< "was received from" << event.peer->address.host
				<< ":" << event.peer->address.port
				<< "on channel" << event.channelID << endl;
				break;
		}

	}

	std::thread guiThread([](){
        TestScreen::open();
        windowClosed.store(true);
    });
    guiThread.detach();

    enet_peer_disconnect(peer, 0);

    while (enet_host_service(client, &event, 3000) > 0) {
        switch(event.type) {
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                puts("Disconnection succeeded.");
                break;
            default:
                break;
        }
    }
	
	return EXIT_SUCCESS;
}