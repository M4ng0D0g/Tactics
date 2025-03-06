#include "IStats.h"

class Stamina : public IStats {
public:
    Stamina(int val, int upperLim) {
        value = val;
        upperLimit = upperLim;
        lowerLimit = 0;
    }
};