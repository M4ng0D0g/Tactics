#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include "GameConfig.h"

#include "enums/TeamEnum.h"
#include "board/Board.h"
#include "player/Player.h"
#include "troop/Troop.h"
#include "troop/TroopCommand.h"
#include "troop/TroopFactory.h"

#include <vector>
#include <enet/enet.h>

class GameProcessor {
private:
	Board& _board;
	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
	TroopFactory factory;

public:
	GameProcessor(
		GameConfig config,
		Board& board,
		std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& players
	);

	// Board& getBoard();
	// std::unordered_map<TeamType, Player>& getPlayers();

	void dominateTile(TeamType team, std::pair<int,int>);
	void summonTroop(TroopType type, TeamType team, std::pair<int,int> pos);
	void removeTroop(std::pair<int,int> pos);

	//Troop [TODO] 步進動作
	void troopAct(TroopCommand& command);

	//Event [REVIEW]
	void summonTroopEvent(const char* data); //[TODO] 合併?
	void moveTroopEvent();
};

#endif