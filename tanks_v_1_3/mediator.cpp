#include "mediator.h"
#include "ui_mediator.h"
#include "QMessageBox"
#include "time.h"
#include "mainmenu.h"
#include "dialog.h"
#include "endgame.h"
#include "QSound"

Mediator::Mediator(QWidget *parent, int _level, int _mode, int _side) :
    QMainWindow(parent),
    ui(new Ui::Mediator)
{
    ui->setupUi(this);
    level = _level;
    bon = NULL;
    air = NULL;
    rec = new Score();
    rec->load_score();
    connect(this, SIGNAL(win()), this, SLOT(on_win()));
    connect(this, SIGNAL(lose()), this, SLOT(on_lose()));
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->status_max_score->setText(tr("Max score: %1").arg(rec->get_max_score()));
    mode = _mode;
    set_game_settings(_mode, _side);
    create_new_game();
}

Mediator::~Mediator()
{
    delete rec;
    delete ui;
}

void Mediator::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_P)
        pause();
    if (paused)
        return;
    if (T[0] != 0)
    {
        T[0]->control(e, m, T, bon);
        if (T[0] != 0)
        {
            tank[0]->setRotation(T[0]->get_arrow());
            tank[0]->setPos(T[0]->X(), T[0]->Y());
        }
    }
}

void Mediator::mousePressEvent(QMouseEvent *e)
{
    if (paused)
        return;
    if (airstrike == 0)
        return;
    if (air != NULL)
        return;
    if (e->x() > 381 || e->y() > 485 || e->x() < 12 || e->y() < 29)
        return;
    air = new Bomber(e->x(), 30, T[0]->get_army(), e->y());
    pl = add_texture(air->IMG(), 40, 40, air->X(), air->Y());
    pl->setRotation(SOUTH);
    pl->setPos(air->X(), air->Y());
    pilot->start(30);
    connect(air, SIGNAL(bomba(Bomb*)), this, SLOT(on_bombing(Bomb*)));
    airstrike--;
    ui->status_air->setText(tr("Airstrike: %1").arg(airstrike));
}

void Mediator::create_new_game()
{
    paused = false;
    stopped = false;
    created_tanks = 1;
    wave = 0;
    qFill(T, (Tank*)NULL);   //танки
    qFill(B, (Bullet*)NULL); //и пульки пока только в плане
    Game = new gamePlaying(num_tanks, true);
    ui->status_score->setText(tr("Score: %1").arg(rec->get_curr_score()));
    m = new Map(Game->map(level % 8));
    int flag = m->create();
    if (flag == 1)
        QMessageBox::information(this, "Error!", "File has not been found!", QMessageBox::Ok);
    if (flag == 2)
        QMessageBox::information(this, "Error!", "Cannot read the data!", QMessageBox::Ok);
    if (flag == 0)
    {
        for (int _i = 0, _x = 0; _i < MAXROW; _i++, _x += 20)
            for (int _j = 0, _y = 0; _j < MAXCOL; _j++, _y += 20)
                p[_i][_j] = add_texture(m->posXY(_x,_y)->pic, SIZE_X, SIZE_Y, _x, _y);

        PlayerTank *pt = new PlayerTank(20,20,0,100,100,lvs_curr,0,gamer_side);
        tank[0] = add_texture(pt->IMG(), SIZE_X, SIZE_Y, pt->X(), pt->Y());
        T.append(pt);
        connect(T[0], SIGNAL(shot(Bullet*)), this, SLOT(on_shot(Bullet*)));
        connect(T[0], SIGNAL(kill(Tank*)), this, SLOT(on_tank_kill(Tank*)));
        connect(T[0], SIGNAL(found(Bonus*)), this, SLOT(on_found_bonus(Bonus*)));
        ui->status_ammo->setText(tr("Ammo: %1").arg(T[0]->get_ammo()));
        ui->status_armored->setText(tr("Armoured: %1").arg(T[0]->get_armour()));
        ui->status_lives->setText(tr("Lives: %1").arg(T[0]->get_lives()));
        ui->status_air->setText(tr("Airstrike: %1").arg(airstrike));

        respawn_bonus();

        resp = new QTimer(this);
        resp->start(2000);
        connect(resp, SIGNAL(timeout()), this, SLOT(respawn()));

        driver = new QTimer(this);
        driver->start(100);
        connect(driver, SIGNAL(timeout()), this, SLOT(drive_tanks()));

        pilot = new QTimer(this);
        connect(pilot, SIGNAL(timeout()), this, SLOT(bomber_fly()));
    }
}

