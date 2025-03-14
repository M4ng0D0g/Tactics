#ifndef GAMESETUP_H
#define GAMESETUP_H

// #include "GameProcessor.h"
#include "TurnManager.h"
#include "enums/Team.h"

class GameSetup {
private:
	TeamMode _teamMode;
	
	int _handLim = 7;
	int _staminaIni = 0;
	int _staminaLim = 10;
	int _summonCost = 5;
	int _discardCost = 1;

public:
	GameSetup();

	//Getter
	inline int getHandLim() { return _handLim }
	inline void getStamina(int& staminaIni, int& staminaLim) {
		staminaIni = _staminaIni;
		staminaLim = _staminaLim;
	}
	inline void getCost(int& summonCost, int& discardCost) {
		summonCost = _summonCost;
		discardCost = _discardCost;
	}

	//Setter
	inline void setHand(int handLim) { _handLim = handLim }
	inline void setStamina(int staminaIni, int staminaLim) {
		_staminaIni = staminaIni;
		_staminaLim = staminaLim;
	}
	inline void setCost(int summonCost, int discardCost) {
		_summonCost = summonCost;
		_discardCost = discardCost;
	}

	void setupTeamMode(std::unordered_map<TeamType, int>& teamtype);
};

#endif