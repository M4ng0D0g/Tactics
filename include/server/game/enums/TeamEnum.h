#ifndef TEAMENUM_H
#define TEAMENUM_H

#include <unordered_map>
#include <vector>

namespace TeamEnum {
    enum Mode { TeamMode_2 , TeamMode_4 };
    enum Type { Neutral = 0, Team1, Team2, Team3, Team4 };

    const std::unordered_map<Mode, std::vector<Type>> TEAM_MAP = {
        {
            TeamMode_2, { Neutral, Team1, Team2 }
        },
        // {
        //     TeamMode_4, {Neutral, Team1, Team2, Team3, Team4}
        // },
    };
}

#endif