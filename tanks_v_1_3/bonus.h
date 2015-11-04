#ifndef BONUS_H
#define BONUS_H

#include "header.h"
#include "QString"

class Bonus
{
    public:
        Bonus(int _x, int _y, BonusType _bo);
        ~Bonus();
        QString IMG() {return pic;}
        int X() {return x;}
        int Y() {return y;}
        BonusType B() {return bo;}
    protected:
        int x;
        int y;
        BonusType bo;
        QString pic;

};

#endif // BONUS_H
