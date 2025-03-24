#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../../event/PacketHandler.h"

#include <set>
#include <memory>
#include <enet/enet.h>
#include <utility>
#include <json.hpp>

class ClientManager : public std::enable_shared_from_this<ClientManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;

public:
	ClientManager(const GameConfig&, std::weak_ptr<GameMediator>);

	// PacketHandler
	void notice(const ENetPeer*, const nlohmann::json&) const;

private:
	void clickBoard(const boost::uuids::uuid, std::pair<int, int>) const;
	void clickHand(const boost::uuids::uuid, int) const;
};

#endif