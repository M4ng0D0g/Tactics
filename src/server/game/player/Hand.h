#ifndef HAND_H
#define HAND_H

#include "../card/Card.h"

#include <vector>
#include <memory>

class Hand {
private:
	std::vector<std::shared_ptr<Card>> _data;
	int _capacity;
public:
	Hand();

	void getCapacity() const;
	void setCapacity(int value) const;


};

#endif