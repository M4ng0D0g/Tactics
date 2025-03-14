#ifndef TILE_H
#define TILE_H

#include "Piece.h"

class Tile {
private:
	TeamType _team;
	std::shared_ptr<Piece> _piece;

public:
	Tile();

	TeamType getTeam();
	void setTeam(TeamType team);

	std::shared_ptr<Piece> getPiece();
	void setPiece(std::shared_ptr<Piece> piece);
};

#endif