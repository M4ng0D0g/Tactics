#pragma once

#include <SFML/Graphics.hpp>

class IHittable {
public:
	virtual ~IHittable() = default;

	/**
	 * @brief 檢查滑鼠是否懸浮在元件上
	 * @return 如果滑鼠懸浮在元件上則返回true，否則返回false
	 */
	[[nodiscard]]
	bool isMouseOver(const sf::Vector2f& globalPos, const sf::Vector2f& size) const {
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		return (mousePos.x >= globalPos.x && mousePos.x <= globalPos.x + size.x)
		&& (mousePos.y >= globalPos.y && mousePos.y <= globalPos.y + size.y);
	}

	bool isMouseEvent(const std::optional<sf::Event>& event) const {
		if(!event) return false;
		if(event->is<sf::Event::MouseButtonPressed>()) return true;
		if(event->is<sf::Event::MouseButtonReleased>()) return true;
		return false;
	}
};