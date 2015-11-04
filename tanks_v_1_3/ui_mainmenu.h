/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created: Wed 2. Sep 21:16:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *new_game;
    QPushButton *info;
    QPushButton *clos;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QLabel *log;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(400, 300);
        MainMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(43, 43, 43);"));
        new_game = new QPushButton(MainMenu);
        new_game->setObjectName(QString::fromUtf8("new_game"));
        new_game->setGeometry(QRect(10, 180, 121, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        new_game->setFont(font);
        new_game->setCursor(QCursor(Qt::PointingHandCursor));
        new_game->setMouseTracking(false);
        new_game->setAutoFillBackground(true);
        new_game->setStyleSheet(QString::fromUtf8("color: rgb(255, 146, 21);"));
        new_game->setFlat(true);
        info = new QPushButton(MainMenu);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(10, 220, 121, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        info->setFont(font1);
        info->setCursor(QCursor(Qt::PointingHandCursor));
        info->setAutoFillBackground(true);
        info->setStyleSheet(QString::fromUtf8("color: rgb(238, 163, 14);"));
        info->setFlat(true);
        clos = new QPushButton(MainMenu);
        clos->setObjectName(QString::fromUtf8("clos"));
        clos->setGeometry(QRect(10, 260, 121, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        font2.setKerning(true);
        clos->setFont(font2);
        clos->setCursor(QCursor(Qt::PointingHandCursor));
        clos->setAutoFillBackground(true);
        clos->setStyleSheet(QString::fromUtf8("color: rgb(225, 140, 2);"));
        clos->setFlat(true);
        comboBox = new QComboBox(MainMenu);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 80, 181, 22));
        comboBox->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0);\n"
"border-color: rgb(15, 197, 2);\n"
"background-color: rgb(15, 197, 2);"));
        label = new QLabel(MainMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 141, 16));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(226, 21, 14);"));
        comboBox_2 = new QComboBox(MainMenu);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 130, 181, 22));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 179, 2);\n"
"color: rgb(248, 29, 0);\n"
"border-color: rgb(10, 179, 2);"));
        label_2 = new QLabel(MainMenu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 171, 16));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(197, 17, 17);"));
        comboBox_3 = new QComboBox(MainMenu);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 30, 181, 22));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(3, 172, 3);\n"
"border-top-color: rgb(3, 172, 3);\n"
"border-left-color: rgb(3, 172, 3);\n"
"border-color: rgb(3, 172, 3);\n"
"color: rgb(243, 2, 2);"));
        label_3 = new QLabel(MainMenu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 171, 16));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(204, 33, 20);"));
        log = new QLabel(MainMenu);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(150, 200, 241, 81));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", 0, QApplication::UnicodeUTF8));
        new_game->setText(QApplication::translate("MainMenu", "\320\270\320\263\321\200\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        info->setText(QApplication::translate("MainMenu", "\320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        clos->setText(QApplication::translate("MainMenu", "\320\262\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainMenu", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\260\321\200\321\202\321\203", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainMenu", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainMenu", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 \320\272\320\276\320\275\321\204\320\273\320\270\320\272\321\202\320\260", 0, QApplication::UnicodeUTF8));
        log->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
