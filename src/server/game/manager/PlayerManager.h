#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"

#include <memory>

class PlayerManager : public std::enable_shared_from_this<PlayerManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;
std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
public:
	PlayerManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);
};

#endif