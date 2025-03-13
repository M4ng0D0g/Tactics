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
class ActionCommand {
private:
	std::unique_ptr<IAction>& action; //[NOTE] 只需引用Piece之策略
	std::shared_ptr<Piece> performer; //[NOTE] 需掌控Piece狀態
public:
	ActionCommand(std::unique_ptr<IAction>& action, std::shared_ptr<Piece> performer)
	: action(action), performer(performer) {}

	void execute(ActionProcessor& processor) {
		Board& board = processor.getBoard();
		action->act(*performer, board);
	}
};

//=Class= [DONE]
class EatCheese : public IAction {
public:
	void act(Piece& perfomer, Board& board) const override { /*do nothing*/ }
};
