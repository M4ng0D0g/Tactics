#ifndef TROOPENUM_H
#define TROOPENUM_H

// ***************************************************************************/

namespace TroopEnum {
    enum Type {
        Mouse0,
        Swordsman, Archer, Spearman, Cavalry, Shieldbearer, Builder
    };
    enum Action {
        EatCheese,

        BeforeTurn, AfterTurn,

        OnSummon,
        OnDying,
        OnClick,
        OnHit,

        MoveBefore, MoveAfter,
        HitTroopAfter,

        OnFriendSummon,
        OnFriendDying,
        OnFriendClick,
        OnFriendHit,

        FriendMoveBefore, FriendMoveAfter,
        FriendHitTroopAfter,
    };
}

#endif