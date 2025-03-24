#include "Board.h"

Tile::Tile() {}

TeamType Tile::getTeam() const {
	return _team;
}

void Tile::setTeam(TeamType team) {
	_team = team;
}