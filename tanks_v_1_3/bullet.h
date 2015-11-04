#ifndef BULLET_H
#define BULLET_H

#include "header.h"
#include "QObject"
#include "QTimer"
#include "map.h"
#include "tank.h"
#include "QGraphicsPixmapItem"

class Tank;

class Bullet: public QObject
{
    Q_OBJECT
    public:
        Bullet(int _x, int _y, int _arrow, Side _army);
        Bullet(const Bullet &_b);
        ~Bullet();
        bool operator==(const Bullet &_obj);
        void move(); //движение снаряда
        bool popal(Map *_m, QList<Tank*> _T, QList<Bullet*> _B); //столкновение снаряда с препятствием (стена, танк)
        int X() {return x;}
        int Y() {return y;}
        int id() {return ID;}
        QString IMG() {return img;}
    protected:
        void central(); //сместить координаты снаряда относительно танка (чтобы он вылетал из дула, а не из башни)
        int x; //ось Х
        int y; //ось У
        int speed; //скорость
        int arrow; //азимут
        Side army; //сторона, которой принадлежит танк, выпустивший снаряд
        QString img; //изображение
        int ID; //
    signals:
        void popal_stena(Cell *_pos); //снаряд попал в стену
        void popal_tank(Tank *_t); //снаряд попал в танк
};

class BulletTimer: public QObject  //таймер для обработки движения снаряда
{
    Q_OBJECT
    public:
        BulletTimer(Bullet *_b, QGraphicsPixmapItem *_p);
        ~BulletTimer();
        void start(); //пуск
        void stop();  //стоп
    protected:
        QTimer *t;    //встроенный таймер
        Bullet *b;  //непосредственно пуля
        QGraphicsPixmapItem *p;//и ее картинка
        //<--- это указатели на объекты, которые необходимо передать сигналом в слот
    signals:
        void takt(Bullet *_b, QGraphicsPixmapItem *_p, BulletTimer *_tmr); //собственно сигнал
    protected slots:
        void on_takt() {emit takt(b, p, this);} //это слот, который каждый такт таймера посылает сигнал takt
};

#endif // BULLET_H
