#ifndef BOARD_H
#define BOARD_H

#include "../troop/Troop.h"
#include "Tile.h"

#include <vector>
#include <utility>
#include <memory>

class Board {
private:
	std::pair<int, int> _size;
	std::vector<std::vector<std::shared_ptr<Tile>>> _data;

public:
	Board(std::pair<int, int> size = {16, 16});

	//Location
	bool isValid(const std::pair<int,int>& loc) const;

	//Troop
	bool hasTroop(const std::pair<int,int>& loc) const;
	//Troop
	const std::shared_ptr<Troop>& getTroop(const std::pair<int,int>& loc) const;
	//Troop
	void placeTroop(std::shared_ptr<Troop> troop, const std::pair<int,int>& loc);
	//Troop
	void removeTroop(const std::pair<int,int>& loc);
	//Troop 應用複雜 交給Manager
	// void moveTroop(const std::pair<int,int>& start, const std::pair<int,int>& dest);

	//Tile
	TeamType getTileTeam(const std::pair<int,int>& loc) const;
	//Tile
	void setTileTeam(const std::pair<int,int>& loc, TeamType team);
	
};

#endif