#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "../object/Board.h"
#include "../object/Troop.h"
#include "../object/Player.h"
#include "../object/Card.h"
#include "enums/TeamEnum.h"

#include <unordered_map>
#include <vector>
#include <memory>

class GameData {
public:
	GameData();
	~GameData();

	//Board
	Board _board;
	TroopFactory _troopFactory;
	std::unordered_map<TeamType, std::vector<std::shared_ptr<Troop>>> _troopMap;
	//Client & Player
	std::unordered_map<boost::uuids::uuid, <std::shared_ptr<Player>> _players;
	// std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
	CardFactory _cardFactory;
	//Turn
	TeamMode _teamMode;
	std::vector<TeamType> _teamList;
	std::vector<TeamType> _enemyList;
	int _activeTeamIndex = 1;
};

#endif