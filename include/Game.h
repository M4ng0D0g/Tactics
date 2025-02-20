#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game{
public:
    Game();  // 建構函式
    void run();  // 遊戲主迴圈
    bool isGameOver() const;  // 檢查遊戲是否結束
    void displayBoard() const;  // 顯示棋盤

private:
    Board board;  // 棋盤
    Player player1, player2;  // 兩名玩家
    int currentPlayer;  // 目前輪到的玩家 (1 或 2)
    
    void switchTurn();  // 切換玩家回合
    void processTurn();  // 處理玩家回合
};

#endif
