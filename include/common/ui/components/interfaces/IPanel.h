#pragma once

#include "BaseComponent.h"
#include "IContainer.h"
#include "IHittable.h"

class IPanel : public BaseComponent, public IContainer, public IHittable {
public:
	IPanel(const CommonOps& ops) : BaseComponent(ops) {}
	virtual ~IPanel() = default;
	
	void syncGlobalPos(const sf::Vector2f& parentPos) override {
		BaseComponent::syncGlobalPos(parentPos);
		syncChild(_globalPos);
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible) return;
		for(const auto& comp : _components) comp->render(window);
	}

	bool handleEvent(const std::optional<sf::Event>& event) override {
		if(!event) return true;
		if(isMouseEvent(event) && !isMouseOver(_globalPos, _size)) return false;
		if(dispatchEvent(event)) return true;
		return false;
	}
};