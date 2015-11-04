#include "bullet.h"
#include "QSound"

Bullet::Bullet(int _x, int _y, int _arrow, Side _army)
{
    x = _x;
    y = _y;
    speed = 10;
    arrow = _arrow;
    army = _army;
    img = "textures/bullet.png";
    ID = qrand()%1000 + 1;
    central();
}

Bullet::Bullet(const Bullet &_b)
{
    x = _b.x;
    y = _b.y;
    speed = _b.speed;
    arrow = _b.arrow;
    army = _b.army;
    img = _b.img;
    ID = _b.ID;
    central();
}

Bullet::~Bullet()
{
}

bool Bullet::operator==(const Bullet &_obj)
{
    return (x == _obj.x && y == _obj.y && arrow == _obj.arrow && army == _obj.army && ID == _obj.ID);
}

void Bullet::move()
{
    switch (arrow) // <-- пуля движется так же, как и танк, только быстрее и не меняет своего направления
    {
        case NORTH:
            y -= speed;
        break;
        case EAST:
            x += speed;
        break;
        case SOUTH:
            y += speed;
        break;
        case WEST:
            x -= speed;
        break;
        default:
            x += 0;
            y += 0;
    }
}

void Bullet::central()
{
    switch (arrow)
    {
        case NORTH:
            y -= 11;
        break;
        case EAST:
            x += 11;
        break;
        case SOUTH:
            y += 11;
        break;
        case WEST:
            x -= 11;
        break;
        default:
            x += 0;
            y += 0;
    }
}

bool Bullet::popal(Map *_m, QList<Tank*> _T, QList<Bullet*> _B)
{
        if (_m->posXY(x, y)->type == cWall) //если попали в стену
        {
            //'разрушаем' стену
            _m->posXY(x, y)->type = cWallD;
            _m->posXY(x, y)->pic = "textures/wall_dammaged.png";
            emit popal_stena(_m->posXY(x, y)); //посылаем сигнал 'попали в стену'
            return true;
        }
        if (_m->posXY(x, y)->type == cWallD) //если попали в разрушенную стену
        {
            //'уничтожаем' стену
            _m->posXY(x, y)->type = cSand;
            _m->posXY(x, y)->pic = "textures/sand.png";
            emit popal_stena(_m->posXY(x, y)); //сигнал
            return true;
        }
        foreach (Bullet* _i, _B)
        {
            if (_i != 0)
                if ((x >= _i->X() - 5 && x<= _i->X() + 5) && (y >= _i->Y() - 5 && y <= _i->Y() + 5) && _i->id() != ID)
                    return true;
        }
        foreach (Tank* _i, _T)
        {
            if (_i != 0)
                if ((x >= _i->X() - 10 && x<= _i->X() + 10) && (y >= _i->Y() - 10 && y<= _i->Y() + 10))
                {
                    _i->set_dammage(SHELL_DAMMAGE);
                    QSound::play("sounds/iron7.wav");
                    emit popal_tank(_i);
                    return true;
                }
        }
    return (!_m->is_shot(x, y));
}

BulletTimer::BulletTimer(Bullet *_b, QGraphicsPixmapItem *_p)
{
    b = _b;
    p = _p;
    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(on_takt()));
}

BulletTimer::~BulletTimer()
{
    delete t;
}

void BulletTimer::start()
{
    t->start(50);
}

void BulletTimer::stop()
{
    t->stop();
}
