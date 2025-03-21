#include "Stamina.h"

Stamina::Stamina(int value, int lowerLimit, int upperLimit)
: LimitStatus(value, lowerLimit, upperLimit) {}

void Stamina::addValue(int value) { _value += value; }
void Stamina::removeValue(int value) { _value -= value; }

bool Stamina::isEnough(int value) const { return _value >= value; }
