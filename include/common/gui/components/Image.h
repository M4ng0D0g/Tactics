#pragma once

#include "base/UIComponent.h"
#include <memory>
#include <iostream>

class Image : public UIComponent {
private:
	std::shared_ptr<sf::Texture> _texture;
	sf::Sprite _sprite;
	
public:
	Image(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {
		_sprite.setPosition(pos);
	}

	bool setTexture(std::shared_ptr<sf::Texture> texture) {
		if(!texture) return false;

		_texture = texture;
		_sprite.setTexture(*_texture);

		sf::Vector2u texSize = _texture->getSize();
		_sprite.setScale(_size.x / texSize.x, _size.y / texSize.y);

		return true;
	}

	void setPosition(const sf::Vector2f& pos) override {
		_pos = pos;
		_sprite.setPosition(pos);
	}

	void setSize(const sf::Vector2f& size) override {
		_size = size;
		if(_texture) {
			sf::Vector2u texSize = _texture->getSize();
			_sprite.setScale(size.x / texSize.x, size.y / texSize.y);
		}
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || !_texture) return;
		window.draw(_sprite);
	}
};