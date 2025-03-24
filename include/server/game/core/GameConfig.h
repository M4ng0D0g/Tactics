#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include "enums/TeamEnum.h"

#include <vector>
#include <enet/enet.h>

class GameConfig {
public:
	GameConfig();

	TeamMode _teamMode;
	std::unordered_map<TeamType, int> _teamType;
	std::unordered_map<TeamType, std::vector<ENetPeer*>> _peers;
	
	int _handLim = 7;
	int _staminaIni = 0;
	int _staminaLim = 10;
	int _summonCost = 5;
	int _discardCost = 1;

	// void setupPlayers(std::unordered_map<TeamType, std::vector<ENetPeer*>>& _players);
};

#endif