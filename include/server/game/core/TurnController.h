#ifndef TURNCONTROLLER_H
#define TURNCONTROLLER_H

#include "GameConfig.h"
#include "game/enums/TeamEnum.h"
#include "game/object/player/Player.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <algorithm>

// ***************************************************************************/

class TurnController {
private:
	std::vector<TeamEnum::Type> _teams;
	std::unordered_map<TeamEnum::Type, bool> _teamState;
	std::unordered_map<TeamEnum::Type, std::vector<std::shared_ptr<Player>>> _teamMembers;
	size_t _activeTeam = 0;

public:
	/**
	 * @brief 建立 `隊伍` Vector 和 `隊伍-玩家Vector` Map，不會主動註冊玩家。
	 * 
	 * @param config 遊戲設定選項。
	 */
	TurnController(const GameConfig& config);

	std::vector<std::shared_ptr<Player>>::iterator findPlayer(TeamEnum::Type team, std::shared_ptr<Player> player);
	void addPlayer(TeamEnum::Type team, const std::shared_ptr<Player> player);
	void removePlayer(TeamEnum::Type team, const std::shared_ptr<Player> player);

	void nextTurn();

	TeamEnum::Type getActiveTeam() const;
	std::vector<std::shared_ptr<Player>> getTeamMembers(TeamEnum::Type team);
	std::vector<TeamEnum::Type> getTeams() const;

	bool isTeamActive(TeamEnum::Type team) const;
	bool isTeamActive(std::shared_ptr<Player> player) const;

	void teamEliminate(TeamEnum::Type team);
	bool isTeamRemaining(TeamEnum::Type team) const;
};

#endif