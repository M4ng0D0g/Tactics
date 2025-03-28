#ifndef IGAMEOPS_H
#define IGAMEOPS_H

class IGameOps {
public:
	// virtual void beforeTurn(TeamType team) = 0;
	// virtual void afterTurn(TeamType team) = 0;
	virtual void turnStart() = 0;
	virtual void turnEnd() = 0;
	//Timer
	// void Timer();
};

#endif