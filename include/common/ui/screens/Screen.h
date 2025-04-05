#pragma once

#include "../components/base/UIComponent.h"
#include "layouts/interface/UILayout.h"
#include <vector>
#include <memory>

class Screen {
private:
	std::vector<std::shared_ptr<UIComponent>> _components;

public:
	Screen() = default;

	void addComponent(std::shared_ptr<UIComponent> component, size_t index = -1) {
		if(!component) return;
		if(index == static_cast<size_t>(-1)) _components.push_back(component);
		else _components.insert(_components.begin() + index, component);
	}

	void syncPosition() {
		for(auto& comp : _components) {
			comp->syncPosition({0f, 0f});
		}
	}

	void render(sf::RenderWindow& window) {
		for(const auto& comp : _components) {
			comp->render(window);
		}
	}

	void handleEvent(const std::optional<sf::Event>& event) {
		for(const auto& comp : _components) {
			comp->handleEvent(event);
		}
	}
};