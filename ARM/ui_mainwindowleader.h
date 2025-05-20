/********************************************************************************
** Form generated from reading UI file 'mainwindowleader.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWLEADER_H
#define UI_MAINWINDOWLEADER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindowLeader
{
public:
    QFrame *frameWorkArea;
    QComboBox *comboBoxlab2;
    QComboBox *comboBoxlab;
    QComboBox *comboBoxtest;
    QComboBox *comboBoxtest2;
    QComboBox *comboBoxtest3;
    QPushButton *btnShowMatchingTemperament;
    QPushButton *btnLab;
    QPushButton *btnTest;
    QPushButton *btnSave;
    QLabel *label;

    void setupUi(QDialog *MainWindowLeader)
    {
        if (MainWindowLeader->objectName().isEmpty())
            MainWindowLeader->setObjectName("MainWindowLeader");
        MainWindowLeader->resize(800, 600);
        frameWorkArea = new QFrame(MainWindowLeader);
        frameWorkArea->setObjectName("frameWorkArea");
        frameWorkArea->setGeometry(QRect(10, 80, 501, 291));
        frameWorkArea->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6A5ACD, stop:1 #7B68EE);\n"
"    border-radius: 10px;\n"
"    border: 1px solid #6A5ACD;\n"
"}"));
        frameWorkArea->setFrameShape(QFrame::Shape::StyledPanel);
        frameWorkArea->setFrameShadow(QFrame::Shadow::Plain);
        comboBoxlab2 = new QComboBox(frameWorkArea);
        comboBoxlab2->setObjectName("comboBoxlab2");
        comboBoxlab2->setGeometry(QRect(20, 170, 461, 51));
        QFont font;
        font.setPointSize(22);
        comboBoxlab2->setFont(font);
        comboBoxlab2->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        comboBoxlab = new QComboBox(frameWorkArea);
        comboBoxlab->setObjectName("comboBoxlab");
        comboBoxlab->setEnabled(true);
        comboBoxlab->setGeometry(QRect(20, 80, 461, 51));
        comboBoxlab->setFont(font);
        comboBoxlab->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        comboBoxtest = new QComboBox(frameWorkArea);
        comboBoxtest->setObjectName("comboBoxtest");
        comboBoxtest->setGeometry(QRect(20, 40, 461, 51));
        comboBoxtest->setFont(font);
        comboBoxtest->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        comboBoxtest2 = new QComboBox(frameWorkArea);
        comboBoxtest2->setObjectName("comboBoxtest2");
        comboBoxtest2->setGeometry(QRect(20, 120, 461, 51));
        comboBoxtest2->setFont(font);
        comboBoxtest2->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        comboBoxtest3 = new QComboBox(frameWorkArea);
        comboBoxtest3->setObjectName("comboBoxtest3");
        comboBoxtest3->setGeometry(QRect(20, 200, 461, 51));
        comboBoxtest3->setFont(font);
        comboBoxtest3->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        btnShowMatchingTemperament = new QPushButton(frameWorkArea);
        btnShowMatchingTemperament->setObjectName("btnShowMatchingTemperament");
        btnShowMatchingTemperament->setGeometry(QRect(470, 10, 31, 31));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        btnShowMatchingTemperament->setIcon(icon);
        btnLab = new QPushButton(MainWindowLeader);
        btnLab->setObjectName("btnLab");
        btnLab->setGeometry(QRect(530, 120, 251, 71));
        QFont font1;
        font1.setPointSize(12);
        btnLab->setFont(font1);
        btnLab->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnTest = new QPushButton(MainWindowLeader);
        btnTest->setObjectName("btnTest");
        btnTest->setGeometry(QRect(530, 250, 251, 71));
        btnTest->setFont(font1);
        btnTest->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnSave = new QPushButton(MainWindowLeader);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(50, 410, 441, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(20);
        btnSave->setFont(font2);
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(MainWindowLeader);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 611, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(28);
        font3.setBold(true);
        label->setFont(font3);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        retranslateUi(MainWindowLeader);

        QMetaObject::connectSlotsByName(MainWindowLeader);
    } // setupUi

    void retranslateUi(QDialog *MainWindowLeader)
    {
        MainWindowLeader->setWindowTitle(QCoreApplication::translate("MainWindowLeader", "Dialog", nullptr));
        comboBoxlab2->setPlaceholderText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\203\321\216", nullptr));
        comboBoxlab->setPlaceholderText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        comboBoxtest->setPlaceholderText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        comboBoxtest2->setPlaceholderText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\265\320\274\321\203", nullptr));
        comboBoxtest3->setPlaceholderText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\276\321\206\320\265\320\275\320\272\321\203", nullptr));
        btnShowMatchingTemperament->setText(QString());
        btnLab->setText(QCoreApplication::translate("MainWindowLeader", "\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214 \320\273\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\203\321\216 \321\200\320\260\320\261\320\276\321\202\321\203", nullptr));
        btnTest->setText(QCoreApplication::translate("MainWindowLeader", "\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214 \320\277\321\200\320\276\320\262\320\265\321\200\320\276\321\207\320\275\321\203\321\216 \321\200\320\260\320\261\320\276\321\202\321\203", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindowLeader", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindowLeader", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowLeader: public Ui_MainWindowLeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWLEADER_H
