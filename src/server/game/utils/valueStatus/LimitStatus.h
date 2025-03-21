#ifndef LIMITSTATUS_H
#define LIMITSTATUS_H

#include "ValueStatus.h"

#include <algorithm>

template <typename T>
class LimitStatus : public ValueStatus<T> {
protected:
	T _lowerLimit;
	T _upperLimit;
public:
	LimitStatus(T value, T lower, T upper)
	: ValueStatus<T>(value), _lowerLimit(lower), _upperLimit(upper) {}

	T getLowerLimit() const { return _lowerLimit; }
	T getUpperLimit() const { return _upperLimit; }
	void setLowerLimit(T value) { _lowerLimit = value; }
	void setUpperLimit(T value) { _upperLimit = value; }

	bool isDepleted() const { return _value <= _lowerLimit; }
	bool isFull() const { return _value >= _upperLimit; }
	bool isExceed() const { return _value > _upperLimit; }
	void clamp() { _value = std::clamp(_value, _lowerLimit, _upperLimit); }
};

#endif