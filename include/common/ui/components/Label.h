#pragma once

#include "interfaces/UIComponent.h"
#include "interfaces/IRenderable.h"
#include <string>
#include <memory>

class Label : public UIComponent, public IRenderable {
private:
	sf::Text _sfText;
	std::string _text;
	std::shared_ptr<sf::Font> _font;

public:
	Label(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}

	void setText(const std::string& text) {
		_text = text;
		_sfText.setString(_text);
	}

	void setFont(std::shared_ptr<sf::Font> font) {
		_font = font;
		_sfText.setFont(*_font);
	}

	void setFontSize(unsigned int size) { _sfText.setCharacterSize(size); }

	void setColor(sf::Color color) { _sfText.setFillColor(color); }

	void syncPosition(sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		_sprite.setPosition(_globalPos);
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || _text.empty()) return;
		window.draw(_sfText);
	}
}