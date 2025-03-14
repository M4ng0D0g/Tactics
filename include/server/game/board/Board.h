#ifndef BOARD_H
#define BOARD_H

#include "../piece/Piece.h"
// #include "Colors.h"

#include <vector>

class Board {
private:
	std::pair<int, int> _size;
	std::vector<std::vector<Tile>> _data;

public:
	Board(std::pair<int, int> size = {16, 16});

	bool isValid(); //?
	bool isInBoard(const std::pair<int,int>& loc);
	bool hasPiece(const std::pair<int,int>& loc);
	std::shared_ptr<Piece>& getPiece(const std::pair<int,int>& loc);
	void placePiece(const shared_ptr<Piece>&, const std::pair<int,int>& loc);
	void removePiece(const std::pair<int,int>& loc);
	void movePiece(const std::pair<int,int>& start, const std::pair<int,int>& dest);
};

#endif