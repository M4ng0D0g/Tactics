
#include "GameSettings.h"
#include "TeamEnum.h"
#include "Stamina.h"
#include "Hand.h"
#include "CardPool.h"
#include <vector>

using namespace std;

class Player {
private:
    Team team;
    //Card
    Hand hand;
    CardPool pool;
    //Stamina
    Stamina stamina;

public:
    Player(GameSettings settings) {
        hand = Hand(settings.handLim);
        stamina = Stamina(settings.iniStamina, settings.staminaLim);

    }

    void discard(const int& indexArr) {
        //判斷玩家是否有足夠stamina
        int cost = indexArr.size();
        if(stamina.isEnough(cost)){
            stamina.removeValue(cost);
            //刪除玩家特定手牌
            hand.discard(indexArr);
            //重新抽牌
            hand.draw();
            //更新玩家手牌(需先做顯示)
        }
    }

    //玩家執行棋子
    //玩家下棋
    //玩家出售棋子? (考慮不做)

};