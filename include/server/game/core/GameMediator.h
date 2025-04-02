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
	~GameMediator() = default;

	/**
	 * @brief 註冊相關物件。
	 * 
	 * @param game `Game` 弱指標。
	 * @param boardManager `BoardManager` 弱指標。
	 * @param clientManager `ClientManager` 弱指標。
	 * @param playerManager `PlayerManager` 弱指標。
	 */
	void setup(std::weak_ptr<Game>, std::weak_ptr<BoardManager>, std::weak_ptr<ClientManager>, std::weak_ptr<PlayerManager>)
};

#endif