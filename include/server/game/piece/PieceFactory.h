#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "Piece.h"

class PieceFactory {
public:
	std::shared_ptr<Piece> createPiece(PieceType type, TeamType team, ActionProcessor& processor){
		std::shared_ptr<Piece> piece;
		std::unique_ptr<IAction> bta, ata, osa, oca;
		switch(type) {
			case PieceType::Mouse0:
				piece = std::make_shared<Piece>(type, team, 1, 1, processor);
				bta = std::make_unique<EatCheese>();
				ata = std::make_unique<EatCheese>();
				osa = std::make_unique<EatCheese>();
				oca = std::make_unique<EatCheese>();
				break;
		}
		piece->setBeforeTurnAction(std::move(bta));
		piece->setAfterTurnAction(std::move(ata));
		piece->setOnSummonAction(std::move(osa));
		piece->setOnClickAction(std::move(oca));
		return piece;
	}
};

#endif