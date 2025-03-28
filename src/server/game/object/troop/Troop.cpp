#include "game/object/Troop.h"

Troop::Troop(TroopEnum::Type, TeamEnum::Type, int defaultHp, int defaultAtk, std::shared_ptr<ICommandProcessor> processor)
	: _type(type), _team(team), _defaultHp(defaultHp), _defaultAtk(defaultAtk), _hp(defaultHp), _atk(defaultAtk) {}

std::shared_ptr<Troop> Troop::getShared() {
	return shared_from_this();
}

TeamEnum::Type Troop::getTeam() const {
	return _team;
}

TroopEnum::Type Troop::getType() const {
	return _type;
}

std::pair<int, int> Troop::getLocation() const {
	return _loc;
}

int Troop::getDefaultHp() const {
	return _defaultHp;
}

int Troop::getDefaultAtk() const {
	return _defaultAtk;
}

int Troop::getHp() const {
	return _hp;
}

int Troop::getAtk() const {
	return _atk;
}

void Troop::setLocation(std::pair<int, int> loc) {
	_loc = loc;
}

void Troop::setAction(TroopEnum::Action actionEnum, std::shared_ptr<ITroopAction> action) {
	_actions[actionEnum] = action;
}

void Troop::setDefaultHp(int hp) {
	_defaultHp = hp;
}

void Troop::setDefaultAtk(int atk) {
	_defaultAtk = atk;
}

void Troop::setHp(int hp) {
	_hp = hp;
}

void Troop::setAtk(int atk) {
	_atk = atk;
}

void Troop::performAction(TroopEnum::Action action) {
	if(_actions.contains(action)) {
		auto command = std::make_shared<TroopCommand>(_actions[action], shared_from_this());
		_processor->queueCommand(command);
	}
}