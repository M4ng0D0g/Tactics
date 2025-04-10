#pragma once

#include "interface/UILayout.h"

class VerticalLayout : public UILayout {
public:
	void applyLayout(std::vector<std::shared_ptr<UIComponent>>& components) override {
		// if(components.empty()) return;

		// sf::Vector2f pos = {0, 0};

		// for(const auto& comp : components) {
		// 	comp->setRelativePosition(pos);
		// 	pos.y += comp->getSize().y;
		// }
	}
};