#ifndef ENDGAME_H
#define ENDGAME_H

#include <QDialog>

namespace Ui {
class EndGame;
}

class EndGame : public QDialog
{
    Q_OBJECT
    
public:
    explicit EndGame(QWidget *parent, QString _inf, int _sc);
    ~EndGame();
    
public slots:
    void on_pushButton_clicked();
    int return_res() {return res;}

private:
    Ui::EndGame *ui;
    int res;
};

#endif // ENDGAME_H
