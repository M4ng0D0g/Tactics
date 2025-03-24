#include "troop/Troop.h"

Troop();

//Getter
std::shared_ptr<Troop> Troop::getShared() {
	return std::shared_from_this();
}
std::pair<int, int> Troop::getLocation() {
	return _loc;
}
ValueStatus getHp() {
	return _hp;
}
ValueStatus getAtk() {
	return _atk;
}

//Setter
void Troop::setLocation(std::pair<int, int> loc) {
	_loc = loc;
}

void Troop::setBeforeTurn(std::unique_ptr<ITroopAction> action) {
	_beforeTurnAction = std::move(action);
}
void Troop::setAfterTurn(std::unique_ptr<ITroopAction> action) {
	_afterTurnAction = std::move(action);
}
void Troop::setOnSummon(std::unique_ptr<ITroopAction> action) {
	_onSummonAction = std::move(action);
}
void Troop::setOnClick(std::unique_ptr<ITroopAction> action) {
	_onClickAction = std::move(action);
}
void Troop::setOnHit(std::unique_ptr<ITroopAction> action) {
	_nHitAction = std::move(action);
}
void Troop::setHitTroop(std::unique_ptr<ITroopAction> action) {
	_hitTroopAction = std::move(action);
}
void Troop::setOnDying(std::unique_ptr<ITroopAction> action) {
	_onDyingAction = std::move(action);
}

//Perform
void performBeforeTurn() {
	if(!_beforeTurnAction) return;
	auto command = std::make_shared<ActionCommand>(_beforeTurnAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performAfterTurn() {
	if(!_afterTurnAction) return;
	auto command = std::make_shared<ActionCommand>(_afterTurnAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performOnSummon() {
	if(!_onSummonAction) return;
	auto command = std::make_shared<ActionCommand>(_onSummonAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performOnClick() {
	if(!_onClickAction) return;
	auto command = std::make_shared<ActionCommand>(_onClickAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performOnHit() {
	if(!_onHitAction) return;
	auto command = std::make_shared<ActionCommand>(_onHitAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performHitTroop() {
	if(!_hitTroopAction) return;
	auto command = std::make_shared<ActionCommand>(_hitTroopAction, std::shared_from_this());
	_processor.troopAct(command);
}
void performOnDying() {
	if(!_onDyingAction) return;
	auto command = std::make_shared<ActionCommand>(_onDyingAction, std::shared_from_this());
	_processor.troopAct(command);
}

