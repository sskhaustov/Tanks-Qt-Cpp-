#include "tank.h"
#include "QSound"
#include "QKeyEvent"

Tank::Tank()
{
    speed = 0;
    pos_x = 0;
    pos_y = 0;
    arrow = 0;
    armour = 0;
    ammo = 0;
    reload = 8;
    lives = 0;
    army = None;
    img = "";
}

Tank::Tank(const Tank &_tank)
{
    pos_x = _tank.pos_x;
    pos_y = _tank.pos_y;
    arrow = _tank.arrow;
    armour = _tank.armour;
    ammo = _tank.ammo;
    order = _tank.order;
    lives = _tank.lives;
    army = _tank.army;
    img = _tank.img;
    s1 = _tank.s1;
}

Tank::~Tank()
{
}

bool Tank::operator==(const Tank &obj)
{
    return (pos_x == obj.pos_x && pos_y == obj.pos_y && arrow == obj.arrow && armour == obj.armour && order == obj.order);
}

int Tank::nearestX()
{
    switch (arrow)
    {
        case EAST:
            return pos_x + 10;
        break;
        case WEST:
            return pos_x - 10;
        break;
        default:
            return pos_x;
    }
}

int Tank::nearestY()
{
    switch (arrow)
    {
        case NORTH:
            return pos_y - 10;
        break;
        case SOUTH:
            return pos_y + 10;
        break;
        default:
            return pos_y;
    }
}

void Tank::move()
{
    switch (arrow) // <-- в зависимости от направления движения танка определяем, какую координату изменять
    {
        case NORTH:
            pos_y -= speed;
        break;
        case EAST:
            pos_x += speed;
        break;
        case SOUTH:
            pos_y += speed;
        break;
        case WEST:
            pos_x -= speed;
        break;
        default:
            pos_x += 0;
            pos_y += 0;
    }
}

void Tank::fire()
{
    if (ammo == 0)
        return;
    ammo--;
    Bullet *b = new Bullet(pos_x, pos_y, arrow, army);
    QSound::play(s1);
    emit shot(b); //посылаем сигнал о том, что танк выстрелил
}

void Tank::found_bonus(Bonus *_b)
{
    if (_b == NULL)
        return;
    if (pos_x >= _b->X() - 10 && pos_x <= _b->X() + 10 && pos_y >= _b->Y() - 10 && pos_y <= _b->Y() + 10)
    {
        if (_b->B() == Live)
            lives++;
        if (_b->B() == Repair)
            armour = 100;
        if (_b->B() == Ammo)
            ammo = 100;
        emit found(_b);
        QSound::play("sounds/bonus.wav");
    }
}

void Tank::set_dammage(int _dammage)
{
    armour -= _dammage;
    if (is_kill())
        emit kill(this);
}

void Tank::set_speed(CellType _cell)
{
    switch (_cell) // <--- можно проехать только по 3-м поверхностям, поэтому задаем скорость в зависимости от их типов
        //скорость постоянна для простоты
    {
        case cGrass:
            speed = 4;
        break;
        case cAsph:
            speed = 6;
        break;
        case cSand:
            speed = 2;
        break;
        default:
            speed = 0;
    }
}

bool Tank::boundary(int _x, int _y)
{
    if (this != 0)
        return ((_x >= pos_x - 10 && _x <= pos_x + 10) && (_y >= pos_y - 10 && _y <= pos_y + 10));
}

bool Tank::pluh(Map *_m)
{
    if (_m->is_wc(pos_x, pos_y))
    {
        QSound::play("sounds/splash.wav");
        set_dammage(2000);
        return true;
    }
    return false;
}

bool Tank::can_move(Map *_m, QList<Tank*> _T)
{
    //можно ехать, если перед танком нет другого танка, или клетки, через которую нельзя проехать
    /*for (int _i = 0; _i < _T->count(); _i++)*/
    foreach (Tank* _i, _T)
    {
        if (_i->boundary(nearestX(), nearestY()) && _i->get_order() != order)
            return false;
    }
    return (_m->is_road(nearestX(),nearestY()));
}

PlayerTank::PlayerTank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army): Tank()
{
    pos_x = _pos_x;
    pos_y = _pos_y;
    arrow = _arrow;
    armour = _armour;
    ammo = _ammo;
    lives = _lives;
    order = _order;
    army = _army;
    img = (_army == Sovok) ? "textures/tank_sov.png" : "textures/tank_ger.png";
    s1 = (_army == Sovok) ? "sounds/gun2.wav" : "sounds/gun1.wav";
}

