#include "game/core/TurnController.h"

TurnController::TurnController(const GameConfig& config) {
	_teams = TeamEnum::TEAM_MAP.at(config._teamMode);
	for(auto team : _teams) {
		if(team == TeamEnum::Type::Neutral) continue;
		_teamMembers[team] = std::vector<std::shared_ptr<Player>>();
		_teamState[team] = true;
	}
}

std::vector<std::shared_ptr<Player>>::iterator TurnController::findPlayer(TeamEnum::Type team, std::shared_ptr<Player> player) {
	const auto& teamM = _teamMembers.at(team);
	auto it = std::find(teamM.begin(), teamM.end(), player);
	return it;
}

void TurnController::addPlayer(TeamEnum::Type team, const std::shared_ptr<Player> player) {
	if(!_teamMembers.contains(team)) return;
	if(findPlayer(team, player) == _teamMembers[team].end()) _teamMembers[team].push_back(player);
}

void TurnController::removePlayer(TeamEnum::Type team, const std::shared_ptr<Player> player) {
	if(!_teamMembers.contains(team)) return;
	auto it = findPlayer(team, player);
	if(it != _teamMembers[team].end()) _teamMembers[team].erase(it);
}

void TurnController::nextTurn() {
	_activeTeam = _activeTeam % (_teams.size() - 1) + 1;
}

TeamEnum::Type TurnController::getActiveTeam() const {
	return _teams[_activeTeam];
}

std::vector<std::shared_ptr<Player>> TurnController::getTeamMembers(TeamEnum::Type team) {
	return _teamMembers[team];
}

std::vector<TeamEnum::Type> TurnController::getTeams() const {
	return _teams;
}

bool TurnController::isTeamActive(TeamEnum::Type team) const {
	return _activeTeam == team;
}

bool TurnController::isTeamActive(std::shared_ptr<Player> player) const {
	auto team = player->getTeam();
	return isTeamActive(team);
}

void TurnController::teamEliminate(TeamEnum::Type team) {
	if(!_teamMembers.contains(team)) return;
	_teamState[team] = false;
}

bool TurnController::isTeamRemaining(TeamEnum::Type team) const {
	if(!_teamMembers.contains(team)) return false;
	return _teamState.at(team);
}

