#ifndef TROOPCOMMAND
#define TROOPCOMMAND

#include "./Troop.h"
#include "./action/interface/ITroopAction.h"

#include <memory>

class Troop;
class ITroopAction;

class TroopCommand {
private:
	std::unique_ptr<ITroopAction>& _action;
	std::shared_ptr<Troop> _performer;
public:
	TroopCommand(std::unique_ptr<ITroopAction>& action, std::shared_ptr<Troop> performer);

	void execute(Board& board) {
		_action->act(_performer, board);
	}
};

#endif