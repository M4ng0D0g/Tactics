#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include "game/enums/TeamEnum.h"
#include <enet/enet.h>

// ***************************************************************************/

class GameConfig {
public:
	GameConfig() {}

	/**
	 * @brief 隊伍模式：`TurnController`
	 */
	TeamEnum::Mode _teamMode = TeamEnum::Mode::TeamMode_2;
	/**
	 * @brief `PeerId-隊伍`：`TurnController`、`GameData`
	 */
	std::unordered_map<const enet_uint8&, TeamEnum::Type> _peers;
	
	/**
	 * @brief 基礎手牌上限：`Player`
	 */
	int _handLim = 7;
	/**
	 * @brief 初始行動點數：`Player`
	 */
	int _staminaIni = 0;
	/**
	 * @brief 基礎行動點數上限：`Player`
	 */
	int _staminaLim = 10;
	/**
	 * @brief 召喚所需行動點數：`PlayerManager`
	 */
	int _summonCost = 5;
	/**
	 * @brief 棄牌所需行動點數：`PlayerManager`
	 */
	int _discardCost = 1;

	// void setupPlayers(std::unordered_map<TeamType, std::vector<ENetPeer*>>& _players);
};

#endif