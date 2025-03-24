#include "Player.h"

Stamina::Stamina(int value, int lowerLimit, int upperLimit)
	: _value(value), _lowerLimit(lowerLimit), _upperLimit(upperLimit) {}

void Stamina::getValue(int& value) const {
	value = _value;
}

void Stamina::getLowerLimit(int& lowerLimit) const {
	lowerLimit = _lowerLimit;
}

void Stamina::getUpperLimit(int& upperLimit) const {
	upperLimit = _upperLimit;
}

void Stamina::addValue(int value) {
	_value += value;
}

void Stamina::removeValue(int value) {
	_value -= value;
}

bool Stamina::isEnough(int value) const {
	return _value >= value;
}