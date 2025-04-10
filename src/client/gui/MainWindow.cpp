#include "MainWindow.h"
#include "../connection/Client.h"

#include <optional>
#include <iostream>

void Window::setScreen(std::shared_ptr<Screen> screen) {
	_screen = screen;
}

void Window::runWindow() {
	// std::cout << "test\n";
	while(_window.isOpen()) {
		while(const std::optional event = _window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) _window.close();
			if(_screen != nullptr) _screen->handleEvent(event);
		}
		if(_screen != nullptr) _screen->render(_window);
		_window.display();
	}
}