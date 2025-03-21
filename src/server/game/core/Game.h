#ifndef GAME_H
#define GAME_H

#include "GameMediator.h"
#include "GameConfig.h"
#include "GameProcessor.h"
#include "../manager/BoardManager.h"
#include "../manager/ClientManager.h"
#include "../manager/PlayerManager.h"
#include "../manager/TurnManager.h"

#include <memory>

class Game : public std::enable_shared_from_this<Game> {
private:
	bool _gameStart = false;
	std::shared_ptr<GameMediator> _gameMediator;

	std::shared_ptr<BoardManager> _boardManager;
	std::shared_ptr<ClientManager> _clientManager;
	std::shared_ptr<PlayerManager> _playerManager;
	std::shared_ptr<TurnManager> _turnManager;
public:
	Game(const GameConfig& config);

	void start();
	void end();
	void end(TeamType vectoryTeam);
};

#endif