#pragma once

#include "base/UIComponent.h"
#include <functional>
#include <unordered_map>

class Button : public UIComponent {
private:
	std::unordered_map<sf::Mouse::Button, std::function<void()>> _pressCallbacks;
	std::unordered_map<sf::Mouse::Button, std::function<void()>> _releaseCallbacks;

public:
	Button(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}

	std::shared_ptr<UIComponent> clone() const override {
		return std::make_shared<Button>(*this);
	}

	void setPressCallback(sf::Mouse::Button key, std::function<void()> callback) {
		_pressCallbacks[key] = callback;
	}
	void setReleaseCallback(sf::Mouse::Button key, std::function<void()> callback) {
		_releaseCallbacks[key] = callback;
	}

	void handleEvent(const std::optional<sf::Event>& event) override {
		if(auto* it = event->getIf<sf::Event::MouseButtonPressed>()){
			if(!contains(it->position) || !_visible) return;

			auto func = _pressCallbacks.find(it->button);
			if(func == _pressCallbacks.end()) return;
			
			(func->second)();
		}
		else if(auto* it = event->getIf<sf::Event::MouseButtonReleased>()) {
			if(!contains(it->position) || !_visible) return;

			auto func = _releaseCallbacks.find(it->button);
			if(func == _releaseCallbacks.end()) return;
			
			(func->second)();
		}
	}

	/**
	 * @brief Do nothing.
	 */
	void render(sf::RenderWindow& window) override {}
};