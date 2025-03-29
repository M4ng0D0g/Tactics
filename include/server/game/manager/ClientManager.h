#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "connection/PacketHandler.h"
#include "game/core/GameConfig.h"
#include "game/core/interface/IClientMedi.h"
#include "game/core/interface/IClientData.h"
#include "game/object/player/Player.h"
#include <memory>
#include <string>
#include <utility>

// ***************************************************************************/

class ClientManager {
private:
	std::weak_ptr<IClientMedi> _mediator;
	std::weak_ptr<IClientData> _data;
	
public:
	ClientManager() = default;
	ClientManager(const GameConfig&, std::weak_ptr<IClientMedi>, std::weak_ptr<IClientData>);

	void notify(std::string) const;
	void fetchAndHandle();

private:
	
	std::string getId(std::shared_ptr<Player>) const;
	void clickBoard(const std::string, const std::pair<int, int>&) const;
	void clickHand(const std::string, int) const;
};

#endif