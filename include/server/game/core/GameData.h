#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "Game.h"
#include "GameConfig.h"
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
#include <enet/enet.h>

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
	std::unordered_map<enet_uint8, std::shared_ptr<Player>> _players;
	std::shared_ptr<CardFactory> _cardFactory;

public:
	GameData() = default;
	/**
	 * @brief
	 * 
	 * 建立所有的遊戲基本物件。
	 * 
	 * 優先建立 `GameMediator`，接著建立各 `Manager` 並傳入所需弱指標進行初始化，最後將 `GameMediator` 弱指標配置給各 `Manager`。
	 * 
	 * @param config 遊戲設定選項。
	 * @param game `Game` 弱指標。
	 */
	GameData(const GameConfig& config, std::weak_ptr<Game> game);


};

#endif