#include "endgame.h"
#include "ui_endgame.h"
#include "QSound"

EndGame::EndGame(QWidget *parent, QString _inf, int _sc) :
    QDialog(parent),
    ui(new Ui::EndGame)
{
    ui->setupUi(this);
    if (_sc != 0)
        ui->label_2->setText(tr("%1 %2").arg(_inf).arg(_sc));
    else
        ui->label_2->setText(_inf);
}

EndGame::~EndGame()
{
    delete ui;
}

void EndGame::on_pushButton_clicked()
{
    QSound::play("sounds/Click.wav");
    res = 1400;
    this->close();
}
