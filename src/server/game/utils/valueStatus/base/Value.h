#ifndef VALUE_H
#define VALUE_H

#include "../interface/IValue.h"

template <typename T>
class Value : public IValue<T> {
protected:
	std::optional<T> _value;
public:
	Value(std::optional<T> value) : _value(value) {}

	std::optional<T> getValue() const override { return _value; }
	void setValue(const std::optional<T> value) override { _value = value; }
};

#endif
