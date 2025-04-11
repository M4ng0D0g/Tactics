#pragma once

#include "BaseComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class IContainer {
protected:
	std::vector<std::shared_ptr<BaseComponent>> _components;

public:
	virtual ~IContainer() = default;

	/**
	 * @brief 添加一個元件到容器中
	 * @param component 要添加的元件
	 * @param index 插入位置，-1表示添加到末尾
	 */
	IContainer& addComponent(std::shared_ptr<BaseComponent> component, size_t index = -1) {
		if (!component) return *this;
		if(index < 0 || index >= _components.size()) _components.push_back(component);
		else _components.insert(_components.begin() + index, component);
		return *this;
	}

	/**
	 * @brief 應用版面配置到所有元件
	 */
	virtual void applyLayout() = 0;

	void syncChild(const sf::Vector2f& pos) {
		for(auto& comp : _components) comp->syncGlobalPos(pos);
	}

	bool dispatchEvent(const std::optional<sf::Event>& event) {
		if(!event) return true;
		for(auto it = _components.rbegin(); it != _components.rend(); ++it) {
			if((*it)->handleEvent(event)) return true;
		}
		return false;
	}
};