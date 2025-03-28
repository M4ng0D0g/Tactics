#ifndef ITROOPACTION_H
#define ITROOPACTION_H

#include "../Troop.h"
#include "../Board.h"

#include <memory>

// ***************************************************************************/

class ITroopAction {
public:
	virtual void act(std::shared_ptr<Troop> performer, Board& board) = 0;
	virtual ~ITroopAction() = default; 
};

#endif // ITROOPACTION_H