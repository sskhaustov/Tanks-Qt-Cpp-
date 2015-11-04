#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QMainWindow>
#include "QDialog"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "header.h"
#include "map.h"
#include "tank.h"
#include "gamePlaying.h"
#include "score.h"
#include "bonus.h"
#include "bomber.h"

namespace Ui {
class Mediator;
}

class Mediator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Mediator(QWidget *parent, int _level, int _mode, int _side);
    ~Mediator();
    
private:
    virtual void keyPressEvent(QKeyEvent *e); //обработчик события нажатия клавиши
    virtual void mousePressEvent(QMouseEvent *e); //обработчик события нажатия мыши
    void create_new_game();
    void delete_game();
    void renew();
    void pause();
    void respawn_bonus();                                       //порождение бонусов
    void set_game_settings(int _mode, int _side);
    QGraphicsPixmapItem* add_texture(QString _texture, int _size_x, int _size_y, int _pos_x, int _pos_y);
    Ui::Mediator *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *p[MAXROW][MAXCOL];
    QGraphicsPixmapItem *tank[20];
    QGraphicsPixmapItem *b; //бонус
    QGraphicsPixmapItem *pl;
    Bonus *bon;
    Map *m;
    QTimer *driver;     //таймер, управляющий танками
    QTimer *resp;       //таймер, порождающий танки
    QTimer *pilot;
    gamePlaying *Game;
    QList<Tank*> T;     // танчики
    QList<Bullet*> B;   //пульки
    Bomber *air;       //бомбардировщик
    int num_tanks;      //всего танков
    int created_tanks;  //число танков, присутствующих на поле боя
    int wave;           //волна танков (4 штуки)
    int level;          //карта
    int mode;           //уровень сложности
    bool stopped; //остановка игры

    int arm;      //броня вражеских танков
    int lvs;      //количество жизней
    int lvs_curr; //текущее количество жизней
    int airstrike; //число авиаударов
    Side gamer_side;
    Side ai_side;

    Score *rec;
    bool paused;    //пауза
signals:
    void win();
    void lose();
protected slots:
    void on_shot(Bullet *_b);                                   //обработка выстрела танка
    void on_tick(Bullet*,QGraphicsPixmapItem*,BulletTimer*);    //обработка полета пули
    void on_popal_stena(Cell*);                                 //обработка попадания пули в стену
    void on_popal_tank(Tank*);                                  //обработка попадания пули в танк
    void drive_tanks();                                         //обработка движения танков-компьютеров
    void on_win();                                              //победа
    void on_lose();                                             //поражение
    void on_tank_kill(Tank *_t);                                //обработка уничтожения танка
    void on_found_bonus(Bonus *_b);                             //найден бонус
    void respawn();                                             //порождение танков
    void bomber_fly();                                          //перемещение бомбардировщика
    void on_bombing(Bomb *_b);                                  //бомбежка
private slots:
    void on_pushButton_clicked();
};

#endif // MEDIATOR_H
