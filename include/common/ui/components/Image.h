#pragma once

#include "interfaces/UIComponent.h"
#include "interfaces/IRenderable.h"
#include <memory>
#include <iostream>

class Image : public UIComponent, public IRenderable {
private:
	std::shared_ptr<sf::Texture> _texture;
	sf::Sprite _sprite;
	
public:
	Image(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}

	bool setTexture(std::shared_ptr<sf::Texture> texture) {
		if(!texture) return false;
		
		_texture = texture;
		_sprite.setTexture(*_texture);
		sf::Vector2u texSize = _texture->getSize();
		_sprite.setScale(_size.x / texSize.x, _size.y / texSize.y);

		return true;
	}

	void syncPosition(sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		_sprite.setPosition(_globalPos);
	}

	void setSize(const sf::Vector2f& size) override {
		_size = size;
		if(_texture) {
			sf::Vector2u texSize = _texture->getSize();
			_sprite.setScale(_size.x / texSize.x, _size.y / texSize.y);
		}
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || !_texture) return;
		window.draw(_sprite);
	}
};