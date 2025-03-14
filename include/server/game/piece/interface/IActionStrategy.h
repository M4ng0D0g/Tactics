#ifndef ACTIONSTRATEGY_H
#define ACTIONSTRATEGY_H

#include "../ActionCommand.h"

class IActionStrategy {
public:
	virtual void act(std::shared_ptr<Piece>& perfomer, Board& board) = 0;
	virtual ~IActionStrategy(); 
};

#endif