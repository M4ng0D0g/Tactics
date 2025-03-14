#ifndef ACTIONCOMMAND_H
#define ACTIONCOMMAND_H

#include "Piece.h"
#include "../GameProcessor.h"

class ActionCommand {
private:
	std::unique_ptr<IActionStrategy>& _action; //[NOTE] 只需引用Piece之策略
	std::shared_ptr<Piece> _performer; //[NOTE] 需掌控Piece狀態
public:
	ActionCommand(std::unique_ptr<IAction>& action, std::shared_ptr<Piece> performer);

	void execute(GameProcessor& processor) {
		Board& board = processor.getBoard();
		_action->act(*_performer, board);
	}
};

#endif