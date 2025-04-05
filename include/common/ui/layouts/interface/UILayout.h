#pragma once

#include "../../components/base/UIComponent.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class UILayout {
protected:
	//sf::Vector2f _spacing = {0f, 0f};
	//float _paddingX, _paddingY;

	int _rows = 1, _cols = 1;
	
public:
	~UILayout() = default;

	virtual void applyLayout(std::vector<std::shared_ptr<UIComponent>>& components) = 0;
};
