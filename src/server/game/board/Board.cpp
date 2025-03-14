#include "Board.h"

Board::Board(std::pair<int, int> size) : _size(size) {
	_data = std::vector<std::vector<Tile>>(_size.first,std:: vector<Tile>(_size.second, Tile()));
}

bool isValid() {}; //?

Tile& Board::getTile(const std::pair<int,int>& pos) {
	const bool check = isInBoard(pos);
	if(check) return _data[pos.first][pos.second];
	else throw out_of_range("Position out of bounds.");
}
bool Board::isInBoard(const std::pair<int,int>& pos) const {
	return (pos.first >= 0) && (pos.first < _size.first) && (pos.second >= 0) && (pos.second < _size.second);
}

bool Board::hasTroop(const std::pair<int,int>& loc);
std::shared_ptr<Troop>& getTroop(const std::pair<int,int>& loc);
void Board::placeTroop(const shared_ptr<Troop>&, const std::pair<int,int>& loc);
void Board::removeTroop(const std::pair<int,int>& loc);
void Board::moveTroop(const std::pair<int,int>& start, const std::pair<int,int>& dest);