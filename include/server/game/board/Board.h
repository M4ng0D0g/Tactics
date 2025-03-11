#pragma once

#include "TeamType.h"
#include "PieceType.h"
#include "Piece.h"
#include "Tile.h"
#include "Colors.h"

#include <iostream>
#include <vector>
#include <pair>

//[O] 建立Tile grid
//[O] 執行邏輯綁定到Processor
class Board { 
private:
	pair<int,int> size;
	vector<vector<Tile>> data;
public:
	Board(pair<int,int> size = {16, 16}) : size(size) {
		data = vector<vector<Tile>>(size.first, vector<Tile>(size.second, Tile()));
	}
	
	Tile& getTile(const pair<int,int>& pos) {
		const bool check = isInBoard(pos);
		if(check) return data[pos.first][pos.second];
		else throw out_of_range("Position out of bounds.");
	}

	bool isInBoard(const pair<int,int>& pos) {
		return (pos.first >= 0) && (pos.first < size.first) && (pos.second >= 0) && (pos.second < size.second);
	}

};
