#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include "Game.h"
#include "../manager/BoardManager.h"
#include "../manager/PlayerManager.h"

class GameMediator : public IBoardOps, IGameOps, IPlayerOps {
private:
	Game& _game;
	BoardManager _boardManager;
	PlayerManager _playerManager;
	
public:
	GameMediator() = default;
	GameMediator(const GameConfig& config, Game& game);
	~GameMediator() = default;
};

#endif