#ifndef STAMINA_H
#define STAMINA_H

#include "../utils/valueStatus/base/Value.h"
#include "../utils/valueStatus/LimitDeco.h"

class Stamina {
private:
	Value<int> _base;
	LimitDeco<int> _value;

public:
	Stamina(int value, int lowerLimit, int upperLimit);

	int getValue() const;

	void setValue(int value);
	void addValue(int value);
	void removeValue(int value);
	void clamp();

	bool isEnough(int value) const;
	
};

#endif