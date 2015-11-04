/********************************************************************************
** Form generated from reading UI file 'endgame.ui'
**
** Created: Wed 2. Sep 21:16:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAME_H
#define UI_ENDGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndGame
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *EndGame)
    {
        if (EndGame->objectName().isEmpty())
            EndGame->setObjectName(QString::fromUtf8("EndGame"));
        EndGame->resize(202, 110);
        EndGame->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);"));
        label = new QLabel(EndGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 91, 16));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_2 = new QLabel(EndGame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 30, 171, 20));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(214, 97, 1);"));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(EndGame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 60, 111, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(203, 92, 1);"));
        pushButton->setFlat(true);

        retranslateUi(EndGame);

        QMetaObject::connectSlotsByName(EndGame);
    } // setupUi

    void retranslateUi(QDialog *EndGame)
    {
        EndGame->setWindowTitle(QApplication::translate("EndGame", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EndGame", "Game Over", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EndGame", "You failed!", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("EndGame", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EndGame: public Ui_EndGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAME_H
