#include "Tile.h"

//[FIXME]
Tile::Tile() {
    team = Team::Neutral;
    size = vector(15, 80);
}
TeamType Tile::getTeam() { return team; };

void Tile::setTeam(TeamType newTeam) { team = newTeam; };
Piece Tile::getPiece() { return piece; };
void Tile::setPiece() {  };
void Tile::removePiece(){ delete(piece); };

bool Tile::hasPiece() {
    if(piece != NULL) return true;
    return false;
}