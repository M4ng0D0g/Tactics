#ifndef STAMINA_H
#define STAMINA_H

#include "../utils/valueStatus/LimitStatus.h"

class Stamina : public LimitStatus<int> {
public:
	Stamina(int value, int lowerLimit, int upperLimit);

	void addValue(int value);
	void removeValue(int value);

	bool isEnough(int value) const;
};

#endif