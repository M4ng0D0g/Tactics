
#include "Board.h"
#include "Player.h"
#include "TeamType.h"

#include "GameSettings.h"
#include "TurnManager.h"
#include "ActionProcessor.h"

#include <vector>
#include <unordered_map>

using namespace std;

class Game {
private:
	GameSettings settings;

	TurnManager manager;
	Board board;
	unordered_map<TeamType, Player> players;
	ActionProcessor processor(&board, &players); //[NOTE] This is acceptable.

	void buildPlayer(TeamType team) {
		Player player();
		players.insert(team, player);
	}

public:
	Game(const GameSettings& setup, ENetPeer* peer0, ENetPeer* peer1): settings(setup) {
		//teamMode
		//setup
		//build player
		PlayerBuilder& builder =  PlayerBuilder::getInstance();
		player = builder.setPeer(peer0).setStamina(setup.staminaLim).setHandLimit(setup.handLim).build();
		players.insert(TeamType::Team0, player);
		player = builder.setPeer(peer1).setStamina(setup.staminaLim).setHandLimit(setup.handLim).build();
		players.insert(TeamType::Team1, player);
	}
	//[DONE]

	
	//[TODO]
	void 
	//[REVIEW]
	//rootEvent
	void gameStart() {
		//啟動常駐狀態
		//抽先手方

	}
	void gameEnd() {}
};