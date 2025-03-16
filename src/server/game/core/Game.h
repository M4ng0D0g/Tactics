#ifndef GAME_H
#define GAME_H

#include "GameMediator.h"
#include "GameConfig.h"
#include "GameProcessor.h"
#include "../managers/TurnManager.h"

#include <enet/enet.h>
#include <memory>

class Game {
private:
	std::unique_ptr<GameMediator> _gameMediator;

	std::unique_ptr<TurnManager> _turnManager;
	std::unique_ptr<BoardManager> _boardManager;
	std::unique_ptr<PlayerManager> _playerManager;

public:
	Game(GameConfig& config)

	void start();
	void end();
	void end(TeamType vectoryTeam);

};

// class Game {
// private:
// 	TurnManager _turnManager;
// 	GameProcessor _processor;

// 	std::unordered_map<TeamType, int> _teamType;
// 	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>> _players;
// 	Board _board;

// public:
	// Game(GameConfig config);

	// void start();
	// void end();
	// void end(TeamType vectoryTeam);
// };

#endif