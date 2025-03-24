#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include "Game.h"
#include "GameData.h"
#include "interface/IBoardOps.h"
#include "interface/IClientOps.h"
#include "interface/IPlayerOps.h"
#include "interface/ITurnOps.h"

#include "../manager/BoardManager.h"
#include "../manager/ClientManager.h"
#include "../manager/PlayerManager.h"
#include "../manager/TurnManager.h"

#include <memory>
#include <stdexcept>

class GameMediator : public IBoardOps, public IClientOps, public IPlayerOps, public ITurnOps {
private:
	std::weak_ptr<Game> _game;
	std::weak_ptr<GameData> _data;
	
	std::weak_ptr<BoardManager> _boardManager;
	std::weak_ptr<ClientManager> _clientManager;
	std::weak_ptr<PlayerManager> _playerManager;
	std::weak_ptr<TurnManager> _turnManager;

	template <typename T>
	std::shared_ptr<T> getManager(std::weak_ptr<T> weakptr) {
		auto manager = weakptr.lock();
		if(!manager) throw std::runtime_error("Manager not found");
		return manager;
	}

public:
	GameMediator(std::weak_ptr<Game> game);

	void setupManager(std::weak_ptr<BoardManager> boardManager,
		std::weak_ptr<ClientManager> clientManager,
		std::weak_ptr<PlayerManager> playerManager,
		std::weak_ptr<TurnManager> turnManager);
};


#endif