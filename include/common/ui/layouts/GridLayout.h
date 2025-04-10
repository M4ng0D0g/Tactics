#pragma once 

#include "interface/UILayout.h"
#include "../components/base/UIComponent.h"

class GridLayout : public UILayout {
public:
	GridLayout(int rows, int cols) : _rows(rows), _cols(cols) {}
	
	void applyLayout(std::vector<std::shared_ptr<UIComponent>>& components) override {
		// int vectorSize = _rows * _cols;
		// if(components.size() != vectorSize) return;

		// for(int i = 0; i < vectorSize; i++) {
		// 	sf::Vector2f pos = {
		// 		components[i]->getSize().x * (i % _cols),
		// 		components[i]->getSize().y * (i / _cols)
		// 	};
		// 	components[i]->setRelativePosition(pos);
		// }
	}
};