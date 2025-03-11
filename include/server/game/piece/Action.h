#pragma once

//=Interface=
class IAction {
public:
    virtual void act() const = 0;
};

//=Class=
class EatCheese : public IAction {
public:
    void act() const override { /*do nothing*/ }
};
