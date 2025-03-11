
#include <Stamina.h>
#include <Hand.h>
#include <CardDeck.h>

#include <enet/enet.h>

//[O] 玩家創建
//[!] Stamina 綁定邏輯
//[X] 卡牌系統

class Player {
private:
	ENetPeer* peer;

	Stamina stamina;
	Hand hand;
	CardDeck cardDeck;
public:
	Player() {}

	void setPeer(ENetPeer* p) { peer = p; }

	void getStamina() { return stamina; }
	void getHand() { return hand; }
	void getCardDeck() { return cardDeck; }
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