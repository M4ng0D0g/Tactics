#include "Player.h"

Hand::Hand(int capacity) : _capacity(capacity) {}

void Hand::getSize() const {
	return _data.size();
}

void Hand::getCapacity() const {
	return _capacity;
}

void Hand::setCapacity(int value) {
	_capacity = value;
}

void Hand::addCard(std::shared_ptr<Card> card) {
	if(_data.size() < _capacity) _data.push_back(card);
}

void Hand::clamp() {
	while(_data.size() > _capacity) _data.pop_back();
}

void Hand::clampRandom() {
	while(_data.size() > _capacity) {
		int index = rand() % _data.size();
		_data.erase(_data.begin() + index);
	}
}

// bool match(int target) { return value == target; }
// bool isEnough(int target) { return value >= target; }
// bool isFull() { return value >= upperLimit; }
// bool isExceed() { return value > upperLimit; }
// bool isDepleted() {return value <= lowerLimit; };

