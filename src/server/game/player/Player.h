#ifndef PLAYER_H
#define PLAYER_H

#include "Stamina.h"
#include "Hand.h"
#include "../card/Deck.h"
#include "../enums/TeamEnum.h"

class Player {
private:
	TeamType _team;

	Stamina _stamina;
	Hand _hand;
	Deck _deck;

	//clickState
public:
	Player(TeamType team);

	void setTeam(TeamType t);

	Stamina& getStamina();
	Hand& getHand();
	Deck& getDeck();
};

#endif