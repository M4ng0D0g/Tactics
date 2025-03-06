
#include "IStats.h"
#include "Card.h"
#include <vector>

using namespace std;

class Hand : public IStats {
private:
    vector<Card> hand;
public:
    Hand(int upperLim) {
        upperLimit = upperLim;
        lowerLimit = 0;
        hand = vector<Card>(upperLim);
    }

    void setValue(int value) override {}
    void setLowerLimit(int newLowerLimit) override {}

    //drawCard 卡池 數量
    //correct 抽到足夠的牌
    //display策略 byOrder
    //discard 棄牌
};