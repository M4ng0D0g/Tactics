#include "Player.h"

Player::Player(TeamType team) : _team(team) {}

Stamina& Player::getStamina() {
	return _stamina;
}

Hand& Player::getHand() {
	return _hand;
}

Deck& Player::getDeck() {
	return _deck;
}

std::vector<bool>& Player::getClickHandState() {
	return _clickHandState;
}

std::stack<std::pair<int, int>>& Player::getClickBoardState() {
	return _clickBoardState;
}