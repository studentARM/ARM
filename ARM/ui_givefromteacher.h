/********************************************************************************
** Form generated from reading UI file 'givefromteacher.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIVEFROMTEACHER_H
#define UI_GIVEFROMTEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GiveFromTeacher
{
public:
    QListWidget *ListLabs;
    QPushButton *Save;
    QLabel *label;

    void setupUi(QDialog *GiveFromTeacher)
    {
        if (GiveFromTeacher->objectName().isEmpty())
            GiveFromTeacher->setObjectName("GiveFromTeacher");
        GiveFromTeacher->resize(800, 600);
        ListLabs = new QListWidget(GiveFromTeacher);
        ListLabs->setObjectName("ListLabs");
        ListLabs->setGeometry(QRect(110, 100, 591, 381));
        Save = new QPushButton(GiveFromTeacher);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(270, 500, 251, 71));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        Save->setFont(font);
        Save->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(GiveFromTeacher);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 731, 31));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        label->setFont(font1);

        retranslateUi(GiveFromTeacher);

        QMetaObject::connectSlotsByName(GiveFromTeacher);
    } // setupUi

    void retranslateUi(QDialog *GiveFromTeacher)
    {
        GiveFromTeacher->setWindowTitle(QCoreApplication::translate("GiveFromTeacher", "Dialog", nullptr));
        Save->setText(QCoreApplication::translate("GiveFromTeacher", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("GiveFromTeacher", "\320\236\321\202\320\274\320\265\321\202\321\214\321\202\320\265 \321\200\320\260\320\261\320\276\321\202\321\213, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\203\320\266\320\265 \320\262\321\213\320\264\320\260\320\275\321\213 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GiveFromTeacher: public Ui_GiveFromTeacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIVEFROMTEACHER_H
