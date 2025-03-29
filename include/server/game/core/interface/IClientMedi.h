#ifndef ICLIENTMEDI_H
#define ICLIENTMEDI_H

#include "game/object/player/Player.h"
#include <string>
#include <memory>

// ***************************************************************************/

class IClientMedi {
public:
	virtual ~IClientMedi() = default;

	virtual const std::string getID(std::shared_ptr<Player>) = 0;
	
	virtual void lockOperation() = 0;
	virtual void unlockOperation() = 0;
	virtual void clickBoard(const std::string, std::pair<int, int>) = 0;
	virtual void clickHand(const std::string, int) = 0;
};

#endif