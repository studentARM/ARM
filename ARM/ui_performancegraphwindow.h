/********************************************************************************
** Form generated from reading UI file 'performancegraphwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFORMANCEGRAPHWINDOW_H
#define UI_PERFORMANCEGRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PerformanceGraphWindow
{
public:
    QWidget *plotContainer;
    QLabel *label;

    void setupUi(QDialog *PerformanceGraphWindow)
    {
        if (PerformanceGraphWindow->objectName().isEmpty())
            PerformanceGraphWindow->setObjectName("PerformanceGraphWindow");
        PerformanceGraphWindow->resize(754, 556);
        plotContainer = new QWidget(PerformanceGraphWindow);
        plotContainer->setObjectName("plotContainer");
        plotContainer->setGeometry(QRect(20, 100, 711, 401));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(12);
        font.setBold(true);
        plotContainer->setFont(font);
        label = new QLabel(PerformanceGraphWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 661, 71));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(PerformanceGraphWindow);

        QMetaObject::connectSlotsByName(PerformanceGraphWindow);
    } // setupUi

    void retranslateUi(QDialog *PerformanceGraphWindow)
    {
        PerformanceGraphWindow->setWindowTitle(QCoreApplication::translate("PerformanceGraphWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PerformanceGraphWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PerformanceGraphWindow: public Ui_PerformanceGraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFORMANCEGRAPHWINDOW_H
