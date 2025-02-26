
#include ".\interface\IPiece.h"
#include "PieceEnum.h"

namespace Piece {
    class Dummy0 : public IPiece {
    private:
    public:
        Dummy0() : IPiece(PieceType::Dummy0, 1, 1) {}
    };
}
