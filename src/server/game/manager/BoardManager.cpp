#include "game/manager/BoardManager.h"

BoardManager::BoardManager(const GameConfig& config, GameMediator& mediator) : _mediator(mediator) {

}

//Board
void BoardManager::occupyTile(std::pair<int,int> loc, TeamType team) {
	if(!_board.isValid()) return;
	_board.setTileTeam(loc, team);
}

// bool isTileOccupied(std::pair<int,int> loc);
bool BoardManager::isTileOwnedBy(std::pair<int,int> loc, TeamType team) {
	if(!_board.isValid()) return;
	return _board.getTileTeam(loc) == team;
}

bool BoardManager::isAllTileOwned() {

}

bool BoardManager::isOwningAllTile(TeamType team);
bool BoardManager::isFewerThanRequiredTile(TeamType team);
bool BoardManager::isFewerThanEnemyTile(TeamType team);

void summonTroop(std::pair<int,int> loc, TroopType type, TeamType team);
void removeTroop(std::pair<int,int> loc);


//Troop [TODO] 步進動作(做在Clinet)
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

//Board [DONE]
void GameProcessor::dominateTile(TeamType team, std::pair<int,int>) { // [O]
	
}

void GameProcessor::summonTroop(TroopType type, TeamType team, std::pair<int,int> pos) { // [O]
	Troop troop = factory.createTroop(type, team, this); //[REVIEW] this是否過於繁瑣
	board.getTile(pos).setTroop(troop);
}

void GameProcessor::removeTroop(std::pair<int,int> pos) {
	if(!board.isInBoard(pos)) return;
	board.getTile(pos).removeTroop();
}

//Troop [TODO] 步進動作
void GameProcessor::troopAct(ActionCommand& command) { //[!] 更新畫面
	command.execute(_board);
	
}
