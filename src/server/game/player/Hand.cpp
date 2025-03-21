#pragma once


using namespace std;

//[REVIEW]
class Hand {
private:
	vector<Card> data;
	int capacity;

public:
	Hand(int capacity) : capacity(capacity) {}

	bool addCard(Card card) {
		if(data.size() < capacity) {
			data.push_back(card);
			return true;
		}
		return false;
	};

	// void setValue(int newValue) { value = newValue; }
	void setCapacity(int limit) { capacity = limit; }

	// int getValue() { return value; }
	// int getUpperLimit() { return upperLimit; }
	// int getLowerLimit() { return lowerLimit; }

	// bool match(int target) { return value == target; }
	// bool isEnough(int target) { return value >= target; }
	// bool isFull() { return value >= upperLimit; }
	// bool isExceed() { return value > upperLimit; }
	// bool isDepleted() {return value <= lowerLimit; };

	// void clamp() {
	// 	value = value > upperLimit ? upperLimit : value;
	// 	value = value < lowerLimit ? lowerLimit : value;
	// }
};
