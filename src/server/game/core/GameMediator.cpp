#include "game/core/GameMediator.h"

GameMediator::GameMediator(const GameConfig& config, Game& game) : _game(game) {
	_boardManager(config, *this);
	_playerManager(config, *this);
}

void GameMediator::setupManager() {

}
