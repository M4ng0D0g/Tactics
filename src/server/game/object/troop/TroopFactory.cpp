#include "game/object/Troop.h"
#include "game/enums/TroopEnum.h"
#include "game/enums/TeamEnum.h"

#include "action/EatCheese.h"

#include <memory>


std::shared_ptr<Troop> TroopFactory::create(TroopEnum::Type type, TeamEnum::Type team, std::shared_ptr<ICommandProcessor> processor) {
	switch(type) {
		case TroopEnum::Type::Mouse0:
			troop = std::make_shared<Troop>(type, team, processor);
			troop->setDefaultHp(1);
			troop->setDefaultAtk(1);
			break;
	}

	return troop;
}