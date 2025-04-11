#pragma once

#include "ui/Screen.h"
#include <memory>

class TestScreen {
private:
	std::shared_ptr<Screen> _screen = std::make_shared<Screen>();

public:
	TestScreen(const sf::Vector2i& windowSize);

	std::shared_ptr<Screen> getScreen() { return _screen; }
};
