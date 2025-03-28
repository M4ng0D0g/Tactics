#ifndef TURNCONTROLLER_H
#define TURNCONTROLLER_H

#include "../../enums/TeamEnum.h"
#include "../../object/Player.h"

#include <memory>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <optional>

class TurnController {
private:
	std::vector<TeamEnum::Type> _teams;
	std::unordered_map<TeamEnum::Type, std::vector<std::shared_ptr<Player>>> _teamMembers;
	std::unordered_map<TeamEnum::Type, bool> _teamRemain;
	size_t _activeTeam = 0;

public:
	TurnController(TeamEnum::Mode mode) {
		_teams = TeamEnum::TEAM_MAP.at(mode);
		for(auto team : _teams) {
			if(team == TeamEnum::Type::Neutral) continue;
			_teamMembers[team] = std::vector<std::shared_ptr<Player>>();
			_teamRemain[team] = true;
		}
	}

	std::optional<size_t> findPlayer(TeamEnum::Type team, std::shared_ptr<Player>& player) {
		if(!_teamMembers.contains(team)) return std::nullopt;

		const auto& teamM = _teamMembers.at(team);
		auto it = std::find(teamM.begin(), teamM.end(), player);

		if(it == teamM.end()) return std::nullopt;
		else return std::distance(teamM.begin(), it);
	}

	void addPlayer(TeamEnum::Type team, const std::shared_ptr<Player>& player) {
		if(!_teamMembers.contains(team)) return;
		if(findPlayer(team, player) != std::nullopt) return;
		_teamMembers[team].push_back(player);
	}

	void removePlayer(TeamEnum::Type team, const std::shared_ptr<Player>& player) {
		if(!_teamMembers.contains(team)) return;
		auto index = findPlayer(team, player);

		if(index == std::nullopt) return;

		_teamMembers[team].erase(_teamMembers[team].begin() + index.value());
	}

	void nextTurn() {
		_activeTeam = _activeTeam % (_teams.size() - 1) + 1;
	}

	TeamEnum::Type getActiveTeam() const {
		return _teams[_activeTeam];
	}

	std::vector<std::shared_ptr<Player>>& getTeamMembers(TeamEnum::Type team) {
		return _teamMembers[team];
	}

	std::vector<TeamEnum::Type> getTeams() const {
		return _teams;
	}

	bool isTeamActive(TeamEnum::Type team) const {
		return _activeTeam == team;
	}

	bool isTeamActive(const std::shared_ptr<Player>& player) const {
		auto team = player->getTeam();
		return isTeamActive(team);
	}

	bool isTeamActive(size_t index) const {
		return _activeTeam == index;
	}

	void teamEliminate(TeamEnum::Type team) {
		if(!_teamMembers.contains(team)) return;
		_teamRemain[team] = false;
	}

	bool isTeamRemain(TeamEnum::Type team) const {
		if(!_teamMembers.contains(team)) return false;
		return _teamRemain.at(team);
	}

};

#endif