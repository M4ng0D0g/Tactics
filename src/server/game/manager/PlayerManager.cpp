#include "game/manager/PlayerManager.h"

PlayerManager::PlayerManager(const GameConfig& config, GameMediator& mediator) : _mediator(mediator) {

}
// std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& players

//TeamMode
// config.setupTeamType(_teamType);
// _turnManager.setPlayer(_players);

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

Player& PlayerManager::getPlayer(boost::uuids::uuid id) {
	auto it = _players.find(id);
	if(it == _players.end()) throw std::runtime_error("Player not found");
	return it->second;
}

bool PlayerManager::clickBoard(boost::uuids::uuid id, std::pair<int, int> loc) {
	Player& player = getPlayer(id);
	player.getClickBoardState().push(loc);
	if(!_gameMediator->boardCheckLocVaild(loc)) return false;
	//相關功能

	return true;
}

bool PlayerManager::clickHand(boost::uuids::uuid id, int index) {
	Player& player = getPlayer(id);
	if(index <  0 || index >= player.getHand().getSize()) return false;
	player.getClickHandState()[index] = !player.getClickHandState()[index];

	return true;
}

bool PlayerManager::discardCard(boost::uuids::uuid id) {
	Player& player = getPlayer(id);
	player->discard();
	while(!player->getHand().isFull()) {
		player->getHand().addCard(player->getDeck().draw());
	}

	return true;
}

bool PlayerManager::drawCard(Player& player) {
	if(player.getHand().isFull()) return false;

	while(!player->getHand().isFull()) {
		player->getHand().addCard(player->getDeck().randomCardType());
	}

	return true;
}