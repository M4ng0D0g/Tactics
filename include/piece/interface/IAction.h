#pragma once

class BeforeTurnAction {
public:
    virtual void act() const = 0;
};

class InTurnAction {
public:
    virtual void act() const = 0;
};

class AfterTurnAction {
public:
    virtual void act() const = 0;
};

class OnClickAction {
public:
    virtual void act() const = 0;
};

class OnHitAction {
public:
    virtual void act() const = 0;
};

class OnPlaceAction {
public:
    virtual void act() const = 0;
};

class OnMoveAction {
public:
    virtual void act() const = 0;
};