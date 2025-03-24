#include "Card.h"


std::unique_ptr<Card> CardFactory::createCard(CardType type) {
	switch(type) {
		case Swordsman: return std::make_shared<Card>(Swordsman, 1);
		case Archer: return std::make_shared<Card>(Archer, 1);
		case Spearman: return std::make_shared<Card>(Spearman, 1);
		case Cavalry: return std::make_shared<Card>(Cavalry, 1);
		case Shieldbearer: return std::make_shared<Card>(Shieldbearer, 1);
		case Builder: return std::make_shared<Card>(Builder, 1);

		default: return std::make_shared<Card>(Mouse0, 0);
	}
}

