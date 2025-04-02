#ifndef CARD_H
#define CARD_H

#include "game/enums/CardEnum.h"
#include <memory>

// ***************************************************************************/

class Card {
private:
	CardEnum::Type _type;
	int _rareRate;

public:
	Card(CardEnum::Type type, int rareRate);

	CardEnum::Type getCardType() const;
	int getRareRate() const;
};



#endif