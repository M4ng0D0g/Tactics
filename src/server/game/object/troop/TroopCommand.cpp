#include "game/object/troop/TroopCommand.h"

TroopCommand::TroopCommand(std::shared_ptr<ITroopAction> action, std::shared_ptr<Troop> performer)
	: _action(action), _performer(performer) {}

void TroopCommand::execute(Board& board) {
	_action->act(_performer, board);
}