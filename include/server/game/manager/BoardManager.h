#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../enums/TeamEnum.h"
#include "../object/troop/interface/ICommandProcessor.h"
#include "../object/board/Board.h"
#include "../object/troop/Troop.h"
#include "../object/troop/TroopFactory.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BoardManager : ICommandProcessor {
private:
	GameMediator& _mediator;

	//Board
	Board _board;
	TroopFactory _troopFactory;
	std::vector<std::shared_ptr<TroopCommand>> _troopCommands;
	std::unordered_map<TeamEnum::Type, std::vector<std::shared_ptr<Troop>>> _troopMap;

public:
	BoardManager() = default;
	BoardManager(const GameConfig&, GameMediator&);

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