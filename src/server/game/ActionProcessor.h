
#include "GameSettings.h"
#include "TeamType.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Action.h"

#include <unordered_map>
#include <pair>

class ActionProcessor {
private:
	GameSettings& settings;
	Board& board;
	std::unordered_map<TeamType, Player>& players;
	PieceFactory& factory = PieceFactory::getInstance(); //[NOTE] 工廠掌握Piece創建

public:
	ActionProcessor(Board& board, std::unordered_map<TeamType, Player>& players)
	: board(board), players(players) {}

	//Common [DONE]
	Board& getBoard() { return board; }
	std::unordered_map<TeamType, Player>& getPlayers() { return players; }

	//Board [DONE]
	void dominateTile(TeamType team, std::pair<int,int>) {
		if(!board.isInBoard(pos)) return;
		board.getTile(pos).setTeam(team);
	}

	bool summonPiece(PieceType type, TeamType team, std::pair<int,int> pos) {
		Piece piece = factory.createPiece(type, team, this); //[REVIEW] this是否過於繁瑣
		board.getTile(pos).setPiece(piece);
	}

	void removePiece(std::pair<int,int> pos) {
		if(!board.isInBoard(pos)) return;
		board.getTile(pos).removePiece();
	}

	//Piece [TODO] 步進動作
	void pieceAct(ActionCommand& command) {
		command.execute(this);
		//[TODO] 更新畫面
	}

	//[TODO]
	void summonPieceEvent(const char* data) {
		//[TODO] 完善拆封包流程
		Player player;
		PieceType type;
		std::pair<int,int> pos;
		int summonCost = settings.SummonCost;
		//判斷玩家是否有足夠stamina
		if(!player.getStamina().isEnough(summonCost)) return;
		//判斷該位置是否可以召喚
		if(!board.isInBoard(pos)) return;
		//更新數值並刪除特定手牌
		//召喚棋子
		player.getStamina().addValue(-summonCost);
		summonPiece(type, player.getTeam);
	}

	//Event [REVIEW]
	
	void movePieceEvent() {
		//(玩家已經確認操作)
		//檢查玩家是否有足夠stamina
		//檢查玩家操作是否合理
		//執行特殊動作
	}
	// void sellPieceEvent(Tile& tile) {
	// 	//檢查條件是否合理
	// 	//販售並給予對應回饋
	// 	if(tile.getTeam() == activeTeam && tile.hasPiece()) tile.sellPiece();
	// }
};