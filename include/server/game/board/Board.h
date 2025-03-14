#ifndef BOARD_H
#define BOARD_H

#include "../troop/Troop.h"
#include "./Tile.h"
// #include "Colors.h"

#include <vector>
#include <memory>

class Board {
private:
	std::pair<int, int> _size;
	std::vector<std::vector<Tile>> _data;

public:
	Board(std::pair<int, int> size = {16, 16});

	bool isValid(); //?
	bool isInBoard(const std::pair<int,int>& loc);
	bool hasTroop(const std::pair<int,int>& loc);
	std::shared_ptr<Troop>& getTroop(const std::pair<int,int>& loc);
	void placeTroop(const std::shared_ptr<Troop>&, const std::pair<int,int>& loc);
	void removeTroop(const std::pair<int,int>& loc);
	void moveTroop(const std::pair<int,int>& start, const std::pair<int,int>& dest);
};

#endif