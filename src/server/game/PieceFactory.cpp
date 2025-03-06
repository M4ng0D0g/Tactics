#pragma once

#include "TeamEnum.h"
#include "PieceEnum.h"
#include "piece/Piece.h"
#include "piece/BeforeTurnAction.h"

class PieceFactory {
public:
    static IPiece createPiece(Team team, PieceType type){
        switch(type) {
            case PieceType::Dummy0:
                Piece::Dummy0 piece;
                Action::eatCheese bta;
                piece.setBeforeTurnAction(&bta);
                return piece;
        }
    }
};