#include "Deck.h"

#include <random>
#include <utility>

Deck::Deck(std::unordered_map<CardType, int> defauleDeck) : _data(defauleDeck) {}

int Deck::getWeight(CardType type) {
	return _data[type];
}
void Deck::setWeight(CardType type, int value) {
	_data[type] = value;
}

std::vector<CardType> randomNCardType(int number) const {
	std::vector<std::pair<CardType, int>> prefix_sum;
	int range = 0;

	for(const auto& [type, weight] : _data) {
		if(weight <= 0) continue;
		range += weight;
		prefix_sum.push_back({type, range});
	}
	if(range == 0) return {};

	std::random_device seed;  
	std::mt19937 rng(seed());
	std::uniform_int_distribution<int> distribution(0, range-1);
	std::vector<CardType> resultSet;
	
	for(int i = 0; i < number; i++) {
		int randomValue = distribution(rng);
		auto it = std::lower_bound(prefix_sum.begin(), prefix_sum.end(), randomValue,
		[](const auto& pair, int value) { return pair.second <= value; });
		resultSet.push_back(it->first);
	}
	
	return resultSet;
}