void Mediator::delete_game()
{
    scene->clear();             //убираем со сцены все изображения
    foreach (Tank* _i, T)
    {
        if (_i != 0)
            delete _i;
    }
    foreach (Bullet* _i, B)
    {
        if (_i != 0)
            delete _i;
    }
    if (bon != NULL)
    {
        delete bon;
        bon = NULL;
    }
    T.clear();
    delete m;
    delete driver;
    delete resp;
    delete Game;
}

void Mediator::set_game_settings(int _mode, int _side)
{
    switch (_mode)
    {
        case 0:
            arm = 10;
            lvs = 3;
            num_tanks = 8;
            airstrike = 3;
        break;
        case 1:
            arm = 40;
            lvs = 2;
            num_tanks = 12;
            airstrike = 2;
        break;
        case 2:
            arm = 90;
            lvs = 1;
            num_tanks = 15;
            airstrike = 1;
        break;
        default:
            arm = lvs = num_tanks = airstrike = 0;
    }
    lvs_curr = lvs;
    switch (_side)
    {
        case 0:
            gamer_side = Sovok;
            ai_side = Dodik;
        break;
        default:
            gamer_side = Dodik;
            ai_side = Sovok;
    }
}

void Mediator::pause()
{
    if (!paused)
    {
        paused = true;
        return;
    }
    else
        paused = false;
}

void Mediator::bomber_fly()
{
    if (paused)
        return;
    if (air->Y() <= 485)
    {
        air->control();
        pl->setPos(air->X(), air->Y());
        return;
    }
    pilot->stop();
    scene->removeItem(pl);
    delete air;
    air = NULL;
}

void Mediator::respawn()
{
    if (paused)
        return;
    if (created_tanks == num_tanks)
    {
        resp->stop();
        return;
    }
    if (wave < 4)
    {
        srand(time(NULL));
        AITank *at = new AITank(360,460,0,arm,30,0,created_tanks,ai_side);
        tank[created_tanks] = add_texture(at->IMG(), SIZE_X, SIZE_Y, at->X(), at->Y());
        T.append(at);
        connect(T[T.count() - 1], SIGNAL(shot(Bullet*)), this, SLOT(on_shot(Bullet*)));
        connect(T[T.count() - 1], SIGNAL(kill(Tank*)), this, SLOT(on_tank_kill(Tank*)));
        connect(T[T.count() - 1], SIGNAL(found(Bonus*)), this, SLOT(on_found_bonus(Bonus*)));
        wave++;
        created_tanks++;
    }
}

/*слот обрабатывает только один снаряд, поэтому все переменные - локальные, т.к.
  слотов вызовется столько же, сколько будет снарядов на карте*/
void Mediator::on_shot(Bullet *_b)
{
    B.append(_b);
    QGraphicsPixmapItem *_bl; //картинка для пули
    _bl = add_texture(_b->IMG(), SIZE_BULLET_X, SIZE_BULLET_Y, _b->X(), _b->Y()); //помещаем пулю на карту
    //QMessageBox::information(this, "", tr("%1 %2\n%3 %4").arg(plr->X()).arg(plr->Y()).arg(_bul->X()).arg(_bul->Y()), QMessageBox::Ok);
    BulletTimer *_t = new BulletTimer(_b, _bl); //создаем таймер для обработки снаряда
    connect(_t, SIGNAL(takt(Bullet*,QGraphicsPixmapItem*,BulletTimer*)), this, SLOT(on_tick(Bullet*,QGraphicsPixmapItem*,BulletTimer*))); //связывает таймер со слотом
    connect(_b, SIGNAL(popal_stena(Cell*)), this, SLOT(on_popal_stena(Cell*)));
    connect(_b, SIGNAL(popal_tank(Tank*)), this, SLOT(on_popal_tank(Tank*)));
    _t->start(); //запускаем таймер
    ui->status_ammo->setText(tr("Ammo: %1").arg(T[0]->get_ammo()));
    //ammo->setText(tr("Ammo: %1").arg(pt[0]->get_ammo()));
    renew();
}

