
#include "Timer.h"


class TurnManager {
private:
	//[REVIEW]
	Team activeTeam;
	unordered_map<Team, Team> enemy = {
		{Team0, Team1},
		{Team1, Team0}
	}; //待優化(放在settings注入)
public:

	void turnStart() {
		//玩家補stamina
		pieceAction(activeTeam); //棋子先行動
		//玩家可以操作
	}
	void turnEnd() {
		//結算操作更新
		//渲染雙方畫面
		//如果有方輸了就結束
		//下一位(待優化)
		activeTeam = enemy[activeTeam];
		turnStart();
	}

};