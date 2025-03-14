#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include "enums/Team.h"

class TurnManager {
private:
	enum _teams;
	_activeTeamIndex;
	int _activePlayerIndex;

public:
	void turnEnd();
	void nextTurn();
	//Timer
	// void Timer();
};

#endif