#ifndef IGAMEMEDI_H
#define IGAMEMEDI_H

// ***************************************************************************/

class IGameMedi {
public:
	virtual ~IGameMedi() = default;
	
	// virtual void beforeTurn(TeamType team) = 0;
	// virtual void afterTurn(TeamType team) = 0;
	virtual void turnStart() = 0;
	virtual void turnEnd() = 0;
	//Timer
	// void Timer();
};

#endif