#ifndef GAME_H
#define GAME_H

#include "GameConfig.h"
#include "GameData.h"
#include "TurnController.h"
#include "interface/IGameMedi.h"
#include <memory>

// ***************************************************************************/

class Game : public std::enable_shared_from_this<Game> {
private:
	GameData _data;
	TurnController _turnController;
	std::weak_ptr<IGameMedi> _mediator;

public:
	Game(const GameConfig& config);

	void gameStart();
	void turnStart();
	void turnEnd();
	void teamEliminate(TeamEnum::Type eliminatedTeam);
	void teamWin(TeamEnum::Type victoryTeam);
	void gameEnd();

	void gameLoop();
};

#endif