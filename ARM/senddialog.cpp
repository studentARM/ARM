#include "senddialog.h"
#include "ui_senddialog.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDebug>

SendDialog::SendDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SendDialog)
{
    ui->setupUi(this);
    loadLeaders();
    loadLabFiles();
}

SendDialog::~SendDialog()
{
    delete ui; // Удаляем UI при закрытии диалога
}

void SendDialog::loadLeaders()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "leaders_connection");
    db.setDatabaseName("database.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных");
        return;
    }

    QSqlQuery query(db);
    if (query.exec("SELECT name FROM leaders")) {
        while (query.next()) {
            ui->comboBoxLeaders->addItem(query.value(0).toString());
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить лидеров");
    }

    db.close();
    QSqlDatabase::removeDatabase("leaders_connection");
}

void SendDialog::loadLabFiles()
{
    QString labPath = QCoreApplication::applicationDirPath() + "/labs";
    QDir dir(labPath);
    QStringList labFiles = dir.entryList(QStringList() << "*.pdf", QDir::Files);

    ui->comboBoxLabs->addItems(labFiles);
}

void SendDialog::on_buttonBox_accepted()
{
    QString leader = ui->comboBoxLeaders->currentText();
    QString lab = ui->comboBoxLabs->currentText();
    QString filePath = QCoreApplication::applicationDirPath() + "/labs/" + lab;

    QMessageBox::information(this, "Отправка",
                             QString("Лабораторная работа \"%1\" отправлена лидеру \"%2\"\nПуть: %3")
                                 .arg(lab, leader, filePath));
}
