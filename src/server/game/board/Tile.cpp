#include "Tile.h"

Tile::Tile() {}

TeamType Tile::getTeam() const {
	return _team;
}

void Tile::setTeam(TeamType team) {
	_team = team;
}

const std::shared_ptr<Troop>& Tile::getTroop() const {
	return _troop;
}

void Tile::setTroop(std::shared_ptr<Troop> troop) {
	_troop = troop;
}