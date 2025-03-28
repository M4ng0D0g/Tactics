#ifndef BOARD_H
#define BOARD_H

#include "enums/TeamEnum.h"
#include "Troop.h"
#include "Tile.h"

#include <vector>
#include <unordered_map>
#include <utility>
#include <memory>

// ***************************************************************************/

class Board {
private:
	std::pair<int, int> _size;
	std::vector<std::vector<std::shared_ptr<Tile>>> _tiles;
	std::vector<std::vector<std::shared_ptr<Troop>>> _troops;

	int _allTileCount; //[TODO]
	std::unordered_map<TeamEnum::Type, int> _teamTileCount; //[TODO]

	bool isLocValid(const std::pair<int,int>& loc) const;
	
public:
	Board(std::pair<int, int> size = {16, 16});

	std::shared_ptr<Troop> getTile(const std::pair<int,int>& loc);
	std::shared_ptr<Troop> getTroop(const std::pair<int,int>& loc);
	void setTroop(const std::pair<int, int> loc, std::shared_ptr<Troop> troop) const;
};

#endif