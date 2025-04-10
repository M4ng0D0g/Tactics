#pragma once

#include "components/interfaces/IContainer.h"
#include "components/interfaces/UIComponent.h"
#include "layouts/interfaces/UILayout.h"
#include <vector>
#include <memory>

class Screen : public IContainer {
public:
	Screen() : IContainer() {}
	//Screen(const Screen&) {}

	void syncPosition() {
		for(auto& comp : _components) comp->syncPosition({0.f, 0.f});
	}

	void render(sf::RenderWindow& window) {
		for(const auto& comp : _renderables) comp->render(window);
	}

	bool handleEvent(const std::optional<sf::Event>& event) {
		for(auto it = _components.rbegin(); it != _components.rend(); it++) {
			if((*it)->handleEvent(event)) return true;
		}
		return false;
	}
};