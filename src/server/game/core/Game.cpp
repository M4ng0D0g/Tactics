#include "Game.h"
#include "../../connection/PacketHandler.h"

Game::Game(const GameConfig& config) {
	_boardManager = BoardManager(config, _mediator);
	_clientManager = ClientManager(config, _mediator);
	_playerManager = PlayerManager(config, _mediator);
	_turnManager = TurnManager(config, _mediator);

	_mediator->setupManager(_boardManager, _clientManager, _playerManager, _turnManager);
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