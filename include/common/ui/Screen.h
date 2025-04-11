#pragma once

#include "components/interfaces/BaseComponent.h"
#include "components/interfaces/IPanel.h"
#include <vector>
#include <memory>

class Screen {
private:
	std::vector<std::shared_ptr<IPanel>> _panels;

public:
	Screen() {}
	//Screen(const Screen&) {}

	void addPanel(std::shared_ptr<IPanel> panel, size_t index = -1) {
		if (!panel) return;
		if(index < 0 || index >= _panels.size()) _panels.push_back(panel);
		else _panels.insert(_panels.begin() + index, panel);
	}

	void syncPosition() {
		for(auto& comp : _panels) comp->syncChild({0.f, 0.f});
	}

	void render(sf::RenderWindow& window) {
		for(const auto& comp : _panels) comp->render(window);
	}

	bool handleEvent(const std::optional<sf::Event>& event) {
		for(auto it = _panels.rbegin(); it != _panels.rend(); ++it) {
			if((*it)->handleEvent(event)) return true;
		}
		return false;
	}
};