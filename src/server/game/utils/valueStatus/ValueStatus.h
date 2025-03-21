#ifndef VALUESTATUS_H
#define VALUESTATUS_H

template <typename T>
class ValueStatus {
protected:
	T _value;
public:
	ValueStatus(T value) : _value(value) {}

	T getValue() const { return _value; }
	void setValue(T value) { _value = value; }
};

#endif
