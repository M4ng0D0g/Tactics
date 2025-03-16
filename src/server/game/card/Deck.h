#ifndef DECK_H
#define DECK_H

#include "../enums/CardEnum.h"

#include <unordered_map>
#include <vector>

class Deck {
private:
	std::unordered_map<CardType, int> _data;
public:
	Deck(std::unordered_map<CardType, int> defauleDeck);

	int getWeight(CardType type) const;
	void setWeight(CardType type, int value);

	std::vector<CardType> randomNCardType(int number) const;
};

#endif