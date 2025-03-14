#ifndef GAME_H
#define GAME_H

#include "GameConfig.h"
#include "GameProcessor.h"
#include "TurnManager.h"
#include "enums/TeamEnum.h"
#include "player/Player.h"
#include "board/Board.h"

#include <enet/enet.h>

class Game {
private:
	TurnManager _turnManager;
	GameProcessor _processor;

	std::unordered_map<TeamType, int> _teamType;
	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>> _players;
	Board _board;

public:
	Game(GameConfig config);

	void start();
	void end();
	void end(TeamType vectoryTeam);
};

#endif