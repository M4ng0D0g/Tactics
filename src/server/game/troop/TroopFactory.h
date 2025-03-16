#ifndef TROOPFACTORY_H
#define TROOPFACTORY_H

#include "./Troop.h"
#include "./action/interface/ITroopAction.h"
#include "../enums/TroopEnum.h"
#include "../utils/ValueStatus.h"
#include "../GameProcessor.h"

#include "./action/EatCheese.h"

#include <memory>

class TroopFactory {
public:
	std::shared_ptr<Troop> createTroop(TroopType type, TeamType team, GameProcessor& processor){
		std::shared_ptr<Troop> troop;
		std::unique_ptr<ITroopAction> bta, ata, osa, oca, oha, hta, oda;

		switch(type) {
			case Mouse0:
				troop = std::make_shared<Troop>(processor, type, team);
				troop->getHp() = ValueStatus(1, 0, 1);
				troop->getAtk() = ValueStatus(1, 0, 32767);

				bta = std::make_unique<EatCheese>();
				ata = std::make_unique<EatCheese>();
				osa = std::make_unique<EatCheese>();
				oca = std::make_unique<EatCheese>();
				oha = std::make_unique<EatCheese>();
				hta = std::make_unique<EatCheese>();
				oda = std::make_unique<EatCheese>();
				break;
		}

		troop->setBeforeTurn(std::move(bta));
		troop->setAfterTurn(std::move(ata));
		troop->setOnSummon(std::move(osa));
		troop->setOnClick(std::move(oca));
		troop->setOnHit(std::move(oha));
		troop->setOnSummon(std::move(hta));
		troop->setOnClick(std::move(oda));

		return troop;
	}
};

#endif