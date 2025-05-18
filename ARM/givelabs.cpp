#include "givelabs.h"
#include "ui_givelabs.h"

#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

GiveLabs::GiveLabs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GiveLabs)
{
    ui->setupUi(this);

    // Загружаем список лабораторных
    loadLabs();

    // Подключаем кнопку сохранения
    connect(ui->Give, &QPushButton::clicked, this, &GiveLabs::onGiveClicked);
}

GiveLabs::~GiveLabs()
{
    delete ui;
}

void createLabsDatabase()
{
    // Создаем подключение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    // Проверяем, открыта ли база данных
    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных: " << db.lastError().text();
        return;
    }

    // Создаем таблицу для лабораторных работ
    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS labs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            lab_name TEXT NOT NULL,
            is_given BOOLEAN NOT NULL DEFAULT 0
        );
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Ошибка создания таблицы лабораторных: " << query.lastError().text();
    }

    db.close();
}

void fillLabsDatabase()
{
    // Создаем подключение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    // Проверяем, открыта ли база данных
    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных: " << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QStringList labs = {"Лабораторная 1", "Лабораторная 2", "Лабораторная 3", "Лабораторная 4"};

    // Добавляем лабораторные в таблицу
    for (const QString &lab : labs) {
        query.prepare("INSERT INTO labs (lab_name, is_given) VALUES (:lab_name, 0)");
        query.bindValue(":lab_name", lab);
        if (!query.exec()) {
            qDebug() << "Ошибка добавления лабораторной работы: " << query.lastError().text();
        }
    }

    db.close();
}

void GiveLabs::loadLabs()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных: " << db.lastError().text();
        return;
    }

    // Запрос на получение всех лабораторных работ
    QSqlQuery query("SELECT id, lab_name, is_given FROM labs");

    // Добавляем лабораторные работы в интерфейс
    int row = 0;
    while (query.next()) {
        QString labName = query.value("lab_name").toString();
        bool isGiven = query.value("is_given").toBool();

        // Создаем чекбокс для каждой лабораторной
        QCheckBox *checkBox = new QCheckBox(labName);
        checkBox->setChecked(isGiven);  // Устанавливаем галочку, если лабораторная уже выдана

        // Добавляем чекбокс в макет
        scrollLayout->addWidget(checkBox);

        // Сохраняем связь с ID лабораторной
        labCheckBoxes.insert(query.value("id").toInt(), checkBox);
    }

    db.close();
}

void GiveLabs::onGiveClicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Не удалось открыть базу данных: " << db.lastError().text();
        return;
    }

    QSqlQuery query;
    for (auto it = labCheckBoxes.begin(); it != labCheckBoxes.end(); ++it) {
        int labId = it.key();
        bool isGiven = it.value()->isChecked();

        // Обновляем статус в базе данных
        query.prepare("UPDATE labs SET is_given = :is_given WHERE id = :id");
        query.bindValue(":is_given", isGiven);
        query.bindValue(":id", labId);
        if (!query.exec()) {
            qDebug() << "Ошибка обновления статуса лабораторной: " << query.lastError().text();
        }
    }

    db.close();
}
