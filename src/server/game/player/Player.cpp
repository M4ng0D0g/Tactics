
#include "Stamina.h"
#include "Hand.h"
#include "CardDeck.h"
#include "TeamType.h"

#include <enet/enet.h>

//[O] 玩家創建
//[!] Stamina 綁定邏輯
//[X] 卡牌系統

class Player {
private:
	ENetPeer* peer;
	TeamType team;

	Stamina stamina;
	Hand hand;
	CardDeck cardDeck;
public:
	Player() {}

	void setPeer(ENetPeer* p) { peer = p; }
	void setTeam(TeamType t) { team = t; }

	Stamina getStamina() { return stamina; }
	Hand getHand() { return hand; }
	CardDeck getCardDeck() { return cardDeck; }
};

class PlayerBuilder {
private:
	PlayerBuilder() {};
	~PlayerBuilder() {};

	Player playerInstance;

public:
	static PlayerBuilder& getInstance() {
		static PlayerBuilder instance;
		return instance;
	}

	PlayerBuilder(const PlayerBuilder&) = delete;
	PlayerBuilder& operator=(const PlayerBuilder&) = delete;

	PlayerBuilder& setPeer(ENetPeer* peer) {
		playerInstance.setPeer(peer);
		return *this;
	}

	PlayerBuilder& setTeam(TeamType team) {
		playerInstance.setTeam(team);
		return *this;
	}

	PlayerBuilder& setStamina(int defaultValue, int upperLimit) {
		Stamina stamina = playerInstance.getStamina();
		stamina.setValue(defaultValue);
		stamina.setUpperLimit(upperLimit)
		return *this;
	}

	PlayerBuilder& setHandLimit(int limit) {
		Hand hand = playerInstance.getHand();
		hand.setCapacity(limit);
		return *this;
	}

	Player build(){
		Player player;
		return player;
	}
};