#ifndef ITROOPACTION_H
#define ITROOPACTION_H

#include "game/objects/troop/Troop.h"
#include "game/objects/board/Board.h"

#include <memory>

class Troop;

// ***************************************************************************/

class ITroopAction {
public:
	virtual void act(std::shared_ptr<Troop> performer, Board& board) = 0;
	virtual ~ITroopAction() = default; 
};

#endif // ITROOPACTION_H