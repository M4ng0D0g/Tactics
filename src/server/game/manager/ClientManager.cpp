#include "game/manager/ClientManager.h"

ClientManager::ClientManager(const GameConfig& config, std::weak_ptr<IClientMedi> mediator, std::weak_ptr<IClientData> data)
: _mediator(mediator), _data(data) {}

void ClientManager::notify(const enet_uint8& peerId, const nlohmann::json& data) const {
	if(!_data->findPlayer(peerId);) return;
	if(!data.contains("command")) return;
	if(!data.contains("data")) return;

	auto player = _data->getPlayer(peerId);

	if(data["command"] == "clickBoard") {
		auto loc = data["data"].get<std::pair<int, int>>();
		_gameMediator->clickBoard(player, loc);
	}
	if(data["command"] == "clickHand") {
		int index = data["data"].get<int>();
		_gameMediator->clickHand(id, index);
	}
}

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