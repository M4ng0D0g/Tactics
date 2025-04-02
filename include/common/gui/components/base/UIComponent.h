#pragma once

#include <SFML/Graphics.hpp>

class UIComponent {
protected:
	sf::Vector2f _pos;
	sf::Vector2f _size;
	bool _visible = true;

public:
	UIComponent(const sf::Vector2f& pos, const sf::Vector2f& size) : _pos(pos), _size(size) {}

	virtual void render(sf::RenderWindow&) = 0;
	virtual void handleEvent(const std::optional<sf::Event>&) {}
	virtual void update() {}
	
	bool contains(const sf::Vector2f& pos) const {
		return (pos.x >= _pos.x && pos.x <= _pos.x + _size.x)
		&& (pos.y >= _pos.y && pos.y <= _pos.y + _size.y);
	}
	
	const sf::Vector2f& getPosition() const {
		return _pos;
	}
	virtual void setPosition(const sf::Vector2f& pos) {
		_pos = pos;
	}

	const sf::Vector2f& getSize() const {
		return _size;
	}
	virtual void setSize(const sf::Vector2f& size) {
		_size = size;
	}

	bool isVisible() const {
		return _visible;
	}
	void setVisible(bool v) {
		_visible = v;
	}
};
