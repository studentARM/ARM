/********************************************************************************
** Form generated from reading UI file 'mainwindowstudent.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWSTUDENT_H
#define UI_MAINWINDOWSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowStudent
{
public:
    QPushButton *StartTest;
    QLabel *welcomeLabel;
    QTableWidget *testsTable;
    QTableWidget *labsTable;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *MainWindowStudent)
    {
        if (MainWindowStudent->objectName().isEmpty())
            MainWindowStudent->setObjectName("MainWindowStudent");
        MainWindowStudent->resize(878, 600);
        MainWindowStudent->setStyleSheet(QString::fromUtf8(""));
        StartTest = new QPushButton(MainWindowStudent);
        StartTest->setObjectName("StartTest");
        StartTest->setGeometry(QRect(20, 510, 201, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(18);
        font.setBold(true);
        StartTest->setFont(font);
        StartTest->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        StartTest->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        StartTest->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        StartTest->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        welcomeLabel = new QLabel(MainWindowStudent);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(50, 20, 761, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        welcomeLabel->setFont(font1);
        welcomeLabel->setStyleSheet(QString::fromUtf8(""));
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        testsTable = new QTableWidget(MainWindowStudent);
        testsTable->setObjectName("testsTable");
        testsTable->setGeometry(QRect(10, 210, 411, 221));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(12);
        font2.setBold(true);
        testsTable->setFont(font2);
        testsTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	background-color: #f0f0f0;\n"
"}"));
        labsTable = new QTableWidget(MainWindowStudent);
        labsTable->setObjectName("labsTable");
        labsTable->setGeometry(QRect(450, 210, 411, 221));
        labsTable->setFont(font2);
        labsTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	background-color: #f0f0f0;\n"
"}"));
        label = new QLabel(MainWindowStudent);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 140, 331, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(22);
        font3.setBold(true);
        label->setFont(font3);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(MainWindowStudent);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 140, 321, 41));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(MainWindowStudent);

        QMetaObject::connectSlotsByName(MainWindowStudent);
    } // setupUi

    void retranslateUi(QDialog *MainWindowStudent)
    {
        MainWindowStudent->setWindowTitle(QCoreApplication::translate("MainWindowStudent", "Dialog", nullptr));
        StartTest->setText(QCoreApplication::translate("MainWindowStudent", "\320\242\320\265\321\201\321\202", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindowStudent", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindowStudent", "\320\237\321\200\320\276\320\262\320\265\321\200\320\276\321\207\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowStudent", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\321\213\320\265 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowStudent: public Ui_MainWindowStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWSTUDENT_H
