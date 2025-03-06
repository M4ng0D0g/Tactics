#pragma once

#include "raylib.h"
#include "Colors.h"
#include "TeamEnum.h"
#include "IPiece.h"
#include <vector>

using namespace std;

class Tile {
private:
    //gameProperties
    Team team;
    IPiece piece;
    
    //displayProperties
    Color color;
    vector<int> size;

public:
    Tile() {
        team = Team::Neutral;
        size = vector(15, 80);
    }

    Team getTeam() { return team; };

    bool hasPiece() {
        if(piece != NULL) return true;
        return false;
    }
    IPiece getPiece() { return piece; };
    void sellPiece(){}

};