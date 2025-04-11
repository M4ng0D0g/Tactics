#pragma once

#include <SFML/Graphics.hpp>

class CommonOps {
protected:
	sf::Vector2f _position, _size;

public:
	CommonOps(sf::Vector2f pos, sf::Vector2f size) : _position(pos), _size(size) {}
	virtual ~CommonOps() = default;

	sf::Vector2f getPosition() const {
		return _position;
	}
	sf::Vector2f getSize() const {
		return _size;
	}
	CommonOps& setPosition(const sf::Vector2f& pos) {
		_position = pos;
		return *this;
	}
	CommonOps& setSize(const sf::Vector2f& size) {
		_size = size;
		return *this;
	}
};