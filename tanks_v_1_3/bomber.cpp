#include "bomber.h"
#include "QSound"

Bomber::Bomber(int _x, int _y, Side _army, int _btar)
{
    x = _x;
    y = _y;
    btar = _btar;
    empty = false;
    speed = 5;
    army = _army;
    pic = (_army == Sovok)? "textures/plane_sov.png" : "textures/plane_ger.png";
    s = (_army == Sovok)? "sounds/pilot_RU.wav" : "sounds/pilot_DE.wav";
    QSound::play(s);
}

Bomber::~Bomber()
{
}

void Bomber::fire()
{
    if (empty)
        return;
    QSound::play("sounds/bomb_exp.wav");
    rad[0].x = x;
    rad[0].y = y;
    rad[1].x = x - 20;
    rad[1].y = y - 20;
    rad[2].x = x;
    rad[2].y = y - 20;
    rad[3].x = x + 20;
    rad[3].y = y - 20;
    rad[4].x = x + 20;
    rad[4].y = y;
    rad[5].x = x + 20;
    rad[5].y = y + 20;
    rad[6].x = x;
    rad[6].y = y + 20;
    rad[7].x = x - 20;
    rad[7].y = y + 20;
    rad[8].x = x - 20;
    rad[8].y = y;
    for (int _i = 0; _i < 9; _i++)
    {
        Bomb *_bom = new Bomb(rad[_i].x, rad[_i].y);
        emit bomba(_bom);
    }
    empty = true;
}

void Bomber::control()
{
    domove();
    if (y > btar - 5 && y < btar + 5)
        fire();
}

Bomb::Bomb(int _x, int _y)
{
    x = _x;
    y = _y;
    img = "textures/exp.png";
}

Bomb::~Bomb()
{
}

void Bomb::popal(Map *_m, QList<Tank *> _T)
{
    if (_m->posXY(x, y)->type == cWall || _m->posXY(x, y)->type == cWallD) //если попали в стену
    {
        //'разрушаем' стену
        _m->posXY(x, y)->type = cSand;
        _m->posXY(x, y)->pic = "textures/sand.png";
        emit popal_stena(_m->posXY(x, y)); //посылаем сигнал 'попали в стену'
    }
    foreach (Tank* _i, _T)
    {
        if (_i != 0)
            if ((x >= _i->X() - 10 && x<= _i->X() + 10) && (y >= _i->Y() - 10 && y<= _i->Y() + 10))
            {
                _i->set_dammage(BOMB_DAMMAGE);
                //QSound::play("sounds/iron7.wav");
                 emit popal_tank(_i);
            }
    }
}
