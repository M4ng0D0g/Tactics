#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include <SFML/Graphics.hpp>

class UIComponent {
protected:
	sf::Vector2f _position;
	sf::Vector2f _size;
public:
	virtual ~UIComponent() = default;

	virtual void handleEvent(const sf::Event& event) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	void setPosition(float x, float y) { _position = {x, y}; }
	void setSize(float width, float height) { _size = {width, height}; }
};

#endif