#include "GameSetup.h"
#include "Team.h"

GameSetup::GameSetup(TeamMode teamMode);

void GameSetup::setupTeamMode(std::map<TeamType, int>& teamtype){
    switch(_teamMode){
        case TwoTeam:
            teamtype = Team::TwoTeam;
            break;
    }
}