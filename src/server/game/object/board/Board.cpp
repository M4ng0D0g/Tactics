#include "Board.h"

bool Board::isLocValid(const std::pair<int,int>& loc) const {
	return (loc.first >= 0) &&(loc.first < _size.first) && (loc.second >= 0) && (loc.second < _size.second);
}

Board::Board(std::pair<int, int> size = {16, 16}) : _size(size) {
	_tiles = std::vector<std::vector<std::shared_ptr<Tile>>>(size.first, std::vector<std::shared_ptr<Tile>>(size.second, std::make_shared<Tile>()));
	_troops = std::vector<std::vector<std::shared_ptr<Troop>>>(size.first, std::vector<std::shared_ptr<Troop>>(size.second, nullptr));
	_allTileCount = size.first * size.second;
}

std::shared_ptr<Troop> Board::getTile(const std::pair<int,int>& loc) {
	if(!isLocValid(loc)) return nullptr;
	return _tile[loc.first][loc.second];
}

std::shared_ptr<Troop> Board::getTroop(const std::pair<int,int>& loc) {
	if(!isLocValid(loc)) return nullptr;
	return _troops[loc.first][loc.second];
}

void Board::setTroop(const std::pair<int,int> loc, std::shared_ptr<Troop> troop) const {
	if(!isLocValid(loc));
	_troops[loc.first][loc.second] = troop;
}