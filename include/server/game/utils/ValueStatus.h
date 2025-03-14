#ifndef VALUESTATUS_H
#define VALUESTATUS_H

#include <math.h>

class ValueStatus {
private:
	int _default; 
	int _value;
	int _upperLimit;
	int _lowerLimit;
public:
	ValueStatus(int value = 1, int lowerLimit = 0, int upperLimit = 1)
	: _default(value), _upperLimit(upperLimit), _lowerLimit(lowerLimit) {
		_value = value;
	}

	void setDefault(int value) { _default = value; }
	void setToDefault() { _value = _default; }
	void setValue(int value) { _value = value; }
	void setUpperLimit(int value) { _upperLimit = value; }
	void setLowerLimit(int value) { _lowerLimit = value; }

	int getDefault() { return _default; }
	int getValue() { return _value; }
	int getUpperLimit() { return _upperLimit; }
	int getLowerLimit() { return _lowerLimit; }

	bool match(int target) { return _value == target; }
	bool isEnough(int target) { return _value >= target; }
	bool isFull() { return _value >= _upperLimit; }
	bool isExceed() { return _value > _upperLimit; }
	bool isDepleted() { return _value <= _lowerLimit; }

	void clamp() { _value = std::max(std::min(_value, _upperLimit), _lowerLimit); }
};

#endif