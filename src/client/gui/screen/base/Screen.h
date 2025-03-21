#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <optional>

class Screen {
private:
public:
	virtual void handleEvent(const std::optional<sf::Event>&) = 0;
	virtual void render(sf::RenderWindow&) = 0;
};


#endif