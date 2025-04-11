#pragma once

#include "options/CommonOps.h"
#include "interfaces/IPanel.h"

enum LayoutType { Horizontal, Vertical };
// enum AlignType { Left, Center, Right };

class StackPanel : public IPanel {
private:
	LayoutType _layoutType = Horizontal;
	float _spacing = 0.f;
	// AlignType _alignType = Left;

public:
	StackPanel(const CommonOps& ops) : IPanel(ops) {}

	StackPanel& setLayoutType(LayoutType layoutType) {
		_layoutType = layoutType;
		return *this;
	}

	StackPanel& setSpacing(int spacing) {
		_spacing = spacing;
		return *this;
	}

	void applyLayout() override {
		if(_components.empty()) return;
		sf::Vector2f pos = {0, 0};

		for(const auto& comp : _components) {
			comp->setRelativePos(pos);
			if(_layoutType == Horizontal) pos.x += comp->getSize().x + _spacing;
			if(_layoutType == Vertical) pos.y += comp->getSize().y + _spacing;
		}
	}
}
