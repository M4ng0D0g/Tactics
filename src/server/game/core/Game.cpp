#include "game/core/Game.h"
#include "connection/PacketHandler.h"

Game::Game(const GameConfig& config) {
	_mediator = GameMediator(config, *this);
	_turnController = TurnController(config);
}

void Game::gameStart() {
	if(_gameStart) return;
	_gameStart = true;

	//?
	_mediator->registerClientManager();
	_turnManager->turnStart();
}

void Game::turnStart() {
	// troop bta -> player狀態更新 -> 允許玩家操作
	do {
		_turnController.nextTurn();
	}
	while(!_turnController.isTeamRemain(_turnController.getActiveTeam()));
	
	TeamEnum::Type activeTeam = _turnController.getActiveTeam();

	_gameMediator->troopBeforeTurn(activeTeam);
	_gameMediator->playerUpdate(activeTeam);
	_gameMediator->playerUnlock(activeTeam);
}

void Game::turnEnd() {
	//禁止玩家操作 -> troop ata
	TeamEnum::Type activeTeam = _turnController.getActiveTeam();
	TeamEnum::Type enemyTeam = _enemyList[_activeTeamIndex];

	_gameMediator->playerLock(activeTeam);
	_gameMediator->troopAfterTurn(activeTeam);
	
	TeamEnum::Type remainTeam;
	int remainCount = 0;
	for(auto team : _turnController.getTeams()) {
		if(_turnController.isTeamRemain(team)) {
			remainTeam = team;
			remainCount++;
		}
	}
	if(remainCount == 1) _gameMediator->gameEnd(remainTeam);
	else if(remainCount == 0) _gameMediator->gameEnd(TeamEnum::Type::Neutral);
	else turnStart();
}

void Game::teamEliminate(TeamType eliminatedTeam) {
	_turnController.teamEliminate(eliminatedTeam);
}

void Game::teamWin(TeamEnum::Type victoryTeam) {
	if(victoryTeam == TeamEnum::Type::Neutral) return; // tie

	gameEnd();
}

void Game::gameEnd() {
	if(!_gameStart) return;
	_gameStart = false;

	//?
	_mediator->unregisterClientManager();
}

void Game::gameLoop() {

}

// ***************************************************************************/