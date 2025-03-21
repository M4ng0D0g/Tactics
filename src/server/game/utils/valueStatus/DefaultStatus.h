#ifndef DEFAULTSTATUS_H
#define DEFAULTSTATUS_H

#include "ValueStatus.h"

template <typename T>
class DefaultStatus : public ValueStatus<T> {
protected:
	T _default;
public:
	DefaultStatus(T value, T defaultValue)
	: ValueStatus<T>(value), _default(defaultValue) {}

	T getDefault() const override { return _default; }
	void setDefault(const T value) override { _default = value; }
	void setToDefault() override { _value = _default; }
};

#endif