#ifndef CARDSIMPLEFACTORY_H
#define CARDSIMPLEFACTORY_H

#include "../enums/CardEnum.h"
#include "Card.h"

#include <memory>

class CardSimpleFactory {
public:
	static std::unique_ptr<Card> createCard(CardType type);
};

#endif