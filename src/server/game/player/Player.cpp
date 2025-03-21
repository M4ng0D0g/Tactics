#include "Player.h"

Player::Player(TeamType team) {}

void Player::setTeam(TeamType t) { team = t; }

Stamina& Player::getStamina() { return _stamina; }
Hand& Player::getHand() { return _hand; }
Deck& Player::getDeck() { return _cardDeck; }