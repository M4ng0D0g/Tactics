#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../enums/TeamEnum.h"

#include <memory>
#include <vector>
#include <unordered_map>

class TurnManager : public std::enable_shared_from_this<TurnManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;

	TeamMode _teamMode;
	std::vector<TeamType>& _teamList;
	std::vector<TeamType>& _enemyList;
	int _activeTeamIndex = 1;
	

public:
	TurnManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);

	void turnStart();
	void turnEnd();
	//Timer
	// void Timer();
};

#endif