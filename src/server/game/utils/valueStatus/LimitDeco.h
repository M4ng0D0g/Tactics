#ifndef LIMITDECO_H
#define LIMITDECO_H

#include "./base/ValueDeco.h"

#include <algorithm>

template <typename T>
class LimitDeco : public ValueDeco<T> {
private:
	std::optional<T> _lowerLimit;
	std::optional<T> _upperLimit;
public:
	LimitDeco(IValue<T>& base, std::optional<T> lower, std::optional<T> upper)
	: ValueDeco<T>(base), _lowerLimit(lower), _upperLimit(upper) {}

	std::optional<T> getLowerLimit() const override { return _lowerLimit; }
	std::optional<T> getUpperLimit() const override { return _upperLimit; }
	void setLowerLimit(const std::optional<T> value) override { _lowerLimit = value; }
	void setUpperLimit(const std::optional<T> value) override { _upperLimit = value; }

	std::optional<bool> isDepleted() const override { return _base.getValue() <= _lowerLimit; }
	std::optional<bool> isFull() const override { return _base.getValue() >= _upperLimit; }
	std::optional<bool> isExceed() const override{ return _base.getValue() > _upperLimit; }
	void clamp() override { _base.setValue(std::clamp(_base.getValue(), _lowerLimit, _upperLimit)); }
};

#endif