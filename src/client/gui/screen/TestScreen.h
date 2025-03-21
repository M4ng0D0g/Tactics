#ifndef TESTSCREEN_H
#define TESTSCREEN_H

#include "./base/Screen.h"

#include <SFML/Graphics.hpp>

class TestScreen : public Screen {
public:
	void handleEvent(const std::optional<sf::Event>& event) override;
	void render(sf::RenderWindow&) override;
};

#endif