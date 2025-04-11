#pragma once

#include "options/ImageOps.h"
#include "interfaces/BaseComponent.h"
#include <memory>
#include <iostream>

class Image : public BaseComponent {
private:
	std::shared_ptr<sf::Texture> _texture;
	sf::Sprite _sprite;
	
public:
	Image(const ImageOps& ops) : BaseComponent(ops), _texture(ops.getTexture()), _sprite(*_texture) {
		sf::Vector2u texSize = _texture->getSize();
		_sprite.setScale({_size.x / texSize.x, _size.y / texSize.y});
	}

	bool setTexture(std::shared_ptr<sf::Texture> texture) {
		if(!texture) return false;
		_texture = texture;
		sf::Vector2u texSize = _texture->getSize();
		_sprite.setTexture(*_texture);
		_sprite.setScale({_size.x / texSize.x, _size.y / texSize.y});
		return true;
	}

	void syncGlobalPos(const sf::Vector2f& parentPos) override {
		BaseComponent::syncGlobalPos(parentPos);
		_sprite.setPosition(_globalPos);
	}

	void setSize(const sf::Vector2f& size) override {
		_size = size;
		if(_texture) {
			sf::Vector2u texSize = _texture->getSize();
			_sprite.setScale({_size.x / texSize.x, _size.y / texSize.y});
		}
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || !_texture) return;
		window.draw(_sprite);
	}
};