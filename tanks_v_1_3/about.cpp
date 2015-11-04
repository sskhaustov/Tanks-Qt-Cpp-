#include "about.h"
#include "ui_about.h"
#include "stdio.h"
#include "stdlib.h"
#include "QMessageBox"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    char str[100];
    FILE *lib = fopen("инструкция.txt", "r");
    if (lib == NULL)
        close();
    for (int _i = 0; _i < 13; _i++)
    {
        fgets(str, 100, lib);
        ui->textEdit->append(str);
    }
}

About::~About()
{
    delete ui;
}
