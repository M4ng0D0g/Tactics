#pragma once

#include "Piece.h"
#include "Board.h"
#include "ActionProcessor.h"

#include <memory>

//=Interface= [DONE]
class IAction {
public:
	virtual void act(Piece& perfomer, Board& board) const = 0;
	virtual ~IAction() = default; 
};

//=Class= [DONE]


//=Class= [DONE]
class EatCheese : public IAction {
public:
	void act(Piece& perfomer, Board& board) const override { /*do nothing*/ }
};
