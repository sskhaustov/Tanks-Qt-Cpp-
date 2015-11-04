#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    int return_res() {return res;}

private:
    Ui::Dialog *ui;
    int res;
};

#endif // DIALOG_H
