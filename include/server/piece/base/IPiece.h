#pragma once

#include <vector>
#include "raylib.h"
#include "TeamEnum.h"
#include "PieceEnum.h"
#include "IAction.h"

using namespace std;

class IPiece {
private:
    PieceType type;
    Team team;
    int defaultHP, HP;
    int atk;
    int loc[2];
    //delegation
    BeforeTurnAction* beforeTurnAction;
    InTurnAction* inTurnAction;
    AfterTurnAction* afterTurnAction;

public:
    //constructor
    IPiece(PieceType type, int hp, int atk) : type(type), defaultHP(hp), atk(atk){
        HP = defaultHP;
    }
    //destructor
    ~IPiece() {
        delete beforeTurnAction;
        delete inTurnAction;
        delete afterTurnAction;
    }
    //properties
    void setTeam(Team team){
        this->team = team;
    }
    Team getTeam(){
        return team;
    }

    void setLoc(int loc[2]){
        this->loc[0] = loc[0];
        this->loc[1] = loc[1];
    }
    void getLoc(int& x, int& y){
        x = loc[0];
        y = loc[y];
    }

    //setter
    void setBeforeTurnAction(BeforeTurnAction* action){
        beforeTurnAction = action;
    }

    void setInTurnAction(InTurnAction* action){
        inTurnAction = action;
    }

    void setAfterTurnAction(AfterTurnAction* action){
        afterTurnAction = action;
    }
    //perform
    void performBeforeTurn(){
        if(beforeTurnAction) beforeTurnAction->act();
    }

    void performInTurn(){
        if(inTurnAction) inTurnAction->act();
    }

    void performAfterTurn(){
        if(afterTurnAction) afterTurnAction->act();
    }


};