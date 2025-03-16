#ifndef IVALUE_H
#define IVALUE_H

#include <optional>

template <typename T>
class IValue {
public:
	virtual ~IValue() = default;

	virtual std::optional<T> getValue() const { return std::nullopt; }
	virtual void setValue(const std::optional<T> value) {}

	virtual std::optional<T> getDefault() const { return std::nullopt; }
	virtual void setDefault(const std::optional<T> value) {}
	virtual void setToDefault() {}

	virtual std::optional<T> getLowerLimit() const { return std::nullopt; }
	virtual std::optional<T> getUpperLimit() const { return std::nullopt; }
	virtual void setLowerLimit(const std::optional<T> value) {}
	virtual void setUpperLimit(const std::optional<T> value) {}
	virtual std::optional<bool> isDepleted() const { return std::nullopt; }
	virtual std::optional<bool> isFull() const { return std::nullopt; }
	virtual std::optional<bool> isExceed() const { return std::nullopt; }
	virtual void clamp() {}
	
};

#endif