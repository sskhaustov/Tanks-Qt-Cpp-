#ifndef TANK_H
#define TANK_H

#include "header.h"
#include "QObject"
#include "QKeyEvent"
#include "map.h"
#include "bullet.h"
#include "bonus.h"

class Bullet;

class Tank: public QObject                  //танк, пока еще абстрактный
{
    Q_OBJECT
    public:
        Tank();
        Tank(const Tank &_tank);
        ~Tank();
        bool operator==(const Tank &obj);
        void move();                                           //движение танка
        void fire();                                           //стрельба
        void set_speed(CellType _cell);                        //задать скорость движения, в зависимости от поверхности
        bool can_move(Map *_m, QList<Tank*> _T);                     //проверяет, можно ли проехать
        bool pluh(Map *_m);                                    //танк утонул
        bool boundary(int _x, int _y);                         //определяем область, занимаемую танком
        bool is_kill() {return armour<=0;}                     //проверяет, уничтожен ли танк
        void set_dammage(int _dammage);                        //повреждение
        void found_bonus(Bonus *_b);                           //нашел бонус
        void set_lives(int _lives) {lives += _lives;}          //задать число жизней
        void repair() {armour = 100;}                          //отремонтировать танк
        void set_pos(int _x, int _y) {pos_x = _x; pos_y = _y;} //переместить танк
        int X() {return pos_x;}                                //получить координату Х
        int Y() {return pos_y;}                                //получить координату У
        int nearestX();                                        //получить координату Х перед танком
        int nearestY();                                        //получить координату У перед танком
        QString IMG() {return img;}                            //отобразить танк на игровом поле
        int get_speed() {return speed;}                        //узнать скорость
        int get_arrow() {return arrow;}                        //узнать направление
        int get_armour() {return armour;}                      //узнать броню
        int get_ammo() {return ammo;}                          //узнать количество боеприпасов
        int get_order() {return order;}                        //узнать порядковый номер
        int get_lives() {return lives;}                        //узнать число жизней
        Side get_army() {return army;}                         //узнать сторону
        virtual void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b) = 0; //управление танком (игрок и компьютер управляют им по-разному)
    protected:
        int speed;      //скорость
        int pos_x;      //координата x
        int pos_y;      //координата у
        int arrow;      //направление
        int armour;     //броня
        int ammo;       //боеприпасы
        int order;      //порядковый номер танка на карте
        int reload;     //перезарядка
        int lives;      //жизни
        Side army;      //сторона
        QString img;    //изображение танка
        QString s1;     //звуки выстрелов
    signals:
        void shot(Bullet *_b);       //танк выстрелил
        void kill(Tank *_t);         //танк уничтожили
        void found(Bonus *_b);       //танк нашел бонус
};

class AITank: public Tank           //уже реальный танк, управляемый компьютером
{
    public:
        AITank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army);
        AITank(const AITank& _tank);
        ~AITank();
        void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b); //ИИ сам управляет танком (исп. только 2 параметра, поэтому в качестве
            //одного из аргументов будет передан NULL)
    protected:
        bool seek(Tank *_t); //поиск цели
        bool is_water(Map *_m) {return _m->is_wc(nearestX(),nearestY());} //водные поверхности
        void domove(Map *_m, QList<Tank*> _T, Bonus *_b); //двигаться в сторону найденной цели
        int compas[4]; //возможные направления движения танка
        int stamina;    //расстояние, которое проехал танк
        bool combatRed;  //заметил цель - открыть огонь на поражение
        bool combatBlue; //нет цели в поле зрения - не стрелять
};

class PlayerTank: public Tank       //уже реальный танк, управляемый человеком
{
    public:
        PlayerTank(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives,  int _order, Side _army);
        PlayerTank(const PlayerTank& _tank);
        ~PlayerTank();
        void control(QKeyEvent *e, Map *_m, QList<Tank*> _T, Bonus *_b); //управление танком осуществляется при помощи клавиш
};

class Artillery: public AITank        //артиллеристская гаубица, управляемая компьютером
{
    public:
        Artillery(int _pos_x, int _pos_y, int _arrow, int _armour, int _ammo, int _lives, int _order, Side _army);
        ~Artillery();
};

#endif // TANK_H
