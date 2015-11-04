/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Wed 2. Sep 21:16:02 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(435, 367);
        About->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 42, 42);"));
        textEdit = new QTextEdit(About);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(10, 10, 421, 351));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8("color:rgb(254, 17, 0);\n"
"background-color: rgb(35, 150, 3);"));
        textEdit->setReadOnly(true);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
