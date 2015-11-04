/********************************************************************************
** Form generated from reading UI file 'mediator.ui'
**
** Created: Wed 2. Sep 21:16:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIATOR_H
#define UI_MEDIATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mediator
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *status_ammo;
    QLabel *status_armored;
    QLabel *status_lives;
    QLabel *status_score;
    QLabel *status_max_score;
    QPushButton *pushButton;
    QLabel *status_air;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mediator)
    {
        if (Mediator->objectName().isEmpty())
            Mediator->setObjectName(QString::fromUtf8("Mediator"));
        Mediator->resize(527, 592);
        Mediator->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);"));
        centralWidget = new QWidget(Mediator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 400, 500));
        status_ammo = new QLabel(centralWidget);
        status_ammo->setObjectName(QString::fromUtf8("status_ammo"));
        status_ammo->setGeometry(QRect(410, 30, 111, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        font.setItalic(true);
        status_ammo->setFont(font);
        status_ammo->setStyleSheet(QString::fromUtf8("color: rgb(250, 50, 9);"));
        status_armored = new QLabel(centralWidget);
        status_armored->setObjectName(QString::fromUtf8("status_armored"));
        status_armored->setGeometry(QRect(410, 70, 111, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        font1.setItalic(true);
        status_armored->setFont(font1);
        status_armored->setStyleSheet(QString::fromUtf8("color:rgb(250, 50, 9)"));
        status_lives = new QLabel(centralWidget);
        status_lives->setObjectName(QString::fromUtf8("status_lives"));
        status_lives->setGeometry(QRect(410, 110, 111, 16));
        status_lives->setFont(font);
        status_lives->setStyleSheet(QString::fromUtf8("color: rgb(250, 50, 9);"));
        status_score = new QLabel(centralWidget);
        status_score->setObjectName(QString::fromUtf8("status_score"));
        status_score->setGeometry(QRect(10, 520, 261, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        status_score->setFont(font2);
        status_score->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        status_max_score = new QLabel(centralWidget);
        status_max_score->setObjectName(QString::fromUtf8("status_max_score"));
        status_max_score->setGeometry(QRect(280, 520, 241, 21));
        status_max_score->setFont(font2);
        status_max_score->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 460, 111, 41));
        QFont font3;
        font3.setPointSize(16);
        font3.setUnderline(true);
        pushButton->setFont(font3);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(222, 89, 0);"));
        pushButton->setFlat(true);
        status_air = new QLabel(centralWidget);
        status_air->setObjectName(QString::fromUtf8("status_air"));
        status_air->setGeometry(QRect(410, 150, 111, 16));
        status_air->setFont(font);
        status_air->setStyleSheet(QString::fromUtf8("color: rgb(250, 50, 9);"));
        Mediator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mediator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 527, 20));
        Mediator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mediator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Mediator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mediator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Mediator->setStatusBar(statusBar);

        retranslateUi(Mediator);

        QMetaObject::connectSlotsByName(Mediator);
    } // setupUi

    void retranslateUi(QMainWindow *Mediator)
    {
        Mediator->setWindowTitle(QApplication::translate("Mediator", "Tanks v 1_3", 0, QApplication::UnicodeUTF8));
        status_ammo->setText(QApplication::translate("Mediator", "Ammo:", 0, QApplication::UnicodeUTF8));
        status_armored->setText(QApplication::translate("Mediator", "Armoured:", 0, QApplication::UnicodeUTF8));
        status_lives->setText(QApplication::translate("Mediator", "Lives:", 0, QApplication::UnicodeUTF8));
        status_score->setText(QApplication::translate("Mediator", "Score:", 0, QApplication::UnicodeUTF8));
        status_max_score->setText(QApplication::translate("Mediator", "Max score:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Mediator", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        status_air->setText(QApplication::translate("Mediator", "Airstrike:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mediator: public Ui_Mediator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIATOR_H
