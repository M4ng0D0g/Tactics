#include "GameMediator.h"

GameMediator::GameMediator(std::weak_ptr<Game> game)
	: _game(game) {}

void GameMediator::setupManager(
	std::weak_ptr<BoardManager> boardManager,
	std::weak_ptr<ClientManager> clientManager,
	std::weak_ptr<PlayerManager> playerManager,
	std::weak_ptr<TurnManager> turnManager) {
	_boardManager = boardManager;
	_clientManager = clientManager;
	_playerManager = playerManager;
	_turnManager = turnManager;
}

// BoardOps implementations
bool GameMediator::BoardOps::isOccupyingAll(TeamType team) {
	// Implement the logic to check if the team is occupying all
	return false; // Placeholder
}

bool GameMediator::BoardOps::isOccupyingEnough(TeamType team) {
	// Implement the logic to check if the team is occupying enough
	return false; // Placeholder
}

bool GameMediator::BoardOps::isOccupyingFewer(TeamType team) {
	// Implement the logic to check if the team is occupying fewer
	return false; // Placeholder
}

// TroopOps implementations
void GameMediator::TroopOps::performBeforeTurn(TeamType team) {
	// Implement the logic to perform actions before the turn
}

void GameMediator::TroopOps::performAfterTurn(TeamType team) {
	// Implement the logic to perform actions after the turn
}

// PlayerOps implementations
void GameMediator::PlayerOps::updateStatus(TeamType team) {
	// Implement the logic to update player status
}

// ClientOps implementations
void GameMediator::ClientOps::lockOperation() {
	// Implement the logic to lock client operations
}

void GameMediator::ClientOps::unlockOperation() {
	// Implement the logic to unlock client operations
}

void clickBoard(const boost::uuids::uuid id, std::pair<int, int> loc) {
	_playerManager->clickBoard(id, loc);
}

void clickHand(const boost::uuids::uuid id, int index) {
	_playerManager->clickHand(id, index);

}
