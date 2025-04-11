#ifndef SCREEN_H
#define SCREEN_H

#include "../../components/base/UIComponent.h"

#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <memory>

class Screen {
protected:
	std::vector<std::shared_ptr<BaseComponent>> _components;
public:
	virtual ~Screen() = default;

	void addComponent(std::shared_ptr<BaseComponent> component) {
		_components.push_back(component);
	}

	virtual void handleEvent(const sf::Event& event) {
		for(auto& component : _components) {
			component->handleEvent(event);
		}
	}

	virtual void render(sf::RenderWindow& window) {
		for(auto& component : _components) component->draw(window);
	}
};


#endif