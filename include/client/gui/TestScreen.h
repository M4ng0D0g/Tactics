#include <iostream>
#include <SFML/Window.hpp>
#include <enet/enet.h>

using namespace sf;
using namespace std;

class TestScreen {
public:
	static void open(){
		cout << "TestScreen opened." << endl;
		Window window(VideoMode({800, 600}), "My window");
		
		while(window.isOpen()) {

		}

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