#include "GameConfig.h"

GameConfig::GameConfig() {};

//Getter
TeamMode GameConfig::getTeamMode() { //[O]
    return _teamMode;
}

int GameConfig::getHandLim() { //[O]
    return _handLim;
}

void GameConfig::getStamina(int& staminaIni, int& staminaLim) { //[O]
    staminaIni = _staminaIni;
    staminaLim = _staminaLim;
}

void GameConfig::getCost(int& summonCost, int& discardCost) { //[O]
    summonCost = _summonCost;
    discardCost = _discardCost;
}

//Setter
void GameConfig::setTeamMode(TeamMode teamMode) { //[X]
    _teamMode = teamMode;
}

void GameConfig::setHand(int handLim) { //[O]
    _handLim = handLim;
}

void GameConfig::setStamina(int staminaIni, int staminaLim) { //[O]
    _staminaIni = staminaIni;
    _staminaLim = staminaLim;
}

void GameConfig::setCost(int summonCost, int discardCost) { //[O]
    _summonCost = summonCost;
    _discardCost = discardCost;
}


void GameConfig::addPeer(TeamType teamType, ENetPeer* peer) { //[X]

}

void GameConfig::removePeer(ENetPeer* peer) { //[X]

}

void GameConfig::setupTeamType(std::unordered_map<TeamType, int>& teamtype) { //[X]

}

void GameConfig::setupPlayers(std::unordered_map<TeamType, std::vector<ENetPeer*>>& _players) { //[X]

}