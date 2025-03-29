#ifndef TILE_H
#define TILE_H

#include "game/enums/TeamEnum.h"

// ***************************************************************************/

class Tile {
private:
	TeamEnum::Type _team = TeamEnum::Type::Neutral;

public:
	Tile() {}

	TeamEnum::Type getTeam() const;
	void setTeam(TeamEnum::Type team);
};

#endif 