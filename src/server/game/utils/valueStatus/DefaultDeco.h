#ifndef DEFAULTDECO_H
#define DEFAULTDECO_H

#include "./base/ValueDeco.h"

template <typename T>
class DefaultDeco : public ValueDeco<T> {
private:
	std::optional<T> _default;
public:
	DefaultDeco(IValue<T>& base, std::optional<T> value)
	: ValueDeco<T>(base), _default(value) {}

	std::optional<T> getDefault() const override { return _default; }
	void setDefault(const std::optional<T> value) override { _default = value; }
	void setToDefault() override { _base.setValue(_default); }
};

#endif