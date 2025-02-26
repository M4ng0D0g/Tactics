#pragma once

#include <iostream>
#include <vector>
#include ".\tile.h"
#include "Colors.h"


using namespace std;

class Board {
private:
    int Row, Col;
    vector<vector<Tile>> tiles;
public:
    Board(int row = 15, int col = 15) {
        Row = row;
        Col = col;
        tiles = vector(Row, vector<Tile>(Col, Tile()));
    }

    Tile getTile(int x, int y) {
        if(x < 0 || x >= Row || y < 0 || y >= Col) cout << "長度不合" << endl;
        return tiles[x][y];
    }
};

class BoardBuilder {
    //todo 長寬自訂
public:
    static Board build() {
        Board board;
        return board;
    }

    static void draw(int locX, int locY, int lengthX, int lengthY, int tilesX, int tilesY) {
        int radioX = lengthX / tilesX;
        int radioY = lengthY / tilesY;

        for(int i = 0; i < tilesX; i++){
            for( int j = 0; j < tilesY; j++){
                Color color = (i + j) % 2 == 0 ? Colors::Neutral0 : Colors::Neutral1; 
                DrawRectangle(locX + i * radioX, locY +  j * radioY, radioX, radioY, color);
            }
        }
    }



};

