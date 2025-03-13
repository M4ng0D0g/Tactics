#ifndef BOARD_H
#define BOARD_H

#include "PieceType.h"
#include "Tile.h"
#include "Colors.h"

#include <iostream>
#include <vector>
#include <utility>

class Board {
private:
	std::pair<int, int> _size;
	std::vector<std::vector<Tile>> _data;

public:
	Board(std::pair<int, int> size = {16, 16});

	Tile& getTile(const std::pair<int,int>& pos);
	bool isInBoard(const std::pair<int,int>& pos) const;
};

#endif