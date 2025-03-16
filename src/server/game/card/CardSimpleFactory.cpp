#include "CardSimpleFactory.h"

static std::unique_ptr<Card> CardSimpleFactory::createCard(CardType type) {
	switch(type) {
		case Swordsman: return std::make_unique<Card>(Swordsman, 1);
		case Archer: return std::make_unique<Card>(Archer, 1);
		case Spearman: return std::make_unique<Card>(Spearman, 1);
		case Cavalry: return std::make_unique<Card>(Cavalry, 1);
		case Shieldbearer: return std::make_unique<Card>(Shieldbearer, 1);
		case Builder: return std::make_unique<Card>(Builder, 1);

		default: return std::make_unique<Card>(Mouse0, 0);
	}
}