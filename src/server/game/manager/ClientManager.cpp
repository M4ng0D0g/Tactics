#include "ClientManager.h"

ClientManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator)
: _gameMediator(gameMediator) {}

//監聽到PacketHandler(已解包成陣列) -> 判斷Peer是否存在 -> 分析事件並傳入參數
void update(ENetEvent&) {
	if()
}


//中間事件 -> 用於提交請求給GameMediator (紀錄Peer的點擊訊息 -> Player儲存並判定是否執行)
//Event
void clickHand(int index);
void clickBoard(std::pair<int, int> loc);

/*
//Event [REVIEW]
void GameProcessor::summonTroopEvent(const char* data) { //[!] 合併? 
	//[!] 完善拆封包流程
	Player player;
	TroopType type;
	std::pair<int,int> pos;
	int summonCost = settings.SummonCost;
	//判斷玩家是否有足夠stamina
	if(!player.getStamina().isEnough(summonCost)) return;
	//判斷該位置是否可以召喚
	if(!board.isInBoard(pos)) return;
	//更新數值並刪除特定手牌
	//召喚棋子
	player.getStamina().addValue(-summonCost);
	summonTroop(type, player.getTeam);
}

void GameProcessor::moveTroopEvent() { //[X]
	//(玩家已經確認操作)
	//檢查玩家是否有足夠stamina
	//檢查玩家操作是否合理
	//執行特殊動作
}
// void sellTroopEvent(Tile& tile) {
// 	//檢查條件是否合理
// 	//販售並給予對應回饋
// 	if(tile.getTeam() == activeTeam && tile.hasTroop()) tile.sellTroop();
// }
*/