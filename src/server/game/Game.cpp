
#include "Board.h"
#include "Player.h"
#include "TeamEnum.h"
#include "GameSettings.h"
#include "Timer.h"
#include <vector>
#include <unordered_map>

using namespace std;

class Game {
private:
    GameSettings settings;
    Board board;
    unordered_map<Team, Player> players;

    Team activeTeam;
    unordered_map<Team, Team> enemy = {
        {Team0, Team1},
        {Team1, Team0}
    }; //待優化(放在settings注入)
public:
    Game(const GameSettings& setup) : settings(setup) {
        //teamMode
        //setup
        //build player
        
    }
    //rootEvent
    void gameStart() {
        //啟動常駐狀態
        //抽先手方

    }
    void gameEnd() {}

    //inGameEvent
    void turnStart() {
        //玩家補stamina
        pieceAction(activeTeam); //棋子先行動
        //玩家可以操作
    }
    void turnEnd() {
        //結算操作更新
        //渲染雙方畫面
        //如果有方輸了就結束
        //下一位(待優化)
        activeTeam = enemy[activeTeam];
        turnStart();
    }

    void summonPieceEvent() {
        //判斷玩家是否有足夠stamina
        //判斷該位置是否可以召喚
        //更新數值並刪除特定手牌
        //召喚棋子
    }
    void movePieceEvent() {
        //(玩家已經確認操作)
        //檢查玩家是否有足夠stamina
        //檢查玩家操作是否合理
        //執行特殊動作
    }
    void sellPieceEvent(Tile& tile) {
        //檢查條件是否合理
        //販售並給予對應回饋
        if(tile.getTeam() == activeTeam && tile.hasPiece()) tile.sellPiece();
    }
    //npcEvent
    void pieceAction(Team team) {
        //攻擊&佔領演算法
    };
    
};