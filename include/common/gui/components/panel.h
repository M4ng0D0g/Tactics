#pragma once

#include "base/UIComponent.h"
#include <vector>
#include <memory>

class Panel : UIComponent {
private:
	std::vector<std::shared_ptr<UIComponent>> _components;

public:
	Panel(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}

	void addComponent(std::shared_ptr<UIComponent> component, size_t index = -1) {
		if(!component) return;
		if(index == static_cast<size_t>(-1)) _components.push_back(component);
		else _components.insert(_components.begin() + index, component);

		updateSize();
	}

	void updateSize() {
        // float maxWidth = 0, totalHeight = 0;
        // for (const auto& comp : _components) {
        //     maxWidth = std::max(maxWidth, comp->getSize().x);
        //     totalHeight += comp->getSize().y;
        // }
        // _size = { maxWidth, totalHeight };
    }

	void render(sf::RenderWindow& window) {
		if(!_visible) return;
		for(const auto& comp : _components) {
			if(!comp->isVisible()) continue;
			comp->render(window);
		}
	}
};