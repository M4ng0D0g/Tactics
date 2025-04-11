#pragma once

#include "CommonOps.h"
#include <SFML/Graphics.hpp>
#include <memory>

class ImageOps : public CommonOps {
protected:
	std::shared_ptr<sf::Texture> _texture;

public:
	ImageOps(sf::Vector2f pos, sf::Vector2f size) : CommonOps(pos, size) {}
	virtual ~ImageOps() = default;

	std::shared_ptr<sf::Texture> getTexture() const { return _texture; }

	ImageOps& setTexture(std::shared_ptr<sf::Texture> texture) {
		_texture = texture;
		return *this;
	}
};