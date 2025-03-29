#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include "Game.h"
#include "interface/IBoardMedi.h"
#include "interface/IClientMedi.h"
#include "interface/IGameMedi.h"
#include "interface/IPlayerMedi.h"
#include "game/manager/BoardManager.h"
#include "game/manager/ClientManager.h"
#include "game/manager/PlayerManager.h"
#include <memory>

// ***************************************************************************/

class GameMediator : public IBoardMedi, IClientMedi, IGameMedi, IPlayerMedi {
private:
	std::weak_ptr<Game> _game;
	std::weak_ptr<BoardManager> _boardManager;
	std::weak_ptr<ClientManager> _clientManager;
	std::weak_ptr<PlayerManager> _playerManager;
	
public:
	GameMediator() = default;
	GameMediator(const GameConfig& config, Game& game);
	~GameMediator() = default;
};

#endif