#ifndef TROOP_H
#define TROOP_H

#include "../GameProcessor.h"
#include "../utils/ValueStatus.h"
#include "../enums/TeamEnum.h"
#include "../enums/TroopEnum.h"
#include "./action/interface/ITroopAction.h"
#include "./TroopCommand.h"

#include <utility>
#include <memory>

class ITroopAction;
class TroopCommand;
class GameProcessor;

class Troop : public std::enable_shared_from_this<Troop> {
private:
	GameProcessor& _processor;
	TroopType _type;
	TeamType _team;
	std::pair<int, int> _loc;
	ValueStatus _hp;
	ValueStatus _atk;
	
	std::unique_ptr<ITroopAction> _beforeTurn = nullptr;
	std::unique_ptr<ITroopAction> _afterTurn = nullptr;
	std::unique_ptr<ITroopAction> _onSummon = nullptr;
	std::unique_ptr<ITroopAction> _onClick = nullptr;
	std::unique_ptr<ITroopAction> _onHit = nullptr;
	std::unique_ptr<ITroopAction> _hitTroop = nullptr;
	std::unique_ptr<ITroopAction> _onDying = nullptr;
public:
	Troop(GameProcessor& processor, TroopType type, TeamType team, int defaultHP, int atk);

	//Getter
	std::shared_ptr<Troop> getShared();
	std::pair<int, int> getLocation();
	ValueStatus getHp();
	ValueStatus getAtk();

	//Setter
	void setLocation(std::pair<int, int> loc);
	void setBeforeTurn(std::unique_ptr<ITroopAction> action);

	//Perform
	void performBeforeTurn();
	void performAfterTurn();

	void performOnSummon();
	void performOnDying();
	void performOnClick();
	void performMoveAfter();
	void performOnHit();
	void performHitTroop();

	void performOnFriendSummon();
	void performOnFriendDying();
	void performOnFriendClick();
	void performFriendMoveAfter();
	void performOnFriendHit();
	void performFriendHitTroop();
};

#endif


