#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../player/Player.h"
#include "../card/CardSimpleFactory.h"

#include <memory>

class PlayerManager : public std::enable_shared_from_this<PlayerManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;

public:
	PlayerManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);

	bool clickBoard(boost::uuids::uuid, std::pair<int, int>);
	bool clickHand(boost::uuids::uuid, int);

private:
	Player& getPlayer(boost::uuids::uuid id);
	bool discardCard(Player&);
	bool drawCard(Player&);

};

#endif