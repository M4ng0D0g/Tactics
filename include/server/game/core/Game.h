#ifndef GAME_H
#define GAME_H

#include "GameConfig.h"
#include "GameMediator.h"
#include "TurnController.h"

#include <memory>

class Game {
private:
	GameMediator _mediator;
	TurnController _turnController;

	bool _gameStart = false;

public:
	Game(const GameConfig& config);

	void gameStart();
	void turnStart();
	void turnEnd();
	void teamEliminate(TeamType eliminatedTeam);
	void teamWin(TeamType victoryTeam);
	void gameEnd();

	void gameLoop();
};

#endif