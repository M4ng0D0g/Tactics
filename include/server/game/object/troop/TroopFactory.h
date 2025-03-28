#ifndef TROOPFACTORY_H
#define TROOPFACTORY_H

#include "enum/TroopEnum.h"
#include "enum/TeamEnum.h"
#include "interface/ICommandProcessor.h"
#include "Troop.h"
#include <memory>

// ***************************************************************************/

class TroopFactory {
public:
	std::shared_ptr<Troop> create(TroopEnum::Type, TeamEnum::Type, std::shared_ptr<ICommandProcessor>);
};

#endif // TROOPFACTORY_H
