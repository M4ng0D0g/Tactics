#pragma once

#include "interfaces/UIComponent.h"
#include "interfaces/IContainer.h"
#include "interfaces/IRenderable.h"
#include "../layouts/interfaces/UILayout.h"
#include "../layouts/FreeLayout.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <optional>
#include <vector>
#include <memory>

/**
 * @brief 可容納子元件並套用版面配置的 Panel。
 */
class Panel : public UIComponent, public IContainer, public IRenderable {
private:
	std::shared_ptr<UILayout> _layout = nullptr;

public:
	Panel(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {}
	
	void setLayout(std::shared_ptr<UILayout> layout) { _layout = std::move(layout); }

	void applyLayout() {
		if(_layout) _layout->apply(_components);
		syncPosition(_globalPos);
	}

	void syncPosition(const sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		for(auto& comp : _components) {
			comp->syncPosition(_globalPos);
		}
	}

	/**
	 * @brief 更新面板的大小以適應所有子元件。
	 * @details 此函數會遍歷所有子元件，計算它們的最大寬度和高度，並更新面板的大小。
	 */
	void updateSize() {
		sf::Vector2f size = {0.f, 0.f};
		for (const auto& comp : _components) {
			size.x = std::max(size.x, comp->getPosition().x + comp->getSize().x);
			size.y = std::max(size.y, comp->getPosition().y + comp->getSize().y);
		}
		_size = size;
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible) return;
		for(const auto& comp : _renderables) comp->render(window);
	}

	bool handleEvent(const std::optional<sf::Event>& event) override {
		for(auto it = _components.rbegin(); it != _components.rend(); it++)	{
			if((*it)->handleEvent(event)) return true;
		}
		return false;
	}
};