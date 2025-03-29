#ifndef ICOMMANDPROCESSOR_H
#define ICOMMANDPROCESSOR_H

#include "game/object/troop/Troop.h"
#include "game/object/troop/TroopCommand.h"

class ICommandProcessor {
public:
	virtual ~ICommandProcessor() = default;

	virtual void queueCommand(TroopCommand) = 0;
	virtual void processCommand() = 0;
};

#endif