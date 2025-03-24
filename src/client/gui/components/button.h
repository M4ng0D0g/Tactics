#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button : public UIComponent {
private:
	sf::RectangleShape _shape;
	sf::Text _text;
	sf::Font _font;
	std::function<void()> _onClick;
public:
	Button(float x, float y, float width, float height, const std::string& text, std::function<void()> onClick) {
		setPosition(x, y);
		setSize(width, height);

		_shape.setPosition(_position);
		_shape.setSize(_size);
		_shape.setFillColor(sf::Color::Blue);

		_font.loadFromFile("assets/fonts/NotoSans-Regular.ttf");
		_text.setFont(_font);
		_text.setString(text);
		_text.setCharacterSize(20);
		_text.setPosition(_position.x + 10, _position.y + 5);

		_onClick = onClick;
	}

	void handleEvent(const sf::Event& event) override {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (_shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				_onClick();
			}
		}
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(_shape);
		window.draw(_text);
	}
};

#endif