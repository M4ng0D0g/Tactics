#include "Tile.h"

//[FIXME]
Tile::Tile() {
    team = Team::Neutral;
    size = vector(15, 80);
}
TeamType Tile::getTeam() { return team; };

void Tile::setTeam(TeamType newTeam) { team = newTeam; };
Troop Tile::getTroop() { return troop; };
void Tile::setTroop() {  };
void Tile::removeTroop(){ delete(troop); };

bool Tile::hasTroop() {
    if(troop != NULL) return true;
    return false;
}