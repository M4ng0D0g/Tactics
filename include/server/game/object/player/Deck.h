#ifndef DECK_H
#define DECK_H

#include "enums/CardEnum.h"
#include <unordered_map>

// ***************************************************************************/

class Deck {
private:
	std::unordered_map<CardEnum::Type, int> _data;
public:
	Deck(std::unordered_map<CardEnum::Type, int> defauleDeck);

	int getWeight(CardEnum::Type type);
	void setWeight(CardEnum::Type type, int value);

	CardEnum::Type randomCardType() const;
};

#endif // DECK_H