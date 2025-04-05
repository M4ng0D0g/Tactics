#pragma once

#include "screens/Screen.h"
#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <memory>

class MainWindow {
private:
	MainWindow(sf::Vector2i size, std::string title, int frameRate): _window(sf::VideoMode(size), title) {
		_window.setFramerateLimit(frameRate);
	}
	~MainWindow();

	sf::RenderWindow _window;
	std::shared_ptr<Screen> _screen;

public:
	static MainWindow& getInstance(sf::Vector2i size, std::string title, int frameRate = 60) {
		static instance = MainWindow(size, title, frameRate);
		return instance;
	}
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;

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
			window.display();
		}
	}
};