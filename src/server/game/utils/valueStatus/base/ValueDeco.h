#ifndef VALUEDECO_H
#define VALUEDECO_H

#include "../interface/IValue.h"

template <typename T>
class ValueDeco : public IValue<T> {
protected:
	IValue<T>& _base;
public:
	ValueDeco(IValue<T>& base) : _base(base) {}

	std::optional<T> getValue() const override { return _base.getValue(); }
	void setValue(const std::optional<T> value) override override { _base.setValue(value); }

	std::optional<T> getDefault() const override { return _base.getDefault(); }
	void setDefault(const std::optional<T> value) override { _base.setDefault(value); }
	void setToDefault() override { _base.setToDefault() }

	std::optional<T> getLowerLimit() const override { return _base.getLowerLimit(); }
	std::optional<T> getUpperLimit() const override { return _base.getUpperLimit(); }
	void setLowerLimit(const std::optional<T> value) override { _base.setLowerLimit(); }
	void setUpperLimit(const std::optional<T> value) override { _base.setUpperLimit(); }
	std::optional<bool> isDepleted() const override { return _base.isDepleted; }
	std::optional<bool> isFull() const override { return _base.isFull(); }
	std::optional<bool> isExceed() const override { return _base.isExceed(); }
	void clamp() override { _base.clamp() }
};

#endif