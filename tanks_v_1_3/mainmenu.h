#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    
private slots:
    void on_clos_clicked();

    void on_new_game_clicked();

    void on_info_clicked();

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
