std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& players

//TeamMode
config.setupTeamType(_teamType);
_turnManager.setPlayer(_players);

//build player
// PlayerBuilder& builder =  PlayerBuilder::getInstance();

// player0 = builder.setPeer(peer0)
// .setTeam(TeamType::Team0)
// .setStamina(setup.StaminaIni, setup.StaminaLim)
// .setHandLimit(setup.HandLim).build();
// players.insert(TeamType::Team0, player0);

// player1 = builder.setPeer(peer1)
// .setTeam(TeamType::Team1)
// .setStamina(setup.StaminaIni, setup.StaminaLim)
// .setHandLimit(setup.HandLim).build();
// players.insert(TeamType::Team1, player1);