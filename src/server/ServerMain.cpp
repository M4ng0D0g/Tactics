#include <iostream>
#include <enet/enet.h>

using namespace std;

int main(int argc, char** argv) {
	if(enet_initialize() != 0) {
		cout << "An error occurred while initializing ENet." << endl;
		return EXIT_FAILURE;
	}
	atexit(enet_deinitialize);

	ENetAddress address;
	ENetHost* server;
	ENetEvent event;

	address.host = ENET_HOST_ANY;
	address.port = 7777;

	server = enet_host_create(&address, 32, 1, 0, 0);
	if(server == NULL) {
		cout << "An error occurred while trying to create an ENet server host." << endl;
		return EXIT_FAILURE;
	}

	while(true) {
		while(enet_host_service(server, &event, 1000) > 0) {
			switch(event.type) {
				case ENET_EVENT_TYPE_CONNECT:
					cout << "A new client from" << event.peer->address.host
					<< ":" << event.peer->address.port << endl;
					break;
				case ENET_EVENT_TYPE_RECEIVE:
					cout << "A packet of length" << event.packet->dataLength 
					<< "containing" << event.packet->data
					<< "was received from" << event.peer->address.host
					<< ":" << event.peer->address.port
					<< "on channel" << event.channelID << endl;
					break;
				case ENET_EVENT_TYPE_DISCONNECT:
					cout << event.peer->address.host
					<< ":" << event.peer->address.port
					<< "disconnected." << endl;
			}
	
		}
	}
	enet_host_destroy(server);
	return EXIT_SUCCESS;
}