
#include "role\User.h"
#include <vector>

using namespace std;

enum ModeType {
    solo, team
};

class GameSettings {
public:
    ModeType modeType = solo;
    int initialHandLimit = 5;
};

class Party {
private:
    const GameSettings settings;
    vector<User> spectetors;


public:
    Party(GameSettings setup) : settings(setup) {

    }

};

