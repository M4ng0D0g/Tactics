#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../../event/PacketHandler.h"

#include <memory>
#include <enet/enet.h>
#include <utility>

class ClientManager : public std::enable_shared_from_this<ClientManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;
	//監聽PacketHandler
	//存放unordered_map<ENetPeer*, Player>
	// std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
public:
	ClientManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);

	//監聽到PacketHandler(已解包成陣列) -> 判斷Peer是否存在 -> 分析事件並傳入參數
	void update(ENetEvent&);
	

	//中間事件 -> 用於提交請求給GameMediator (紀錄Peer的點擊訊息 -> Player儲存並判定是否執行)
	//Event
	void clickHand(int index);
	void clickBoard(std::pair<int, int> loc);

	

	//收到callback -> 做包(字串) -> 請求PacketHandler發送

	

};

#endif