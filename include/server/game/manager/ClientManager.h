#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "connection/interface/IClientEvent.h"
#include "game/core/GameConfig.h"
#include "game/core/interface/IClientMedi.h"
#include "game/core/interface/IClientData.h"
#include "game/object/player/Player.h"
#include <memory>
#include <utility>
#include <json.hpp>
#include <enet/enet.h>

// ***************************************************************************/

class ClientManager {
private:
	std::weak_ptr<IClientMedi> _mediator;
	std::weak_ptr<IClientData> _data;

	IClientEvent& _packetHandler;
	
public:
	ClientManager() = default;
	ClientManager(const GameConfig&, std::weak_ptr<IClientMedi>, std::weak_ptr<IClientData>);

	/**
	 * @brief 監聽 `PacketHandler`，當被通知時，從 `GameData` 查找對應 `PeerId`，若找到則處理事件。
	 * 
	 * @param peerId 事件發送端的 `PeerId`。
	 * @param data 資料 `JSON` 包。
	 */
	void notify(const enet_uint8& peerId, const nlohmann::json& data) const;
};

#endif