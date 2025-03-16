#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "enums/TeamEnum.h"
#include "GameConfig.h"

#include <enet/enet.h>

class TurnManager {
private:
	std::unordered_map<TeamType, int>& _teamType;
	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;

	int _activeTeamIndex;

public:
	TurnManager(GameConfig config);

	void turnStart();
	void turnEnd();
	//Timer
	// void Timer();
};

#endif