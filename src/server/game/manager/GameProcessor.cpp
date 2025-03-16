#include "GameProcessor.h"


GameProcessor::GameProcessor(
	GameConfig& config,
	Board& board,
	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& players
) : _board(board), _players(players) { //[X]

}

//Common
// Board& getBoard() { return board; }
// std::unordered_map<TeamType, Player>& getPlayers() { return players; }

//Board [DONE]
void GameProcessor::dominateTile(TeamType team, std::pair<int,int>) { // [O]
	if(!board.isInBoard(pos)) return;
	board.getTile(pos).setTeam(team);
}

void GameProcessor::summonTroop(TroopType type, TeamType team, std::pair<int,int> pos) { // [O]
	Troop troop = factory.createTroop(type, team, this); //[REVIEW] this是否過於繁瑣
	board.getTile(pos).setTroop(troop);
}

void GameProcessor::removeTroop(std::pair<int,int> pos) {
	if(!board.isInBoard(pos)) return;
	board.getTile(pos).removeTroop();
}

//Troop [TODO] 步進動作
void GameProcessor::troopAct(ActionCommand& command) { //[!] 更新畫面
	command.execute(_board);
	
}

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
