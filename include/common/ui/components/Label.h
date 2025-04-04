#pragma once

#include "base/UIComponent.h"
#include <string>
#include <memory>

class Label : public UIComponent {
private:
	std::string _text;
	sf::Text _sfText;
	std::shared_ptr<sf::Font> _font;

public:
	Label(const sf::Vector2f& pos, const sf::Vector2f& size, std::shared_ptr<sf::Font> font)
	: UIComponent(pos, size), _font(font) {
		_sfText.setFont(font);
		_sfText.setCharacterSize(24);
		_sfText.setFillColor(sf::Color::Black);
	}

	std::shared_ptr<UIComponent> clone() const override{
		return std::make_shared<Label>(*this);
	}

	void setText(const std::string& text) {
		_text = text;
		_sfText.setString(text);
	}

	void syncPosition(sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		_sprite.setPosition(_globalPos);
	}

	void setFont(std::shared_ptr<sf::Font> font) {
		_font = font;
		_sfText.setFont(*_font);
	}

	void setFontSize(unsigned int size) {
		_sfText.setCharacterSize(size);
	}

	void setColor(sf::Color color) {
		_sfText.setFillColor(color);
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || _text.empty()) return;
		window.draw(_sfText);
	}
}