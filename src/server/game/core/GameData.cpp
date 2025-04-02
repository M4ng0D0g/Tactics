#include "game/core/GameData.h"


GameData::GameData(const GameConfig& config, std::weak_ptr<Game> game) {
	_mediator = std::make_shared<GamMediator>();
	_data = std::make_shared(*this);

	_boardManager = std::make_shared<BoardManager>(config, _mediator, _data);
	_clientManager = std::make_shared<ClientManager>(config, _mediator, _data);
	_playerManager = std::make_shared<PlayerManager>(config, _mediator, _data);
	_mediator.setup(game, _boardManager, _clientManager, _playerManager);
}

bool GameData::findPlayer(const enet_uint8&) override {

}
bool GameData::getPlayer(const enet_uint8&) override {
	
}