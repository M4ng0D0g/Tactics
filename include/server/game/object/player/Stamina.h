#ifndef STAMINA_H
#define STAMINA_H

// ***************************************************************************/

class Stamina {
private:
	int _value;
	int _lowerLimit;
	int _upperLimit;
public:
	Stamina(int value, int lowerLimit, int upperLimit);

	int getValue() const;
	int getLowerLimit() const;
	int getUpperLimit() const;

	void addValue(int value);
	void removeValue(int value);

	bool isEnough(int value) const;
};

#endif // STAMINA_H