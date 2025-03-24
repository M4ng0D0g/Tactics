#include "Player.h"

Deck::Deck(std::unordered_map<CardType, int> defauleDeck) : _data(defauleDeck) {}

int Deck::getWeight(CardType type) {
	return _data[type];
}

void Deck::setWeight(CardType type, int value) {
	_data[type] = value;
}

CardType Deck::randomCardType() const {
	std::vector<CardType> cardTypes;
	std::vector<int> prefixSum;
	int range = 0;

	for(const auto& [type, weight] : _data) {
		if(weight <= 0) continue;
		range += weight;
		cardTypes.push_back(type);
		prefixSum.push_back(range);
	}
	if(range == 0) return Mouse0;

	int index = rand() % range;
	auto it = std::lower_bound(prefixSum.begin(), prefixSum.end(), index);
	return cardTypes[it - prefixSum.begin()];
}