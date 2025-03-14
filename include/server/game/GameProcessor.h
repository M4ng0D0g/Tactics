#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#include "GameSetup.h"

#include "enums/Team.h"
#include "board/Board.h"
#include "player/Player.h"
#include "piece/Piece.h"
// #include "Action.h"

#include <unordered_map>
#include <vector>

class GameProcessor {
private:
	GameSetup& _setup;
	Board& _board;
	std::unordered_map<TeamType, std::vector<std::unordered_map<ENetPeer*, Player>>>& _players;
	PieceFactory factory; //[NOTE] 工廠掌握Piece創建

public:
	ActionProcessor(Board& board, std::unordered_map<TeamType, Player>& players);

	//Common [DONE]
	Board& getBoard();
	std::unordered_map<TeamType, Player>& getPlayers();

	//Board [DONE]
	void dominateTile(TeamType team, std::pair<int,int>);
	bool summonPiece(PieceType type, TeamType team, std::pair<int,int> pos);
	void removePiece(std::pair<int,int> pos);

	//Piece [TODO] 步進動作
	void pieceAct(ActionCommand& command);

	//Event [REVIEW]
	void summonPieceEvent(const char* data); //[TODO] 合併?
	void movePieceEvent();
};

#endif