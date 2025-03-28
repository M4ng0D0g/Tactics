#include "game/object/Troop.h"

class EatCheese : public ITroopAction {
public:
	void act(std::shared_ptr<Troop> performer, Board& board) override {
		/*do nothing*/
	}
};

