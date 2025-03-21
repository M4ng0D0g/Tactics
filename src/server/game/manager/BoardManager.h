#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "../core/GameConfig.h"
#include "../core/GameMediator.h"
#include "../board/Board.h"
#include "../troop/Troop.h"
#include "../troop/TroopFactory.h"
#include "../enums/TeamEnum.h"

#include <memory>
#include <unordered_map>
#include <vector>

class BoardManager : public std::enable_shared_from_this<BoardManager> {
private:
	std::weak_ptr<GameMediator> _gameMediator;
	
	Board _board;
	TroopFactory _troopFactory;
	std::unordered_map<TeamType, std::vector<std::shared_ptr<Troop>>> _troopMap;

public:
	BoardManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator);

	//Board
	void occupyTile(std::pair<int,int> loc, TeamType team);
	// bool isTileOccupied(std::pair<int,int> loc);
	bool isTileOwnedBy(std::pair<int,int> loc, TeamType team);
	bool isAllTileOwned();
	bool isOwningAllTile(TeamType team);
	bool isFewerThanRequiredTile(TeamType team);
	bool isFewerThanEnemyTile(TeamType team);
	
	void summonTroop(std::pair<int,int> loc, TroopType type, TeamType team);
	void removeTroop(std::pair<int,int> loc);

	//Troop
	void triggerBeforeTurn(TeamType team);
	void triggerAfterTurn(TeamType team);

	void triggerOnSummon(std::shared_ptr<Troop>& troop);
	void triggerOnDying(std::shared_ptr<Troop>& troop);
	void triggerOnClick(std::shared_ptr<Troop>& troop);
	void triggerMoveAfter(std::shared_ptr<Troop>& troop);
	void triggerOnHit(std::shared_ptr<Troop>& troop);
	void triggerHitTroop(std::shared_ptr<Troop>& troop);

	void triggerOnFriendSummon(TeamType team);
	void triggerOnFriendDying(TeamType team);
	void triggerOnFriendClick(TeamType team);
	void triggerFriendMoveAfter(TeamType team);
	void triggerOnFriendHit(TeamType team);
	void triggerFriendHitTroop(TeamType team);
	
	void troopAct(TroopCommand& command);
};

#endif