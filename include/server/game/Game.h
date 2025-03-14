#ifndef GAME_H
#define GAME_H

#include "GameSetup.h"
#include "GameProcessor.h"
#include "TurnManager.h"

#include "enums/Team.h"
#include "player/Player.h"
#include "board/Board.h"

#include <vector>
#include <enet/enet.h>

class Game {
private:
	GameSetup _setup;
	TurnManager _turnManager;
	GameProcessor _processor; //[TODO] 加入需求

	std::unordered_map<TeamType, int> _teamType;

	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>> _players;
	Board _board;

	
public:
	Game(GameSetup setup) : _setup(setup) {
		//TeamMode
		_setup.setupTeamMode(_teamType);
		_turnManager = TurnManager(_teamType);
		_turnManager.setPlayer(_players);



		_processor = GameProcessor(_setup, _board);.
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
	};

	void start();
	void end();
	void end(TeamType vectoryTeam);
};

#endif