void Mediator::on_bombing(Bomb *_b)
{
    if (_b->X() >= WIDTH-20 || _b->X() <= 0 || _b->Y() >= HEIGHT-20 || _b->Y() <= 0)
    {
        delete _b;
        return;
    }
    QGraphicsPixmapItem *_bomp;
    _bomp = add_texture(_b->IMG(), SIZE_X, SIZE_Y, _b->X(), _b->Y());
    _bomp->setPos(_b->X(), _b->Y());
    connect(_b, SIGNAL(popal_stena(Cell*)), this, SLOT(on_popal_stena(Cell*)));
    connect(_b, SIGNAL(popal_tank(Tank*)), this, SLOT(on_popal_tank(Tank*)));
    _b->popal(m, T);
    delete _b;
    renew();
}


void Mediator::on_tank_kill(Tank *_t)
{
    int _n = _t->get_order();
    if (_t->get_lives() > 0)
    {
        int _x, _y;
        _t->set_lives(-1);
        _t->repair();
        if (_n == 0)
        {
            _x = _y = 20;
            ui->status_armored->setText(tr("Armoured: %1").arg(_t->get_armour()));
            ui->status_lives->setText(tr("Lives: %1").arg(_t->get_lives()));
        }
        else
        {
            _x = 360;
            _y = 460;
        }
        _t->set_pos(_x,_y);
        tank[_n]->setPos(_x,_y);
        return;
    }
    if (_n == 0)
    {
        ui->status_armored->setText(tr("Armoured: 0"));
        Game->dead();
    }
    scene->removeItem(tank[_n]);
    T[_n] = 0;
    delete _t;
    Game->dec_tanks();
    wave--;
}

void Mediator::drive_tanks()
{
    if (paused)
        return;
    foreach (Tank* _i, T)
    {
        if (_i != 0 && _i->get_order() != 0)
        {
            int _n = _i->get_order();
            if (level == 2)
                _i->control(NULL, m, T, bon);
            else
                _i->control(NULL, m, T, NULL);
            if (_i != 0)
            {
                tank[_n]->setRotation(_i->get_arrow());
                tank[_n]->setPos(_i->X(),_i->Y());
            }
        }
    }
    if (Game->win())
        emit win();
    if (Game->lose())
        emit lose();
}

void Mediator::renew()
{
    scene->removeItem(tank[0]);
    tank[0] = add_texture(T[0]->IMG(), SIZE_X, SIZE_Y, T[0]->X(), T[0]->Y());
    tank[0]->setRotation(T[0]->get_arrow());
}

void Mediator::on_popal_stena(Cell *_pos)
{
    //QMessageBox::information(this, "", tr("%1").arg(_pos->get_img()), QMessageBox::Ok);
    for (int _i = 0; _i < MAXROW; _i++)
        for (int _j = 0; _j < MAXCOL; _j++)
            if (_pos->x == m->get_cell(_i, _j)->x && _pos->y == m->get_cell(_i, _j)->y)
            {
                scene->removeItem(p[_i][_j]); //убираем нужную текстуру и накладываем на ее место другую
                p[_i][_j] = add_texture(_pos->pic, SIZE_X, SIZE_Y, _pos->x, _pos->y);
                return;
            }
    renew();
    //t[0] = renew(t[0],pt[0]);
}

void Mediator::on_popal_tank(Tank *_t)
{
    if (_t != 0)
    {
        int _n = _t->get_order();
        if (_n == 0)
            ui->status_armored->setText(tr("Armoured: %1").arg(_t->get_armour()));
        else
        {
            rec->inc_score();
            ui->status_score->setText(tr("Score: %1").arg(rec->get_curr_score()));
        }
    }
}

