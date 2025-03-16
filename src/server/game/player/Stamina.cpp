#include "Stamina.h"

Stamina::Stamina(int value, int lowerLimit, int upperLimit)
: _base(value), _value(_base, lowerLimit, upperLimit) {}

int Stamina::getValue() const {	return _value.getValue(); }

void Stamina::setValue(int value) { _value.setValue(value); }
void Stamina::addValue(int value) { _value.setValue(_value.getValue() + value); }
void Stamina::removeValue(int value) { _value.setValue(_value.getValue() - value); }
void Stamina::clamp() { _value.clamp(); }

bool Stamina::isEnough(int value) const { return _value.getValue() >= value; }
