#pragma once

#include "options/CommonOps.h"
#include "interfaces/IPanel.h"

class GridPanel : public IPanel {
private:
	int _rows = 0, _cols = 0;
	sf::Vector2f _cellSize = {0.f, 0.f};
	float _spacing = 0.f;

public:
	GridPanel(const CommonOps& ops) : IPanel(ops) {}

	GridPanel& setDimension(int rows, int cols) {
		_rows = rows;
		_cols = cols;
		return *this;
	}

	GridPanel& setCellSize(const sf::Vector2f& size) {
		_cellSize = size;
		return *this;
	}

	GridPanel& setSpacing(float spacing) {
		_spacing = spacing;
		return *this;
	}

	void applyLayout() override {
		if(_components.empty()) return;
		sf::Vector2f pos = {0, 0};
		int dim = _rows * _cols;

		for(int i = 0; i < _components.size() && i < dim; i++) {
			int row = i / _cols;
			int col = i % _cols;
			pos.x = col * (_cellSize.x + _spacing);
			pos.y = row * (_cellSize.y + _spacing);
			_components[i]->setRelativePos(pos);
			_components[i]->setSize(_cellSize);
		}
	}

};