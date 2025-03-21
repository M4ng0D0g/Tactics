#include "Game.h"
#include "../../connection/PacketHandler.h"

Game::Game(const GameConfig& config) {
	_gameMediator = std::make_shared<GameMediator>(shared_from_this());

	_boardManager = std::make_shared<BoardManager>(config, _gameMediator);
	_clientManager = std::make_shared<ClientManager>(config, _gameMediator);
	_playerManager = std::make_shared<PlayerManager>(config, _gameMediator);
	_turnManager = std::make_shared<TurnManager>(config, _gameMediator);

	_gameMediator->setupManager(_boardManager, _clientManager, _playerManager, _turnManager);
}

void Game::start() {
	if(_gameStart) return;
	_gameStart = true;

	PacketHandler::getInstance().registerObserver(_clientManager);
	_turnManager->turnStart();
}

void Game::end() {
	if(!_gameStart) return;
	_gameStart = false;
	PacketHandler::getInstance().unregisterObserver(_clientManager);
}

void Game::end(TeamType vectoryTeam) {
	if(!_gameStart) return;
	_gameStart = false;
	PacketHandler::getInstance().unregisterObserver(_clientManager);
}