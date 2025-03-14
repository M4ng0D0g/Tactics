#ifndef PIECE_H
#define PIECE_H

#include "../enums/Team.h"
#include "../enums/PieceType.h"
#include "interface/IActionStrategy.h"
#include "../GameProcessor.h"

#include <utility>
#include <memory>

class Piece {
private:
	GameProcessor& _processor;
	PieceType _type;
	TeamType _team;
	std::pair<int, int> _loc;
	
	std::unique_ptr<IActionStrategy> _beforeTurn;
	std::unique_ptr<IActionStrategy> _afterTurn;
	std::unique_ptr<IActionStrategy> _onSummon;
	std::unique_ptr<IActionStrategy> _onClick;
	std::unique_ptr<IActionStrategy> _onHit;
	std::unique_ptr<IActionStrategy> _hitPiece;
	std::unique_ptr<IActionStrategy> _onDying;
public:
	Piece();

	//Getter
	std::shared_ptr<Piece> getShared();
	std::pair<int, int> getLocation();

	//Setter
	void setLocation(std::pair<int, int> loc);

	//Perform
	void performBeforeTurn();
	void performAfterTurn();
	void performOnSummon();
	void performOnClick();
	void performOnhit();
	void performHitPiece();
	void performOnDying();
};
#endif