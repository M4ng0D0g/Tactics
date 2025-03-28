#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "game/manager/PlayerManager.h"
#include "game/core/GameConfig.h"
#include "event/PacketHandler.h"

#include <set>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

class ClientManager {
private:
	PlayerManager& _playerManager;

	//Client & Player
	std::unordered_map<std::string, Player> _players;

public:
	ClientManager() = default;
	ClientManager(const GameConfig&, PlayerManager&);

	void notify(std::string) const;
	void fetchAndHandle();

private:
	Player& getPlayer(const std::string id);
	std::string getId(const Player& player) const;
	void clickBoard(const std::string, const std::pair<int, int>&) const;
	void clickHand(const std::string, int) const;
};

#endif