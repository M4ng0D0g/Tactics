#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "game/core/GameConfig.h"
#include "game/core/interface/IBoardMedi.h"
#include "game/core/interface/IBoardData.h"
#include "game/enums/TeamEnum.h"
#include "game/object/troop/interface/ICommandProcessor.h"
#include <memory>
#include <unordered_map>
#include <vector>

// ***************************************************************************/

class BoardManager : ICommandProcessor {
private:
	std::weak_ptr<IBoardMedi> _mediator;
	std::weak_ptr<IBoardData> _data;

public:
	BoardManager() = default;
	BoardManager(const GameConfig&, std::weak_ptr<IBoardMedi>, std::weak_ptr<IBoardData>);

	//Board
	void occupyTile(std::pair<int,int> loc, TeamEnum::Type team);
	// bool isTileOccupied(std::pair<int,int> loc);
	bool isTileOwnedBy(std::pair<int,int> loc, TeamEnum::Type team);
	bool isAllTileOwned();
	bool isOwningAllTile(TeamEnum::Type team);
	bool isFewerThanRequiredTile(TeamEnum::Type team);
	bool isFewerThanEnemyTile(TeamEnum::Type team);
	
	void summonTroop(std::pair<int,int> loc, TroopEnum::Type type, TeamEnum::Type team);
	void removeTroop(std::pair<int,int> loc);

	//Troop
	void triggerBeforeTurn(TeamEnum::Type team);
	void triggerAfterTurn(TeamEnum::Type team);

	void triggerOnSummon(std::shared_ptr<Troop>& troop);
	void triggerOnDying(std::shared_ptr<Troop>& troop);
	void triggerOnClick(std::shared_ptr<Troop>& troop);
	void triggerMoveAfter(std::shared_ptr<Troop>& troop);
	void triggerOnHit(std::shared_ptr<Troop>& troop);
	void triggerHitTroop(std::shared_ptr<Troop>& troop);

	void triggerOnFriendSummon(TeamEnum::Type team);
	void triggerOnFriendDying(TeamEnum::Type team);
	void triggerOnFriendClick(TeamEnum::Type team);
	void triggerFriendMoveAfter(TeamEnum::Type team);
	void triggerOnFriendHit(TeamEnum::Type team);
	void triggerFriendHitTroop(TeamEnum::Type team);
};

#endif