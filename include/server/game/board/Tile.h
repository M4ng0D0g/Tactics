#pragma once

#include "TeamType.h"
#include "Piece.h"

using namespace std;

//[FIXME]
class Tile {
private:
    //gameProperties
    TeamType team;
    Piece piece;
    
    //displayProperties
public:
    Tile() {
        team = Team::Neutral;
        size = vector(15, 80);
    }

    TeamType getTeam() { return team; };
    void setTeam(TeamType newTeam) { team = newTeam; };

    Piece getPiece() { return piece; };
    void setPiece() {  };
    void removePiece(){ delete(piece); };
    bool hasPiece() {
        if(piece != NULL) return true;
        return false;
    }
    
    

};