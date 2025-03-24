#ifndef PLAYER_H
#define PLAYER_H

#include "enums/TeamEnum.h"
#include "enums/CardEnum.h"
#include "Card.h"

#include <vector>
#include <stack>
#include <unordered_map>
#include <memory>
#include <cstdlib>

class Player {
private:
	TeamType _team;

	Stamina _stamina;
	Hand _hand;
	Deck _deck;

	std::vector<bool> _clickHandState;
	std::stack<std::pair<int, int>> _clickBoardState;

public:
	Player(TeamType team);

	Stamina& getStamina();
	Hand& getHand();
	Deck& getDeck();
	std::vector<bool>& getClickHandState();
	std::stack<std::pair<int, int>>& getClickBoardState();
};

class Stamina {
private:
	int _value;
	int _lowerLimit;
	int _upperLimit;
public:
	Stamina(int value, int lowerLimit, int upperLimit);

	int getValue() const;
	int getLowerLimit() const;
	int getUpperLimit() const;

	void addValue(int value);
	void removeValue(int value);

	bool isEnough(int value) const;
};

class Hand {
private:
	std::vector<std::shared_ptr<Card>> _data;
	int _capacity;
public:
	Hand(int capacity);

	void getSize() const;
	void getCapacity() const;
	void setCapacity(int value);

	void addCard(std::shared_ptr<Card> card);

	void clamp();
	void clampRandom();

};

class Deck {
private:
	std::unordered_map<CardType, int> _data;
public:
	Deck(std::unordered_map<CardType, int> defauleDeck);

	int getWeight(CardType type);
	void setWeight(CardType type, int value);

	CardType randomCardType() const;
};

#endif