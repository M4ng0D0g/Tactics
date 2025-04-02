#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include <memory>

// ***************************************************************************/

class CardFactory {
public:
	std::unique_ptr<Card> createCard(CardType type);
};

#endif // CARDFACTORY_H