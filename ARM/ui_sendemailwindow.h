/********************************************************************************
** Form generated from reading UI file 'sendemailwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDEMAILWINDOW_H
#define UI_SENDEMAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SendEmailWindow
{
public:
    QLabel *fileLabel;
    QPushButton *selectFileButton;
    QPushButton *sendButton;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *Text;
    QComboBox *studentComboBox;

    void setupUi(QDialog *SendEmailWindow)
    {
        if (SendEmailWindow->objectName().isEmpty())
            SendEmailWindow->setObjectName("SendEmailWindow");
        SendEmailWindow->resize(639, 344);
        fileLabel = new QLabel(SendEmailWindow);
        fileLabel->setObjectName("fileLabel");
        fileLabel->setGeometry(QRect(170, 220, 291, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        font.setBold(true);
        fileLabel->setFont(font);
        fileLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        selectFileButton = new QPushButton(SendEmailWindow);
        selectFileButton->setObjectName("selectFileButton");
        selectFileButton->setGeometry(QRect(20, 270, 231, 51));
        selectFileButton->setFont(font);
        selectFileButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        sendButton = new QPushButton(SendEmailWindow);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(380, 270, 231, 51));
        sendButton->setFont(font);
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(SendEmailWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 19, 261, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(SendEmailWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 80, 261, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Text = new QTextEdit(SendEmailWindow);
        Text->setObjectName("Text");
        Text->setGeometry(QRect(113, 114, 411, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto")});
        font1.setPointSize(9);
        font1.setBold(true);
        Text->setFont(font1);
        Text->setStyleSheet(QString::fromUtf8("QTextEdit \n"
"{\n"
"	background-color: #f0f0f0;\n"
"	color: #000000;\n"
"}"));
        studentComboBox = new QComboBox(SendEmailWindow);
        studentComboBox->setObjectName("studentComboBox");
        studentComboBox->setGeometry(QRect(111, 50, 421, 28));

        retranslateUi(SendEmailWindow);

        QMetaObject::connectSlotsByName(SendEmailWindow);
    } // setupUi

    void retranslateUi(QDialog *SendEmailWindow)
    {
        SendEmailWindow->setWindowTitle(QCoreApplication::translate("SendEmailWindow", "Dialog", nullptr));
        fileLabel->setText(QCoreApplication::translate("SendEmailWindow", "\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));
        selectFileButton->setText(QCoreApplication::translate("SendEmailWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        sendButton->setText(QCoreApplication::translate("SendEmailWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label->setText(QCoreApplication::translate("SendEmailWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("SendEmailWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendEmailWindow: public Ui_SendEmailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDEMAILWINDOW_H
