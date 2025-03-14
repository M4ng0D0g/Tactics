#ifndef TEAMTYPE_H
#define TEAMTYPE_H

#include <unordered_map>

enum TeamMode { TwoTeamMode };
enum TeamType { Neutral, Team1, Team2, Team3, Team4 };

namespace Team {
    inline const std::unordered_map<TeamType, int> TwoTeam = {
        {TeamType::Neutral, 0}, {TeamType::Team1, 1}, {TeamType::Team2, 2}
    };
}

#endif