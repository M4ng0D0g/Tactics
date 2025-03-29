#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "GameMediator.h"
#include "interface/IBoardData.h"
#include "interface/IClientData.h"
#include "interface/IGameData.h"
#include "interface/IPlayerData.h"
#include "game/manager/BoardManager.h"
#include "game/manager/ClientManager.h"
#include "game/manager/PlayerManager.h"
#include "game/object/board/Board.h"
#include "game/object/card/CardFactory.h"
#include "game/object/player/Player.h"
#include "game/object/troop/Troop.h"
#include "game/object/troop/TroopFactory.h"
#include <memory>

// ***************************************************************************/

class GameData : public IBoardData, IClientData, IGameData, IPlayerData {
private:
	std::shared_ptr<GameMediator> _mediator;
	std::shared_ptr<BoardManager> _boardManager;
	std::shared_ptr<ClientManager> _clientManager;
	std::shared_ptr<PlayerManager> _playerManager;

	//Game
	bool _gameStart = false;

	//Board
	std::shared_ptr<Board> _board;
	std::shared_ptr<TroopFactory> _troopFactory;
	std::vector<std::shared_ptr<TroopCommand>> _troopCommands;
	std::unordered_map<TeamEnum::Type, std::vector<std::shared_ptr<Troop>>> _troopMap;

	//Client & Player
	std::unordered_map<std::string, Player> _players;
	std::shared_ptr<CardFactory> _cardFactory;

public:
	GameData() = default;
	GameData(
		std::shared_ptr<GameMediator>,
		std::shared_ptr<BoardManager>,
		std::shared_ptr<ClientManager>,
		std::shared_ptr<PlayerManager>
	);


};

#endif