#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "game/core/GameConfig.h"
#include "game/core/interface/IPlayerMedi.h"
#include "game/core/interface/IPlayerData.h"
#include "game/object/player/Player.h"
#include <string>
#include <memory>
#include <utility>
#include <enet/enet.h>

// ***************************************************************************/

class PlayerManager {
private:
	std::weak_ptr<IPlayerMedi> _mediator;
	std::weak_ptr<IPlayerData> _data;

public:
	PlayerManager() = default;
	PlayerManager(const GameConfig&, std::weak_ptr<IPlayerMedi>, std::weak_ptr<IPlayerData>);

	bool clickBoard(std::shared_ptr<Player>, const std::pair<int, int>&);
	bool clickHand(std::shared_ptr<Player>, int);

	bool discardCard(std::shared_ptr<Player>);
	bool drawCard(std::shared_ptr<Player>);

};

#endif