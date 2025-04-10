#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./screen/Base/Screen.h"

#include <SFML/Graphics.hpp>
#include <memory>

class Window {
private:
	Window() : _window(sf::VideoMode({600, 400}), "Test Screen") {}
	~Window() {}

	sf::RenderWindow _window;
	std::shared_ptr<Screen> _screen;
public:
	static Window& getInstance() {
		static Window instance;
		return instance;
	}
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void setScreen(std::shared_ptr<Screen>);
	void runWindow();

};

#endif