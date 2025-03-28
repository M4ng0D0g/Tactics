#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "ClientManager.h"
#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../object/player/Player.h"
#include "../object/card/CardFactory.h"

#include <memory>

class PlayerManager {
private:
	GameMediator& _mediator;
	ClientManager _clientManager;

	CardFactory _cardFactory;

public:
	PlayerManager() = default;
	PlayerManager(const GameConfig&, GameMediator&);

	bool clickBoard(boost::uuids::uuid, std::pair<int, int>);
	bool clickHand(boost::uuids::uuid, int);

private:
	Player& getPlayer(boost::uuids::uuid id);
	bool discardCard(Player&);
	bool drawCard(Player&);

};

#endif