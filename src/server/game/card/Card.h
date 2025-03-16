#ifndef CARD_H
#define CARD_H

#include "../enums/CardEnum.h"

class Card {
private:
	CardType _type;
	int _rareRate;
public:
	Card(CardType type, int rareRate);

	CardType getCardType();
	int getRareRate() const;
};

#endif