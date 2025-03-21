#include "Board.h"


Board::Board(std::pair<int, int> size = {16, 16})
: _size(size),
_data(size.first, std::vector<std::shared_ptr<Tile>>(size.second, std::make_shared<Tile>())) {
	_allTileCount = size.first * size.second;
}

bool Board::isValid(const std::pair<int,int>& loc) const {
	return (loc.first >= 0) &&(loc.first < _size.first) &&
		(loc.second >= 0) && (loc.second < _size.second);
}

bool Board::hasTroop(const std::pair<int,int>& loc) const {
	return _data[loc.first][loc.second]->getTroop() != nullptr;
}

const std::shared_ptr<Troop>& Board::getTroop(const std::pair<int,int>& loc) const {
	return _data[loc.first][loc.second]->getTroop();
}

void Board::placeTroop(std::shared_ptr<Troop> troop, const std::pair<int,int>& loc) {
	_data[loc.first][loc.second]->setTroop(troop);
}

void Board::removeTroop(const std::pair<int,int>& loc) {
	_data[loc.first][loc.second]->setTroop(nullptr);
}

TeamType Board::getTileTeam(const std::pair<int,int>& loc) const {
	return _data[loc.first][loc.second]->getTeam();
}

void Board::setTileTeam(const std::pair<int,int>& loc, TeamType team) {
	_data[loc.first][loc.second]->setTeam();
}
