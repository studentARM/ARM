/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QLabel *questionLabel;
    QProgressBar *progressBar;
    QPushButton *answerButton1;
    QPushButton *answerButton2;
    QPushButton *answerButton3;
    QPushButton *answerButton4;
    QLabel *FinLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName("Test");
        Test->resize(772, 527);
        questionLabel = new QLabel(Test);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setGeometry(QRect(20, 80, 711, 111));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(20);
        font.setBold(true);
        questionLabel->setFont(font);
        questionLabel->setTabletTracking(false);
        questionLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    background-color: #4B0082; \n"
"    color: white;            \n"
"    border-radius: 10px;        \n"
"    padding: 8px 12px;      \n"
"    font-weight: bold;     \n"
"    border: 2px solid #9370DB; \n"
"}\n"
"qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255))"));
        questionLabel->setTextFormat(Qt::TextFormat::MarkdownText);
        questionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        questionLabel->setWordWrap(true);
        progressBar = new QProgressBar(Test);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 20, 251, 31));
        progressBar->setSizeIncrement(QSize(0, 0));
        progressBar->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(true);
        progressBar->setFont(font1);
        progressBar->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        progressBar->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        progressBar->setAutoFillBackground(false);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid rgb(255, 255, 255); \n"
"    background: r #9370DB;        \n"
"    border-radius: 7px;      \n"
"    height: 12px;            \n"
"    text-align: center;        \n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: rgb(226, 83, 255);  \n"
"    width: 3px;                /* \320\236\321\207\320\265\320\275\321\214 \321\203\320\267\320\272\320\270\320\265 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\321\213 */\n"
"    border-radius: 5px;        /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    margin: 0.3px;             /* \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\276\321\202\321\201\321\202\321\203\320\277 */\n"
"}"));
        progressBar->setMaximum(15);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Orientation::Horizontal);
        answerButton1 = new QPushButton(Test);
        answerButton1->setObjectName("answerButton1");
        answerButton1->setGeometry(QRect(20, 250, 341, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        answerButton1->setFont(font2);
        answerButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        answerButton2 = new QPushButton(Test);
        answerButton2->setObjectName("answerButton2");
        answerButton2->setGeometry(QRect(400, 250, 331, 81));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(16);
        font3.setBold(true);
        answerButton2->setFont(font3);
        answerButton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        answerButton3 = new QPushButton(Test);
        answerButton3->setObjectName("answerButton3");
        answerButton3->setGeometry(QRect(20, 370, 341, 81));
        answerButton3->setFont(font3);
        answerButton3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        answerButton4 = new QPushButton(Test);
        answerButton4->setObjectName("answerButton4");
        answerButton4->setGeometry(QRect(400, 370, 331, 81));
        answerButton4->setFont(font3);
        answerButton4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        FinLabel = new QLabel(Test);
        FinLabel->setObjectName("FinLabel");
        FinLabel->setGeometry(QRect(20, 130, 711, 151));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(25);
        font4.setBold(true);
        FinLabel->setFont(font4);
        FinLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        closeButton = new QPushButton(Test);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(452, 398, 271, 91));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        closeButton->setFont(font5);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QDialog *Test)
    {
        Test->setWindowTitle(QCoreApplication::translate("Test", "Dialog", nullptr));
        questionLabel->setText(QCoreApplication::translate("Test", "TextLabel", nullptr));
        progressBar->setFormat(QCoreApplication::translate("Test", "%v/30", nullptr));
        answerButton1->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        answerButton2->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        answerButton3->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        answerButton4->setText(QCoreApplication::translate("Test", "PushButton", nullptr));
        FinLabel->setText(QCoreApplication::translate("Test", "\320\236\320\277\321\200\320\276\321\201 \320\277\321\200\320\276\320\271\320\264\320\265\320\275", nullptr));
        closeButton->setText(QCoreApplication::translate("Test", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
