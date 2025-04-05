#pragma once

#include "base/UIComponent.h"
#include "../layouts/interface/UILayout.h"
#include <vector>
#include <memory>

class Panel : public UIComponent {
private:
	std::vector<std::shared_ptr<UIComponent>> _components;
	std::shared_ptr<UILayout> _layout;

public:
	Panel(const sf::Vector2f& pos, const sf::Vector2f& size, std::shared_ptr<UILayout> layout)
	: UIComponent(pos, size), _layout(layout) {}

	std::shared_ptr<UIComponent> clone() const override {
		return std::make_shared<Panel>(*this);
	}

	void applyLayout() {
		_layout->applyLayout(_components);
	}

	void addComponent(std::shared_ptr<UIComponent> component, size_t index = -1) {
		if(!component) return;
		if(index == static_cast<size_t>(-1)) _components.push_back(component);
		else _components.insert(_components.begin() + index, component);
	}

	void syncPosition(sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		for(auto& comp : _components) {
			comp->syncPosition(_globalPos);
		}
	}

	void updateSize() {
		sf::Vector2f size = {0, 0};
		for (const auto& comp : _components) {
			size.x = std::max(size.x, comp->getRelativePosition().x + comp->getSize().x);
			size.y = std::max(size.y, comp->getRelativePosition().y + comp->getSize().y);
		}
		_size = size;
	}

	void render(sf::RenderWindow& window) {
		if(!_visible) return;
		for(const auto& comp : _components) {
			if(!comp->isVisible()) continue;
			comp->render(window);
		}
	}

	void handleEvent(const std::optional<sf::Event>& event) override {
		for(const auto& comp : _components) {
			comp->handleEvent(event);
		}
	}
};