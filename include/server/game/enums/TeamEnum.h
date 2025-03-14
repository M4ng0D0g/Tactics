#ifndef TEAMTYPE_H
#define TEAMTYPE_H

#include <unordered_map>

enum TeamMode { TeamMode_2 , TeamMode_4 };
enum TeamType { Neutral, Team1, Team2, Team3, Team4 };

const std::unordered_map<TeamMode, std::unordered_map<TeamType, int>> TEAM_MAP = {
    {
        TeamMode_2, {
            {Neutral, 0}, {Team1, 1}, {Team2, 2}
        }
    },
    {
        TeamMode_4, {
            {Neutral, 0}, {Team1, 1}, {Team2, 2}, {Team3, 3}, {Team4, 4}
        }
    },
};

#endif