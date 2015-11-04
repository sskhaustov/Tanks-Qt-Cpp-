#include <QtGui/QApplication>
#include "mediator.h"
#include "mainmenu.h"
#include "QTextCodec"
#include "time.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251"));
    //Mediator w;
    srand(time(NULL));
    MainMenu w;
    w.show();
    
    return a.exec();
}
