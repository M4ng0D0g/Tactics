#pragma once

#include "Screen.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <memory>

class Window {
private:
	Window(sf::Vector2u size, std::string title, int frameRate): _window(sf::VideoMode(size), title) {
		_window.setFramerateLimit(frameRate);
	}
	~Window();

	sf::RenderWindow _window;
	std::shared_ptr<Screen> _screen;

public:
	static Window& getInstance(
		const sf::Vector2u& size = sf::Vector2u(800, 600),
		const std::string& title = "Default Title",
		int frameRate = 60
	) {
		static Window instance(size, title, frameRate);
		return instance;
	}
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void setScreen(const std::shared_ptr<Screen>& screen) {
		_screen = screen;
	}

	void open() {
		while(_window.isOpen()) {
			while(const std::optional event = _window.pollEvent()) {
				if(event->is<sf::Event::Closed>()) _window.close();
				else _screen->handleEvent(event);
			}

			if(_screen) _screen->render(_window);
			_window.display();
		}
	}
};