PlayerTank::PlayerTank(const PlayerTank& _tank)
{
    pos_x = _tank.pos_x;
    pos_y = _tank.pos_y;
    arrow = _tank.arrow;
    armour = _tank.armour;
    ammo = _tank.ammo;
    order = _tank.order;
    lives = _tank.lives;
    army = _tank.army;
    img = _tank.img;
    s1 = _tank.s1;
}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b)
{
    set_speed(_m->posXY(pos_x, pos_y)->type); //задаем скорость, в зависимости от поверхности
    switch (e->key()) //определяем, какая клавиша нажата
    {
        case Qt::Key_D:
            if (arrow != EAST)
                arrow = EAST; //задаем азимут 90 (вправо)
            if (!pluh(_m) && can_move(_m, _T)) //проверяем, можно ли проехать
            {
                move(); //едем
                found_bonus(_b);
            }
        break;
        //далее все то же самое, только для другого азимута
        case Qt::Key_A:
            if (arrow != WEST)
                arrow = WEST;
            if (!pluh(_m) && can_move(_m, _T))
            {
                move();
                found_bonus(_b);
            }
        break;
        case Qt::Key_W:
            if (arrow != NORTH)
                arrow = NORTH;
            if (!pluh(_m) && can_move(_m, _T))
            {
                move();
                found_bonus(_b);
            }
        break;
        case Qt::Key_S:
            if (arrow != SOUTH)
                arrow = SOUTH;
            if (!pluh(_m) && can_move(_m, _T))
            {
                move();
                found_bonus(_b);
            }
        break;
        case Qt::Key_X: //стрельба
            fire();
        break;
    }
}

AITank::AITank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army): Tank()
{
    pos_x = _pos_x;
    pos_y = _pos_y;
    arrow = _arrow;
    armour = _armour;
    ammo = _ammo;
    order = _order;
    lives = _lives;
    army = _army;
    img = (_army == Sovok) ? "textures/tank_sov.png" : "textures/tank_ger.png";
    s1 = (_army == Sovok) ? "sounds/gun2.wav" : "sounds/gun1.wav";
    compas[0] = 0;
    compas[1] = 90;
    compas[2] = 180;
    compas[3] = 270;
    stamina = 0;
    combatRed = false;
    combatBlue = true;
}

AITank::AITank(const AITank& _tank)
{
    pos_x = _tank.pos_x;
    pos_y = _tank.pos_y;
    arrow = _tank.arrow;
    armour = _tank.armour;
    ammo = _tank.ammo;
    order = _tank.order;
    lives = _tank.lives;
    army = _tank.army;
    img = _tank.img;
    s1 = _tank.s1;
    compas[0] = 0;
    compas[1] = 90;
    compas[2] = 180;
    compas[3] = 270;
    stamina = _tank.stamina;
    combatRed = _tank.combatRed;
    combatBlue = _tank.combatBlue;
}

AITank::~AITank()
{
}

bool AITank::seek(Tank *_t)
{
    if (_t != 0)
    //танк считается замеченым, если находится на одной линии с сабжем хотя бы по одной оси координат и принадлежит другой армии
    return (((_t->X() >= pos_x - 5 && _t->X() <= pos_x + 5) || (_t->Y() >= pos_y - 5 && _t->Y() <= pos_y + 5)) && _t->get_army() != army);
    return false;
}

void AITank::domove(Map *_m, QList<Tank*> _T, Bonus *_b)
{
    if (_T[0] == 0)
        return; //выход из функции - на случай, если танк уничтожен
    //выход из функции - на случай, если танк вышел из зоны поражения
    if ((_T[0]->X() < pos_x - 5 || _T[0]->X() > pos_x + 5)  && (_T[0]->Y() < pos_y - 5 || _T[0]->Y() > pos_y + 5))
    {
        combatRed = false;
        combatBlue = true;
        return;
    }
    //определяем, в какую сторону ехать
    if (_T[0]->X() >= pos_x - 5 && _T[0]->X() <= pos_x + 5)
        arrow = (_T[0]->Y() >= pos_y) ? SOUTH : NORTH; //север-юг
    if (_T[0]->Y() >= pos_y - 5 && _T[0]->Y() <= pos_y + 5)
        arrow = (_T[0]->X() >= pos_x) ? EAST : WEST; //восток-запад
    if (!pluh(_m) && can_move(_m, _T)) //здесь танк различает только стены - водные поверхности не различает
    {
        move();
        found_bonus(_b);
    }
    else
        arrow = compas[qrand() % 4];
}

void AITank::control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b)
{
    if (stamina >= 110 && combatBlue)
        stamina = 0; //проехал 110 м. - начать движение заново
    if (stamina==0 && combatBlue) //начало движения
        arrow = compas[qrand() % 4]; //задаем случайное направление
    set_speed(_m->posXY(pos_x,pos_y)->type); //задаем скорость, в зависимости от поверхности
    if (!pluh(_m) && can_move(_m, _T) && !is_water(_m)) //ехать дальше, если нет препятствий, иначе сменить направление
        if (seek(_T[0])) //если заметил вражеский танк, то ехать в его сторону, поливая его огнем
        {
            combatRed = true;
            combatBlue = false;
            domove(_m, _T, _b);
            if (reload >= 8)
            {
                fire();
                reload = 0;
            }
            reload++;
        }
        else
        {
            move();
            found_bonus(_b);
        }
    else
        arrow = compas[qrand() % 4];
    stamina++;
}