void Mediator::respawn_bonus()
{
    if (bon != NULL)
        return;
    int x, y;
    BonusType bt;
    do
    {
        x = qrand() % RESPAWN_BONUS_X + 20;
        y = qrand() % RESPAWN_BONUS_Y + 20;
    }
    while (!m->is_road(x, y) || m->is_wc(x, y));
    switch (qrand() % 3)
    {
        case 0:
            bt = Live;
        break;
        case 1:
            bt = Repair;
        break;
        case 2:
            bt = Ammo;
        break;
    }
    bon = new Bonus(m->posXY(x,y)->x,m->posXY(x,y)->y,bt);
    b = add_texture(bon->IMG(), SIZE_X, SIZE_Y, bon->X(), bon->Y());
}

void Mediator::on_tick(Bullet *_b, QGraphicsPixmapItem *_p, BulletTimer *_tmr)
{
    if (paused)
        return;
    if (stopped)
    {
        _tmr->stop();
        scene->removeItem(_p);
        B.removeOne(_b);
        delete _b;             //
        delete _tmr;
        return;
    }
    _b->move(); //двигаем пулю
    _p->setPos(_b->X(), _b->Y()); //и картинку
    if (_b->X() >= WIDTH-20 || _b->X() <= 0 || _b->Y() >= HEIGHT-20 || _b->Y() <= 0 || _b->popal(m, T, B)) //условие 'уничтожения' пули
    {
        _tmr->stop();
        scene->removeItem(_p); //чистка памяти
        B.removeOne(_b);
        delete _b;             //
        delete _tmr;           //
    }
}

void Mediator::on_found_bonus(Bonus *_b)
{
    scene->removeItem(b);
    delete _b;
    bon = NULL;
    ui->status_ammo->setText(tr("Ammo: %1").arg(T[0]->get_ammo()));
    ui->status_armored->setText(tr("Armoured: %1").arg(T[0]->get_armour()));
    ui->status_lives->setText(tr("Lives: %1").arg(T[0]->get_lives()));
    respawn_bonus();
}

QGraphicsPixmapItem* Mediator::add_texture(QString _texture, int _size_x, int _size_y, int _pos_x, int _pos_y)
{
    QGraphicsPixmapItem *_px;
    _px = scene->addPixmap(QPixmap(_texture)); //добавляем картинку
    _px->setOffset(-0.5*QPointF(_size_x, _size_y)); //смещаем начало координат в центр
    _px->setPos(_pos_x, _pos_y); //помещаем на карту
    return _px;
}

void Mediator::on_win()
{
    stopped  = true;
    lvs_curr = T[0]->get_lives();
    rec->set_score_win(T[0]->get_lives(),mode,T[0]->get_ammo(),T[0]->get_armour());
    QSound::play("sounds/victory.wav");
    EndGame d(0,"Victory!",0);
    d.show();
    d.exec();
    int _res = d.return_res();
    switch (_res)
    {
        case 1400:
            delete_game();
            level++;
            create_new_game();
        break;
    }
}

void Mediator::on_lose()
{
    stopped = true;
    lvs_curr = lvs;
    if (rec->get_curr_score() > rec->get_max_score())
    {
        rec->save_score();
        rec->load_score();
        ui->status_max_score->setText(tr("Max score: %1").arg(rec->get_max_score()));
    }
    QSound::play("sounds/fail.wav");
    EndGame d(0,"Your score: ",rec->get_curr_score());
    d.show();
    d.exec();
    int _res = d.return_res();
    switch (_res)
    {
        case 1400:
            delete_game();
            rec->cancel();
            level = 0;
            create_new_game();
        break;
    }
}

void Mediator::on_pushButton_clicked()
{
    if (!paused)
        pause();
    QSound::play("sounds/Click.wav");
    Dialog d;
    d.show();
    d.exec();
    int _res = d.return_res();
    switch (_res)
    {
        case 1400:
            if (rec->get_curr_score() > rec->get_max_score())
                rec->save_score();
            delete_game();
            close();
            MainMenu w;
            w.show();
            w.exec();
        break;
    }
}
