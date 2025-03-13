#ifndef TILE_H
#define TILE_H

#include "TeamType.h"
#include "Piece.h"

//[FIXME]
class Tile {
private:
	//gameProperties
	TeamType _team;
	Piece _piece;

	//displayProperties
	public:
	Tile();

	TeamType getTeam();
	Piece getPiece();

	void setTeam(TeamType newTeam);
	void setPiece();

	void removePiece();
	bool hasPiece();

};

#endif