#include <iostream>
#include <SFML/Window.hpp>
#include <enet/enet.h>
#include "Client.hpp"

using namespace sf;
using namespace std;

class TestScreen {
public:
	static void open(){
		cout << "TestScreen opened." << endl;
		Window window(VideoMode({800, 600}), "My window");
		
		while(window.isOpen()) {
			// check all the window's events that were triggered since the last iteration of the loop
			while(const std::optional event = window.pollEvent()) {
				// "close requested" event: we close the window
				if(event->is<sf::Event::Closed>())
					window.close();
			}
		}
		Client::getInstance().sendPacket("client:closeWindow");
	}
};
// class TestScreen {
// private:
// 	TestScreen(){}
// public:
// 	TestScreen(const TestScreen&) = delete;
// 	TestScreen& operator=(const TestScreen&) = delete;

// 	static TestScreen& getInstance() {
// 		static TestScreen instance;
// 		cout << "TestScreen generated." << endl;
// 		return instance;
// 	}

// 	virtual void open() {}
// };