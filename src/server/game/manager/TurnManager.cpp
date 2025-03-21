#include "TurnManager.h"
#include "game/GameConfig.h"

TurnManager::TurnManager(const GameConfig& config, std::weak_ptr<GameMediator> gameMediator)
: _gameMediator(gameMediator) {
	config.getTeamMode(_TeamMode);
	_teamList = TEAM_MAP[_teamMode];
	_enemyMap = ENEMY_MAP[_teamMode];
}

// troop bta -> player狀態更新 -> 允許玩家操作
void TurnManager::turnStart() {
	TeamType activeTeam = _teamList[_activeTeamIndex];

	_gameMediator->troopBeforeTurn(activeTeam);
	_gameMediator->playerUpdateStatus(activeTeam);
	_gameMediator->clientUnlockAction(activeTeam);
}

//禁止玩家操作 -> troop ata
void TurnManager::turnEnd() {
	TeamType activeTeam = _teamList[_activeTeamIndex];
	TeamType enemyTeam = _enemyList[_activeTeamIndex];

	_gameMediator->clientUnlockAction(activeTeam);
	_gameMediator->troopAfterTurn(activeTeam);
	
	//如果有方輸了就結束
	if(_gameMediator->boardCheckOwingAll(activeTeam)) _gameMediator.gameEndEvent(activeTeam);
	else if(_gameMediator->boardCheckNotEnough(activeTeam))
	else if(_gameMediator->boardCheckFewer(activeTeam)) _gameMediator.gameEndEvent(enemyTeam);
	else {
		//下一位(待優化)
		_activeTeamIndex = ++_activeTeamIndex % (_teamList.size() - 1) + 1;
		turnStart();
	}
}

//Timer
// void Timer();