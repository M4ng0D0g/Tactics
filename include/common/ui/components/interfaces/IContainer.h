#pragma once

#include "IClickable.h"
#include "IHittable.h"
#include "IRenderable.h"
#include "UIComponent.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class IContainer {
protected:
	std::vector<std::shared_ptr<UIComponent>> _components;
	std::vector<std::shared_ptr<IClickable>> _clickables;
	std::vector<std::shared_ptr<IHittable>> _hittables;
	std::vector<std::shared_ptr<IRenderable>> _renderables;

public:
	virtual ~IContainer() = default;

	/**
	 * @brief 添加一個元件到容器中
	 * @param component 要添加的元件
	 * @param index 插入位置，-1表示添加到末尾
	 */
	virtual void addComponent(std::shared_ptr<UIComponent> component, size_t index = -1) {
		if (!component) return;

		//TODO: 這裡的判斷應該要更嚴謹，檢查是否已經存在於容器中
		if(index < 0 || index >= _components.size()) {
			_components.push_back(component);
			if(auto p = dynamic_cast<std::shared_ptr<IClickable>>(component)) _components.push_back(component);
			if(auto p = dynamic_cast<std::shared_ptr<IHittable>>(component)) _components.push_back(component);
			if(auto p = dynamic_cast<std::shared_ptr<IRenderable>>(component)) _components.push_back(component);
		}
		else {
			_components.insert(_components.begin() + index, component);
			if(auto p = dynamic_cast<std::shared_ptr<IClickable>>(component)) _clickables.insert(_clickables.begin() + index, p);
			if(auto p = dynamic_cast<std::shared_ptr<IHittable>>(component)) _hittables.insert(_hittables.begin() + index, p);
			if(auto p = dynamic_cast<std::shared_ptr<IRenderable>>(component)) _renderables.insert(_renderables.begin() + index, p);
		}
	}
};