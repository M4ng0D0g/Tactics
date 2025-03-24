#ifndef TROOPENUM_H
#define TROOPENUM_H

enum TroopType {
    Mouse0,
    
    Swordsman,
    Archer,
    Spearman,
    Cavalry,
    Shieldbearer,
    Builder
};

enum TroopAction {
    EatCheese,

    Swordsman_AfterTurn,
    Archer_AfterTurn,
    Spearman_AfterTurn,
    Cavalry_AfterTurn,
    Shieldbearer_AfterTurn,

    Builder_OnSummon,
    Builder_OnDying
};

#endif