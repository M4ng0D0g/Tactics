#ifndef GAMECONFIG_H
#define GAMECONFIG_H

// #include "GameProcessor.h"
#include "enums/TeamEnum.h"

#include <vector>
#include <enet/enet.h>

class GameConfig {
private:
	TeamMode _teamMode;
	std::unordered_map<TeamType, int> _teamType;
	std::unordered_map<TeamType, std::vector<ENetPeer*>> _peers;
	
	int _handLim = 7;
	int _staminaIni = 0;
	int _staminaLim = 10;
	int _summonCost = 5;
	int _discardCost = 1;

public:
	GameConfig();

	//Getter
	TeamMode getTeamMode();
	int getHandLim();
	void getStamina(int& staminaIni, int& staminaLim);
	inline void getCost(int& summonCost, int& discardCost);

	//Setter
	void setTeamMode(TeamMode teamMode);
	void setHand(int handLim);
	void setStamina(int staminaIni, int staminaLim);
	void setCost(int summonCost, int discardCost);

	void addPeer(TeamType teamType, ENetPeer* peer);
	void removePeer(ENetPeer* peer);

	void setupTeamType(std::unordered_map<TeamType, int>& teamtype);
	void setupPlayers(std::unordered_map<TeamType, std::vector<ENetPeer*>>& _players);
};

#endif