#include "Card.h"

Card::Card(CardType type, int rareRate) : _type(type), _rareRate(rareRate) {}

CardType Card::getCardType() const {
    return _type;
}
int Card::getRareRate() const {
    return _rareRate;
}