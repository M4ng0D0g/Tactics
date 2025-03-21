#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "./screen/Base/Screen.h"

#include <SFML/Graphics.hpp>
#include <memory>

class MainWindow {
private:
	MainWindow() : _window(sf::VideoMode({600, 400}), "Test Screen") {}
	~MainWindow() {}

	sf::RenderWindow _window;
	std::shared_ptr<Screen> _screen;
public:
	static MainWindow& getInstance() {
		static MainWindow instance;
		return instance;
	}
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;

	void setScreen(std::shared_ptr<Screen>);
	void runWindow();

};

#endif