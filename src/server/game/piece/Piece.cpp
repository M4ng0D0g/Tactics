#pragma once

#include "TeamType.h"
#include "PieceType.h"
#include "Action.h"
#include "ActionProcessor.h"

#include <memory>
#include <pair>

class Piece : public std::enable_shared_from_this<Piece> {
private:
	ActionProcessor& processor;
	//Strategy
	std::unique_ptr<IAction> beforeTurnAction;
	std::unique_ptr<IAction> afterTurnAction;
	std::unique_ptr<IAction> onSummonAction;
	std::unique_ptr<IAction> onClickAction;

	PieceType type;
	TeamType team;
	int defaultHP, HP, atk;
public:
	//Constructor / Destructor [DONE]
	Piece(PieceType type, TeamType team, int hp, int atk, ActionProcessor& processor)
	: type(type), team(team), defaultHP(hp), atk(atk), processor(processor) {
		HP = defaultHP;
	}
	~Piece() {}

	//Setter [DONE]
	void setBeforeTurnAction(std::unique_ptr<IAction> action) { beforeTurnAction = std::move(action); }
	void setAfterTurnAction(std::unique_ptr<IAction> action) { afterTurnAction = std::move(action); }
	void setOnSummonAction(std::unique_ptr<IAction> action) { onSummonAction =  std::move(action); }
	void setOnClickAction(std::unique_ptr<IAction> action) { onClickAction = std::move(action); }

	//Perform [DONE]
	void performBeforeTurn() {
		auto command = std::make_shared<ActionCommand>(beforeTurnAction, std::shared_from_this());;
		processor.pieceAct(command);
	}
	void performAfterTurn() {
		auto command = std::make_shared<ActionCommand>(afterTurnAction, std::shared_from_this());;
		processor.pieceAct(command);
	}
	void performOnSummon() {
		auto command = std::make_shared<ActionCommand>(onSummonAction, std::shared_from_this());;
		processor.pieceAct(command);
	}
	void performOnClick() {
		auto command = std::make_shared<ActionCommand>(onClickAction, std::shared_from_this());;
		processor.pieceAct(command);
	}
};

