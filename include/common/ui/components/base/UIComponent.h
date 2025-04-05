#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class UIComponent : public std::enable_shared_from_this<UIComponent> {
protected:
	sf::Vector2f _globalPos;
	sf::Vector2f _relativePos;
	sf::Vector2f _size;
	bool _visible = true;

public:
	UIComponent(const sf::Vector2f& pos, const sf::Vector2f& size) : _relativePos(pos), _size(size) {}

	virtual std::shared_ptr<UIComponent> clone() const = 0;
	virtual void render(sf::RenderWindow&) = 0;
	virtual void handleEvent(const std::optional<sf::Event>&) {}
	virtual void update() {}
	
	
	bool contains(const sf::Vector2f& pos) const {
		return (pos.x >= _globalPos.x && pos.x <= _globalPos.x + _size.x)
		&& (pos.y >= _globalPos.y && pos.y <= _globalPos.y + _size.y);
	}
	
	const sf::Vector2f& getPosition() const {
		return _relativePos;
	}
	virtual void setPosition(const sf::Vector2f& pos) {
		_relativePos = pos;
	}
	virtual void syncPosition(sf::Vector2f& parentPos) {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
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
