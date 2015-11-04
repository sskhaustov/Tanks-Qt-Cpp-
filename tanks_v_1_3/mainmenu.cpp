#include "mediator.h"
#include "about.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "dialog.h"
#include "QSound"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->comboBox->addItem(tr("Полигон"));
    ui->comboBox->addItem(tr("Брестская крепость"));
    ui->comboBox->addItem(tr("Балатон"));
    ui->comboBox->addItem(tr("Карелия"));
    ui->comboBox->addItem(tr("Сталинград"));
    ui->comboBox->addItem(tr("Севастополь"));
    ui->comboBox->addItem(tr("Краков"));
    ui->comboBox->addItem(tr("Висла"));

    ui->comboBox_2->addItem(tr("Легко"));
    ui->comboBox_2->addItem(tr("Средне"));
    ui->comboBox_2->addItem(tr("Сложно"));

    ui->comboBox_3->addItem(tr("СССР"));
    ui->comboBox_3->addItem(tr("Третий Рейх"));

    ui->log->setPixmap(QPixmap("images/logo.png"));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_clos_clicked()
{
    QSound::play("sounds/Click.wav");
    Dialog d;
    d.show();
    d.exec();
    int _res = d.return_res();
    switch (_res)
    {
        case 1400:
            close();
        break;
    }
}

void MainMenu::on_new_game_clicked()
{
    QSound::play("sounds/Click.wav");
    Mediator *m = new Mediator(0, ui->comboBox->currentIndex(), ui->comboBox_2->currentIndex(), ui->comboBox_3->currentIndex());
    m->show();
    this->close();
}

void MainMenu::on_info_clicked()
{
    QSound::play("sounds/Click.wav");
    About *w = new About(0);
    w->show();
}

void MainMenu::on_comboBox_3_currentIndexChanged(int index)
{
    QSound::play("sounds/Click_08.wav");
}

void MainMenu::on_comboBox_currentIndexChanged(int index)
{
    QSound::play("sounds/Click_08.wav");
}

void MainMenu::on_comboBox_2_currentIndexChanged(int index)
{
    QSound::play("sounds/Click_08.wav");
}
