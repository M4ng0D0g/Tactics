
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "TeamType.h"
#include "Action.h"

#include <unordered_map>

using namespace std;

class ActionProcessor {
private:
	Board& board;
	unordered_map<TeamType, Player>& players;
	PieceFactory& factory = PieceFactory::getInstance(); //[NOTE] 工廠掌握Piece創建

public:
	ActionProcessor(Board& board, unordered_map<TeamType, Player>& players)
	: board(board), players(players) {}

	//[DONE]

	//Board
	void dominateTile(TeamType team, pair<int,int>) {
		if(!board.isInBoard(pos)) return;
		board.getTile(pos).setTeam(team);
	}

	bool summonPiece(PieceType type, TeamType team, pair<int,int> pos) {
		//[TODO] 完善拆封包流程
		if(!board.isInBoard(pos)) return false;
		Piece piece = factory.createPiece(type, team, this); //[REVIEW] this是否過於繁瑣
		board.getTile(pos).setPiece(piece);
	}

	void removePiece(pair<int,int> pos) {
		if(!board.isInBoard(pos)) return;
		board.getTile(pos).removePiece();
	}

	//[TODO]
	

	//Piece
	void pieceAct(IAction& action) {
		action.act()

	}


	//[REVIEW]
	void summonPieceEvent() {
		//判斷玩家是否有足夠stamina
		//判斷該位置是否可以召喚
		//更新數值並刪除特定手牌
		//召喚棋子
	}
	void movePieceEvent() {
		//(玩家已經確認操作)
		//檢查玩家是否有足夠stamina
		//檢查玩家操作是否合理
		//執行特殊動作
	}
	void sellPieceEvent(Tile& tile) {
		//檢查條件是否合理
		//販售並給予對應回饋
		if(tile.getTeam() == activeTeam && tile.hasPiece()) tile.sellPiece();
	}
};