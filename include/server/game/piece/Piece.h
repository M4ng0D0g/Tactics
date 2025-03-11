#pragma once

#include <pair>
#include "TeamType.h"
#include "PieceType.h"
#include "Action.h"
#include "ActionProcessor.h"

using namespace std;

class Piece {
private:
	ActionProcessor& processor;

	PieceType type;
	TeamType team;
	int defaultHP
	int HP;
	int atk;

	//delegation
	IAction* beforeTurnAction;
	IAction* afterTurnAction;
	IAction* onClickAction;
public:
	//constructor
	Piece(PieceType type, TeamType team, int hp, int atk, ActionProcessor& processor)
	: type(type), team(team), defaultHP(hp), atk(atk), processor(processor) {
		HP = defaultHP;
	}
	//destructor
	~IPiece() {
		delete beforeTurnAction;
		delete afterTurnAction;
		delete onClickAction;
	}

	//setter
	void setBeforeTurnAction(IAction* action) { beforeTurnAction = action; }
	void setOnClickAction(IAction* action) { onClickAction = action; }
	void setAfterTurnAction(IAction* action) { afterTurnAction = action; }

	//perform [FIXME] 用命令模式
	void performBeforeTurn() { processor.pieceAction(beforeTurnAction); }
	void performOnClick() { processor.pieceAction(onClickAction); }
	void performAfterTurn() { processor.pieceAction(afterTurnAction); }

};

class PieceFactory {
private:
	PieceFactory() {};
	~PieceFactory() {};
public:
	static PieceFactory& getInstance() {
		static PieceFactory instance;
		return instance;
	}

	PieceFactory(const PieceFactory&) = delete;
	PieceFactory& operator=(const PieceFactory&) = delete;

	Piece createPiece(PieceType type, TeamType team, ActionProcessor& processor){
		switch(type) {
			case PieceType::Mouse0:
				Piece piece(type, team, 1, 1, processor);
				EatCheese bta;
				piece.setBeforeTurnAction(&bta);
				return piece;
		}
	}
};