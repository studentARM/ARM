/********************************************************************************
** Form generated from reading UI file 'temperamentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERAMENTDIALOG_H
#define UI_TEMPERAMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_TemperamentDialog
{
public:
    QListWidget *listWidgetStudents;
    QLabel *labelTitle;

    void setupUi(QDialog *TemperamentDialog)
    {
        if (TemperamentDialog->objectName().isEmpty())
            TemperamentDialog->setObjectName("TemperamentDialog");
        TemperamentDialog->resize(498, 399);
        listWidgetStudents = new QListWidget(TemperamentDialog);
        listWidgetStudents->setObjectName("listWidgetStudents");
        listWidgetStudents->setGeometry(QRect(30, 81, 441, 281));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(14);
        font.setBold(true);
        listWidgetStudents->setFont(font);
        listWidgetStudents->setStyleSheet(QString::fromUtf8("background-color: #DDA0DD;"));
        labelTitle = new QLabel(TemperamentDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(2, 20, 491, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        labelTitle->setFont(font1);
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TemperamentDialog);

        QMetaObject::connectSlotsByName(TemperamentDialog);
    } // setupUi

    void retranslateUi(QDialog *TemperamentDialog)
    {
        TemperamentDialog->setWindowTitle(QCoreApplication::translate("TemperamentDialog", "Dialog", nullptr));
        labelTitle->setText(QCoreApplication::translate("TemperamentDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemperamentDialog: public Ui_TemperamentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERAMENTDIALOG_H
