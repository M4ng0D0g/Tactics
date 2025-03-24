#ifndef CARD_H
#define CARD_H

#include "enums/CardEnum.h"

#include <memory>

class Card {
private:
	CardType _type;
	int _rareRate;
public:
	Card(CardType type, int rareRate);

	CardType getCardType() const;
	int getRareRate() const;
};

class CardFactory {
public:
	std::unique_ptr<Card> createCard(CardType type);
};

#endif