#pragma once

//[DONE]
class Stamina {
private:
	int value;
	int upperLimit;
	int lowerLimit;
public:
	Stamina(int default, int lowerLimit = 0, int upperLimit)
	: value(default), upperLimit(upperLimit), lowerLimit(lowerLimit) {}

	void addValue(int addend) { value += addend };

	void setValue(int newValue) { value = newValue; }
	void setUpperLimit(int newValue) { upperLimit = newValue; }
	void setLowerLimit(int newValue) { lowerLimit = newValue; }

	int getValue() { return value; }
	int getUpperLimit() { return upperLimit; }
	int getLowerLimit() { return lowerLimit; }

	bool match(int target) { return value == target; }
	bool isEnough(int target) { return value >= target; }
	bool isFull() { return value >= upperLimit; }
	bool isExceed() { return value > upperLimit; }
	bool isDepleted() {return value <= lowerLimit; };

	void clamp() {
		value = value > upperLimit ? upperLimit : value;
		value = value < lowerLimit ? lowerLimit : value;
	}
};
