#ifndef TROOPCOMMAND_H
#define TROOPCOMMAND_H

#include "Troop.h"
#include "game/objects/board/Board.h"
#include "interface/ITroopAction.h"
#include <memory>

// ***************************************************************************/

class TroopCommand {
private:
	std::shared_ptr<ITroopAction> _action;
	std::shared_ptr<Troop> _performer;

public:
	TroopCommand(std::shared_ptr<ITroopAction> action, std::shared_ptr<Troop> performer);

	void execute(Board& board);
};

#endif // TROOPCOMMAND_H
