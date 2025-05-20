/********************************************************************************
** Form generated from reading UI file 'mainwindowteacher.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWTEACHER_H
#define UI_MAINWINDOWTEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowTeacher
{
public:
    QPushButton *Give;
    QPushButton *Materials;
    QTableWidget *stats;
    QLabel *label;
    QComboBox *group;
    QPushButton *labs;

    void setupUi(QDialog *MainWindowTeacher)
    {
        if (MainWindowTeacher->objectName().isEmpty())
            MainWindowTeacher->setObjectName("MainWindowTeacher");
        MainWindowTeacher->resize(1200, 600);
        Give = new QPushButton(MainWindowTeacher);
        Give->setObjectName("Give");
        Give->setGeometry(QRect(20, 460, 361, 71));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        Give->setFont(font);
        Give->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Materials = new QPushButton(MainWindowTeacher);
        Materials->setObjectName("Materials");
        Materials->setGeometry(QRect(810, 460, 361, 71));
        Materials->setFont(font);
        Materials->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stats = new QTableWidget(MainWindowTeacher);
        if (stats->columnCount() < 5)
            stats->setColumnCount(5);
        if (stats->rowCount() < 30)
            stats->setRowCount(30);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(10, 50, 1181, 391));
        stats->setRowCount(30);
        stats->setColumnCount(5);
        label = new QLabel(MainWindowTeacher);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 0, 341, 51));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        group = new QComboBox(MainWindowTeacher);
        group->setObjectName("group");
        group->setGeometry(QRect(980, 10, 181, 31));
        QFont font2;
        font2.setPointSize(15);
        group->setFont(font2);
        group->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        labs = new QPushButton(MainWindowTeacher);
        labs->setObjectName("labs");
        labs->setGeometry(QRect(440, 460, 321, 71));
        labs->setFont(font);
        labs->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(MainWindowTeacher);

        QMetaObject::connectSlotsByName(MainWindowTeacher);
    } // setupUi

    void retranslateUi(QDialog *MainWindowTeacher)
    {
        MainWindowTeacher->setWindowTitle(QCoreApplication::translate("MainWindowTeacher", "Dialog", nullptr));
        Give->setText(QCoreApplication::translate("MainWindowTeacher", "\320\222\321\213\320\264\320\260\321\202\321\214 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        Materials->setText(QCoreApplication::translate("MainWindowTeacher", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\321\213 \320\273\320\270\320\264\320\265\321\200\320\260\320\274", nullptr));
        label->setText(QCoreApplication::translate("MainWindowTeacher", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260\320\274", nullptr));
        labs->setText(QCoreApplication::translate("MainWindowTeacher", "\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowTeacher: public Ui_MainWindowTeacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWTEACHER_H
