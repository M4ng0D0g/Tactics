#ifndef ICLIENTMEDI_H
#define ICLIENTMEDI_H

#include "game/object/player/Player.h"
#include <string>
#include <memory>

// ***************************************************************************/

class IClientMedi {
public:
	virtual ~IClientMedi() = default;
	
	virtual void lockOperation() = 0;
	virtual void unlockOperation() = 0;
	virtual void clickBoard(std::shared_ptr<Player>, std::pair<int, int>) = 0;
	virtual void clickHand(std::shared_ptr<Player>, int) = 0;
};

#endif