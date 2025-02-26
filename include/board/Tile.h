#pragma once

#include "raylib.h"
#include "Colors.h"
#include "TeamEnum.h"
#include <vector>

using namespace std;

class Tile {
private:
    Team team;
    Color color;
    vector<int> size;

public:
    Tile() {
        team = Team::Neutral;
        size = vector(15, 80);
    }
    Team getTeam(){ return team; };

};