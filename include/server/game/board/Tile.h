#ifndef TILE_H
#define TILE_H

#include "../troop/Troop.h"

class Tile {
private:
	TeamType _team;
	std::shared_ptr<Troop> _troop;

public:
	Tile();

	TeamType getTeam();
	void setTeam(TeamType team);

	std::shared_ptr<Troop> getTroop();
	void setTroop(std::shared_ptr<Troop> troop);
};

#endif