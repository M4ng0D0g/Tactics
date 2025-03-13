#include "Board.h"

Board::Board(std::pair<int, int> size) : _size(size) {
	_data = std::vector<std::vector<Tile>>(_size.first,std:: vector<Tile>(_size.second, Tile()));
}

Tile& Board::getTile(const std::pair<int,int>& pos) {
	const bool check = isInBoard(pos);
	if(check) return _data[pos.first][pos.second];
	else throw out_of_range("Position out of bounds.");
}
bool Board::isInBoard(const std::pair<int,int>& pos) const {
	return (pos.first >= 0) && (pos.first < _size.first) && (pos.second >= 0) && (pos.second < _size.second);
}