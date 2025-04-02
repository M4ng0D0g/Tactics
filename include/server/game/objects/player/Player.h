#ifndef PLAYER_H
#define PLAYER_H

#include "game/enums/TeamEnum.h"
#include "Deck.h"
#include "Hand.h"
#include "Stamina.h"
#include <vector>
#include <unordered_map>
#include <memory>

// ***************************************************************************/

class Player {
private:
	TeamEnum::Type _team;

	Stamina _stamina;
	Hand _hand;
	Deck _deck;

	std::vector<bool> _clickHandState;
	std::vector<std::pair<int, int>> _clickBoardState;

public:
	Player(TeamEnum::Type team);

	Stamina& getStamina();
	Hand& getHand();
	Deck& getDeck();
	std::vector<bool>& getClickHandState();
	std::vector<std::pair<int, int>>& getClickBoardState();
};

#endif // PLAYER_H