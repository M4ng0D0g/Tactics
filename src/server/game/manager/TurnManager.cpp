
#include "TurnManager.h"
#include "game/GameConfig.h"

TurnManager::TurnManager(GameConfig& config) {

}

void TurnManager::turnStart() {
	//玩家補stamina
	pieceAction(activeTeam); //棋子先行動
	//玩家可以操作
}

void TurnManager::turnEnd() {
	//結算操作更新
	//渲染雙方畫面
	//如果有方輸了就結束
	//下一位(待優化)
	activeTeam = enemy[activeTeam];
	turnStart();
}
//Timer
// void Timer();