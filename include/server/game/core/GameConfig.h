#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include "game/enums/TeamEnum.h"
#include <string>

// ***************************************************************************/

class GameConfig {
public:
	GameConfig() {}

	TeamEnum::Mode _teamMode = TeamEnum::Mode::TeamMode_2;
	std::unordered_map<std::string, TeamEnum::Type> _peers;
	
	int _handLim = 7;
	int _staminaIni = 0;
	int _staminaLim = 10;
	int _summonCost = 5;
	int _discardCost = 1;

	// void setupPlayers(std::unordered_map<TeamType, std::vector<ENetPeer*>>& _players);
};

#endif