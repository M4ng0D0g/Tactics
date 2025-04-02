#ifndef HAND_H
#define HAND_H

#include "game/objects/card/Card.h"
#include <vector>
#include <memory>

// ***************************************************************************/

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

#endif // HAND_H