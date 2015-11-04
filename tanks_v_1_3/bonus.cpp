#include "bonus.h"

Bonus::Bonus(int _x, int _y, BonusType _bo)
{
    x = _x;
    y = _y;
    bo = _bo;
    if (bo == Live)
        pic = "textures/bonus_live.png";
    if (bo == Ammo)
        pic = "textures/bonus_ammo.png";
    if (bo == Repair)
        pic = "textures/bonus_repair.png";
}

Bonus::~Bonus()
{
}
