#ifndef TILE_H
#define TILE_H

#include "../troop/Troop.h"
#include "../enums/TeamEnum.h"

#include <memory>

class Tile {
private:
	TeamType _team = Neutral;
	std::shared_ptr<Troop> _troop = nullptr;

public:
	Tile();

	//TeamType
	TeamType getTeam() const;
	//TeamType
	void setTeam(TeamType team);

	//Troop
	const std::shared_ptr<Troop>& getTroop() const;
	//Troop
	void setTroop(std::shared_ptr<Troop> troop);
};

#endif