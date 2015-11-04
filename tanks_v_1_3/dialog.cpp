#include "dialog.h"
#include "ui_dialog.h"
#include "QSound"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QSound::play("sounds/Click.wav");
    res = 1400;
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    QSound::play("sounds/Click.wav");
    res = 1500;
    this->close();
}
