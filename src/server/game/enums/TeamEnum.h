#ifndef TEAMTYPE_H
#define TEAMTYPE_H

#include <unordered_map>
#include <vector>

enum TeamMode { TeamMode_2 , TeamMode_4 };
enum TeamType { Neutral = 0, Team1, Team2, Team3, Team4 };

const std::unordered_map<TeamMode, std::vector<TeamType>> TEAM_MAP = {
    {
        TeamMode_2, { Neutral, Team1, Team2 }
    },
    // {
    //     TeamMode_4, {Neutral, Team1, Team2, Team3, Team4}
    // },
};

const std::unordered_map<TeamMode, std::vector<TeamType>> ENEMY_MAP = {
    {
        TeamMode_2, { Neutral, Team2, Team1 }
    },
    // {
    //     TeamMode_4, {Neutral, Team1, Team2, Team3, Team4}
    // },
};

#endif