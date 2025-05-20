/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLineEdit *name;
    QLineEdit *password;
    QLabel *label_2;
    QComboBox *group;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnLogin;
    QLabel *label_5;
    QLineEdit *email;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 150, 71, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label->setFont(font);
        name = new QLineEdit(LoginWindow);
        name->setObjectName("name");
        name->setGeometry(QRect(230, 150, 401, 61));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        name->setFont(font1);
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #EE82EE;  /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border: 2px solid #8B008B;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: hsl(300, 76%, 85%);  /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border-color: #BA55D3;  /* MediumOrchid */\n"
"}"));
        password = new QLineEdit(LoginWindow);
        password->setObjectName("password");
        password->setGeometry(QRect(230, 330, 401, 61));
        password->setFont(font1);
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #EE82EE;  /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border: 2px solid #8B008B;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: hsl(300, 76%, 85%);  /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border-color: #BA55D3;  /* MediumOrchid */\n"
"}"));
        password->setEchoMode(QLineEdit::EchoMode::Password);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 320, 111, 51));
        label_2->setFont(font);
        group = new QComboBox(LoginWindow);
        group->setObjectName("group");
        group->setGeometry(QRect(230, 420, 401, 61));
        QFont font2;
        font2.setBold(false);
        group->setFont(font2);
        group->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #EE82EE;\n"
"    border: 2px solid #8B008B;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\262 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\274 \320\262\320\270\320\264\320\266\320\265\321\202\320\265 */\n"
"    font-size: 20px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #F5B0F5;\n"
"    border-color: #BA55D3;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\321\214 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #EE82EE; /* \320\244\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 \321\204\320\276\320\275 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: white;             /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320"
                        "\272\321\201\321\202 */\n"
"    border: 1px solid #8B008B;\n"
"    border-radius: 5px;\n"
"    selection-background-color: #BA55D3; /* \320\246\320\262\320\265\321\202 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\263\320\276 \320\277\321\203\320\275\320\272\321\202\320\260 */\n"
"    outline: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\277\321\203\320\275\320\272\321\202\320\270\321\200\320\275\321\203\321\216 \321\200\320\260\320\274\320\272\321\203 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"}\n"
"\n"
"/* \320\241\321\202\321\200\320\265\320\273\320\272\320\260 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right center;\n"
"    width: 20px;\n"
"    border-left: 1px solid #8B008B;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow_down_white.png); /* \320\221\320\265"
                        "\320\273\320\260\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\260 (\320\276\320\277\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\276) */\n"
"}"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 420, 101, 51));
        label_3->setFont(font);
        label_4 = new QLabel(LoginWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 20, 521, 81));
        QFont font3;
        font3.setPointSize(48);
        font3.setBold(true);
        label_4->setFont(font3);
        btnLogin = new QPushButton(LoginWindow);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(320, 500, 191, 81));
        QFont font4;
        font4.setPointSize(22);
        btnLogin->setFont(font4);
        btnLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_5 = new QLabel(LoginWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 240, 111, 51));
        label_5->setFont(font);
        email = new QLineEdit(LoginWindow);
        email->setObjectName("email");
        email->setGeometry(QRect(230, 240, 401, 61));
        email->setFont(font1);
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #EE82EE;  /* \320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border: 2px solid #8B008B;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: hsl(300, 76%, 85%);  /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\270\320\276\320\273\320\265\321\202\320\276\320\262\321\213\320\271 */\n"
"    border-color: #BA55D3;  /* MediumOrchid */\n"
"}"));
        email->setEchoMode(QLineEdit::EchoMode::Normal);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\320\244\320\230\320\236", nullptr));
        password->setText(QString());
        label_2->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        group->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\263\321\200\321\203\320\277\320\277\321\203...", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        email->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
