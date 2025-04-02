#pragma once

#include "base/UIComponent.h"
#include <functional>
#include <unordered_map>

class Button : public UIComponent {
private:
	std::unordered_map<sf::Mouse::Button, std::function<void()>> _callbacks;

public:
	Button(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}

	void setCallback(sf::Mouse::Button key, std::function<void()> callback) {
		_callbacks[key] = callback;
	}

	void handleEvent(const std::optional<sf::Event>& event) override {
		if(auto* it = event->getIf<sf::Event::MouseButtonPressed>()){
			if(!contains(it->position) || !_visible) return;

			auto func = _callbacks.find(it->button);
			if(func == _callbacks.end()) return;
			
			(func->second)();
		}
		else if(auto* it = event->getIf<sf::Event::MouseButtonReleased>()) {
			if(!contains(it->position) || !_visible) return;

			auto func = _callbacks.find(it->button);
			if(func == _callbacks.end()) return;
			
			(func->second)();
		}
	}

	/**
	 * @brief Do nothing.
	 */
	void render(sf::RenderWindow& window) override {}
};