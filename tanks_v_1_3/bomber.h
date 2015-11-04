#ifndef BOMBER_H
#define BOMBER_H

#include "header.h"
#include "QString"
#include "map.h"
#include "tank.h"
#include "QObject"

class Tank;
class Bomb;

struct Point
{
    int x;
    int y;
};

class Bomber: public QObject
{
    Q_OBJECT
    public:
        Bomber(int _x, int _y, Side _army, int _btar);
        ~Bomber();
        void control();
        QString IMG() {return pic;}
        int X() {return x;}
        int Y() {return y;}
    private:
        void domove() {y+=speed;} //движение к точке атаки
        void fire();              //атака
        int x;
        int y;
        int btar;                 //точка-указатель на цель
        int speed;                //скорость
        bool empty;               //сбросил бомбы или нет
        Point rad[9]; //радиус поражения
        Side army;
        QString pic;
        QString s;    //звуковое подтверждение
    signals:
        void bomba(Bomb *_b);
};

class Bomb: public QObject
{
    Q_OBJECT
    public:
        Bomb(int _x, int _y);
        ~Bomb();
        QString IMG() {return img;}
        int X() {return x;}
        int Y() {return y;}
        void popal(Map *_m, QList<Tank*> _T);
    private:
        int x;
        int y;
        QString img;
    signals:
        void popal_stena(Cell *_pos); //снаряд попал в стену
        void popal_tank(Tank *_t); //снаряд попал в танк
};

#endif // BOMBER_H
