#include <iostream>
#include "raylib.h"
#include "..\include\board\Board.h"

using namespace std;

int main(){
    InitWindow(900, 900, "Tactics");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            BoardBuilder::build();
            BoardBuilder::draw(0, 0, 900, 900, 15, 15);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}