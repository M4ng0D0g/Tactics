#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../../event/PacketHandler.h"

#include <unordered_set>
#include <memory>
#include <enet/enet.h>
#include <utility>
#include <json.hpp>

class ClientManager : public std::enable_shared_from_this<ClientManager> {
private:
	friend class Event;
	friend class SendToMediator;
	friend class ReceiveFromMediator;

	std::weak_ptr<GameMediator> _gameMediator;
	//監聽PacketHandler
	std::unordered_set<ENetPeer*> _peers;
	// std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
public:
	ClientManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);

	class Event {
	private:
		friend class PacketHandler;
		void handle(const ENetPeer*, const nlohmann::json&);
	};

	class SendToMediator {
	private:
		friend class Event;

		//中間事件 -> 用於提交請求給GameMediator (紀錄Peer的點擊訊息 -> Player儲存並判定是否執行)
		void clickBoard(std::pair<int, int> loc);
		void clickHand(int index);
	};

	class ReceiveFromMediator {
	private:
		friend class GameMediator;

		//收到callback -> 做包(字串) -> 請求PacketHandler發送
		void update();
	};


};

#endif