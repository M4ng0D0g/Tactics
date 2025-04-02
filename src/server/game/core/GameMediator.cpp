#include "game/core/GameMediator.h"

GameMediator::GameMediator(
	std::weak_ptr<Game> game,
	std::weak_ptr<BoardManager> boardManager,
	std::weak_ptr<ClientManager> clientManager,
	std::weak_ptr<PlayerManager> playerManager
) : _game(game), _boardManager(boardManager), _clientManager(clientManager), _playerManager(playerManager) {}


//Client


void GameMediator::lockOperation() override {}
void GameMediator::unlockOperation() override {}
void GameMediator::clickBoard(std::shared_ptr<Player>, std::pair<int, int>) override {}
void GameMediator::clickHand(std::shared_ptr<Player>, int) override {}
