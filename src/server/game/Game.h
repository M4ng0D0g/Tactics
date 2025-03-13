
#include "Board.h"
#include "Player.h"
#include "TeamType.h"

#include "GameSettings.h"
#include "TurnManager.h"
#include "ActionProcessor.h"

#include <vector>
#include <unordered_map>

class Game {
private:
	GameSettings settings;

	TurnManager manager;
	Board board;
	std::unordered_map<TeamType, Player> players;
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

		player0 = builder.setPeer(peer0)
		.setTeam(TeamType::Team0)
		.setStamina(setup.StaminaIni, setup.StaminaLim)
		.setHandLimit(setup.HandLim).build();
		players.insert(TeamType::Team0, player0);

		player1 = builder.setPeer(peer1)
		.setTeam(TeamType::Team1)
		.setStamina(setup.StaminaIni, setup.StaminaLim)
		.setHandLimit(setup.HandLim).build();
		players.insert(TeamType::Team1, player1);
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