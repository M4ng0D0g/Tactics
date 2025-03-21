#ifndef GAMEMEDIATOR_H
#define GAMEMEDIATOR_H

#include "Game.h"
#include "../manager/BoardManager.h"
#include "../manager/ClientManager.h"
#include "../manager/PlayerManager.h"
#include "../manager/TurnManager.h"

class GameMediator {
private:
	std::weak_ptr<Game> _game;
	
	std::weak_ptr<BoardManager> _boardManager;
	std::weak_ptr<ClientManager> _clientManager;
	std::weak_ptr<PlayerManager> _playerManager;
	std::weak_ptr<TurnManager> _turnManager;
public:
	GameMediator(std::weak_ptr<Game> game);

	void setupManager(std::weak_ptr<BoardManager> boardManager,
		std::weak_ptr<ClientManager> clientManager,
		std::weak_ptr<PlayerManager> playerManager,
		std::weak_ptr<TurnManager> turnManager);

	//操作需要先判斷manager.lock()

	//board
	bool boardCheckOwingAll(TeamType team);
	bool boardCheckNotEnough(TeamType team);
	bool boardCheckFewer(TeamType team);

	//troop
	void troopBeforeTurn(TeamType team);
	void troopAfterTurn(TeamType team);

	//player
	void playerUpdateStatus(TeamType team);

	//client
	void clientUnlockAction();
	void clientLockAction();
	void clientClickCard();
	void clientClickBoard();
	void clientClickTroop();
	// void clientUpdateScreen();


};


#endif