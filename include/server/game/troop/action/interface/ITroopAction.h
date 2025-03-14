#ifndef ITROOPACTION_H
#define ITROOPACTION_H

#include "../../Troop.h"
#include "../../../board/Board.h"

#include <memory>

class Troop;
class Board;

class ITroopAction {
public:
	virtual void act(std::shared_ptr<Troop>& performer, Board& board) = 0;
	virtual ~ITroopAction() = default; 
};

#endif