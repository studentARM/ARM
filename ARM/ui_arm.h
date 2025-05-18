/********************************************************************************
** Form generated from reading UI file 'arm.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARM_H
#define UI_ARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ARM
{
public:
    QWidget *centralwidget;
    QPushButton *btnTeacher;
    QPushButton *btnLeader;
    QPushButton *btnStudent;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ARM)
    {
        if (ARM->objectName().isEmpty())
            ARM->setObjectName("ARM");
        ARM->resize(800, 600);
        centralwidget = new QWidget(ARM);
        centralwidget->setObjectName("centralwidget");
        btnTeacher = new QPushButton(centralwidget);
        btnTeacher->setObjectName("btnTeacher");
        btnTeacher->setGeometry(QRect(200, 140, 411, 101));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        btnTeacher->setFont(font);
        btnTeacher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\276\321\202 \321\202\321\221\320\274\320\275\320\276-\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\320\276\320\263\320\276 (#4B0082) \320\272 \320\277\321\203\321\200\320\277\321\203\321\200\320\275\320\276\320\274\321\203 (#8B008B) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4B0082, stop:1 #8B008B);\n"
"    color: white;\n"
"    border-radius: 20px;\n"
"    border: none;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    /* \320\235\320\276\320\262\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \321\217\321\200\320\272\320\276-\321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#FF00FF) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 "
                        "#FF00FF, stop:1 #8B008B);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    /* \320\237\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \342\200\224 \320\261\320\276\320\273\320\265\320\265 \321\202\321\221\320\274\320\275\321\213\320\271 \321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#CC00CC) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #CC00CC, stop:1 #6A006A);\n"
"}"));
        btnTeacher->setAutoRepeat(false);
        btnLeader = new QPushButton(centralwidget);
        btnLeader->setObjectName("btnLeader");
        btnLeader->setGeometry(QRect(200, 260, 411, 101));
        btnLeader->setFont(font);
        btnLeader->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\276\321\202 \321\202\321\221\320\274\320\275\320\276-\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\320\276\320\263\320\276 (#4B0082) \320\272 \320\277\321\203\321\200\320\277\321\203\321\200\320\275\320\276\320\274\321\203 (#8B008B) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4B0082, stop:1 #8B008B);\n"
"    color: white;\n"
"    border-radius: 20px;\n"
"    border: none;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    /* \320\235\320\276\320\262\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \321\217\321\200\320\272\320\276-\321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#FF00FF) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 "
                        "#FF00FF, stop:1 #8B008B);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    /* \320\237\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \342\200\224 \320\261\320\276\320\273\320\265\320\265 \321\202\321\221\320\274\320\275\321\213\320\271 \321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#CC00CC) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #CC00CC, stop:1 #6A006A);\n"
"}"));
        btnStudent = new QPushButton(centralwidget);
        btnStudent->setObjectName("btnStudent");
        btnStudent->setGeometry(QRect(200, 390, 411, 101));
        btnStudent->setFont(font);
        btnStudent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\276\321\202 \321\202\321\221\320\274\320\275\320\276-\321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\320\276\320\263\320\276 (#4B0082) \320\272 \320\277\321\203\321\200\320\277\321\203\321\200\320\275\320\276\320\274\321\203 (#8B008B) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4B0082, stop:1 #8B008B);\n"
"    color: white;\n"
"    border-radius: 20px;\n"
"    border: none;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    /* \320\235\320\276\320\262\321\213\320\271 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202: \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \321\217\321\200\320\272\320\276-\321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#FF00FF) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 "
                        "#FF00FF, stop:1 #8B008B);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    /* \320\237\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 \342\200\224 \320\261\320\276\320\273\320\265\320\265 \321\202\321\221\320\274\320\275\321\213\320\271 \321\200\320\276\320\267\320\276\320\262\321\213\320\271 (#CC00CC) */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #CC00CC, stop:1 #6A006A);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 481, 91));
        QFont font1;
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8(""));
        ARM->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ARM);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ARM->setMenuBar(menubar);
        statusbar = new QStatusBar(ARM);
        statusbar->setObjectName("statusbar");
        ARM->setStatusBar(statusbar);

        retranslateUi(ARM);

        QMetaObject::connectSlotsByName(ARM);
    } // setupUi

    void retranslateUi(QMainWindow *ARM)
    {
        ARM->setWindowTitle(QCoreApplication::translate("ARM", "ARM", nullptr));
        btnTeacher->setText(QCoreApplication::translate("ARM", "\320\257 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        btnLeader->setText(QCoreApplication::translate("ARM", "\320\257 \320\273\320\270\320\264\320\265\321\200", nullptr));
        btnStudent->setText(QCoreApplication::translate("ARM", "\320\257 \321\201\321\202\321\203\320\264\320\265\320\275\321\202", nullptr));
        label->setText(QCoreApplication::translate("ARM", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ARM: public Ui_ARM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARM_H
