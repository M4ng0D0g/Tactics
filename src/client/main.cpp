
#include <iostream>
#include <thread>
#include <atomic>
#include <enet/enet.h>
#include "Client.hpp"
#include "gui/TestScreen.h"

using namespace std;

// atomic<bool> windowClosed(false);

int main(int argc, char** argv) {
	Client& client = Client::getInstance();

	if(!client.initENet()) return EXIT_FAILURE;
	client.createClient();
	client.setAddress("127.0.0.1", 7777);
	client.createPeer();
	if(!client.connect()) return EXIT_FAILURE;

	client.sendPacket("This_is_some_test_data.");

	//TODO: 抽出分工
	thread mainLoop([&client]() {
		while(client.ServerRunning){
			client.handleEvents();
		}
	});
	thread t0(TestScreen::open);

	mainLoop.join();
	t0.join();

	
	
	// std::thread guiThread([](){
    //     TestScreen::open();
    //     windowClosed.store(true);
    // });
    // guiThread.detach();
	
	client.disconnect();
	return EXIT_SUCCESS;
}