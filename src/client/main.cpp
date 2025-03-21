#include "connection/Client.h"
#include "connection/PacketHandler.h"
#include "gui/MainWindow.h"
#include "gui/screen/TestScreen.h"

#include <iostream>
#include <thread>
#include <json.hpp>
#include <memory>

using namespace std;

// atomic<bool> windowClosed(false);

int main(int argc, char** argv) {
	Client& client = Client::getInstance();
	PacketHandler& packetHandler = PacketHandler::getInstance();
	MainWindow& mainWindow = MainWindow::getInstance();

	if(!client.initENet()) return EXIT_FAILURE;
	client.createClient();
	client.setAddress("127.0.0.1", 7777);
	client.createPeer();
	if(!client.connect()) return EXIT_FAILURE;

	nlohmann::json jsonObj;
	jsonObj["event"] = "test";
	packetHandler.send(jsonObj);

	thread clientThread([&client]() { client.runClient(); });
	if(clientThread.joinable()) clientThread.detach();

	mainWindow.setScreen(std::make_shared<TestScreen>());
	mainWindow.runWindow();

	// jsonObj["event"] = "client:closeWindow";
	// packetHandler.send(jsonObj); 無法發送
	
	client.disconnect();
	return EXIT_SUCCESS;
}