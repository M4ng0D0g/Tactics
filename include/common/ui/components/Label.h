#pragma once

#include "options/CommonOps.h"
#include "interfaces/BaseComponent.h"
#include <string>
#include <memory>

class Label : public BaseComponent {
private:
	sf::Text _sfText;
	std::string _text;
	std::shared_ptr<sf::Font> _font;

public:
	Label(const CommonOps& ops) : BaseComponent(ops) {}

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

	void syncGlobalPos(sf::Vector2f& parentPos) override {
		BaseComponent::syncGlobalPos(parentPos);
		_sprite.setPosition(_globalPos);
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible || _text.empty()) return;
		window.draw(_sfText);
	}
}