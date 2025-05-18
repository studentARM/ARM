#include "givefromteacher.h"
#include "ui_givefromteacher.h"

#include <QMessageBox>
#include <QCheckBox>
#include <QPropertyAnimation>

GiveFromTeacher::GiveFromTeacher(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GiveFromTeacher)
{
    ui->setupUi(this);

    this->setStyleSheet("GiveFromTeacher { background-image: url(:/resources/background.png); }");

    // Инициализация БД
    initDB();

    // Загрузка лабораторных работ в список
    loadLabs();

    // Сохраняем начальную геометрию кнопок
    originalGeometry = ui->Save->geometry();

    // Устанавливаем фильтры событий для кнопок
    ui->Save->installEventFilter(this);

   // Жесткий сброс всех стилей
        ui->ListLabs->setStyleSheet("");

    QString listStyle =
        "QListWidget {"
        "    background-color: #DDA0DD;"
        "    font-size: 14pt;"
        "}"
        "QListWidget::item {"
        "    height: 40px;"
        "    background: #DDA0DD;"
        "}"
        "QListWidget::item:hover {"
        "    background: #EE82EE;"  // Фиолетовый при наведении
        "}";

    // Стиль для чекбоксов
    QString checkboxStyle =
        "QCheckBox {"
        "    spacing: 15px;"
        "    color: black;"
        "    font-size: 14pt;"
        "}"
        "QCheckBox::indicator {"
        "    width: 28px;"
        "    height: 28px;"
        "    border: 2px solid #5A5A5A;"
        "    border-radius: 3px;"
        "    background: white;"
        "}"
        "QCheckBox::indicator:checked {"
        "    background: #9932CC;"
        "}";

    // Применяем комбинированный стиль
    ui->ListLabs->setStyleSheet(listStyle + checkboxStyle);


    QFont font;
    font.setPointSize(14);
    ui->ListLabs->setFont(font);


    for(int i = 0; i < ui->ListLabs->count(); ++i) {
        QListWidgetItem* item = ui->ListLabs->item(i);
        if(QCheckBox* cb = qobject_cast<QCheckBox*>(ui->ListLabs->itemWidget(item))) {
            cb->setStyleSheet(checkboxStyle);
            cb->setFont(font);
        }
    }


}

GiveFromTeacher::~GiveFromTeacher()
{
    db.close();  // Закрываем БД при закрытии окна
    delete ui;

}

void GiveFromTeacher::initDB()
{
    // Подключаемся к SQLite (файл users.db в папке проекта)
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть базу данных!");
        return;
    }

    // Создаем таблицу checklabs, если её нет
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS checklabs ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT NOT NULL,"
               "is_issued BOOLEAN NOT NULL DEFAULT 0)");  // 0 — не выдана, 1 — выдана

    // Если таблица пустая, добавляем тестовые данные
    query.exec("SELECT COUNT(*) FROM checklabs");
    if (query.next() && query.value(0).toInt() == 0) {
        query.exec("INSERT INTO checklabs (name, is_issued) VALUES ('Лабораторная работа 1', 0)");
        query.exec("INSERT INTO checklabs (name, is_issued) VALUES ('Лабораторная работа 2', 0)");
        query.exec("INSERT INTO checklabs (name, is_issued) VALUES ('Лабораторная работа 3', 0)");
    }
}

void GiveFromTeacher::loadLabs()
{
    ui->ListLabs->clear();

    QSqlQuery query("SELECT name, is_issued FROM checklabs");
    while (query.next()) {
        QString labName = query.value(0).toString();
        bool isIssued = query.value(1).toBool();

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(100, 40));  // Фиксированная высота

        QCheckBox *checkBox = new QCheckBox(labName);
        checkBox->setChecked(isIssued);

        // Шрифт всегда жирный
        QFont font = checkBox->font();
        font.setBold(true);
        checkBox->setFont(font);

        ui->ListLabs->addItem(item);
        ui->ListLabs->setItemWidget(item, checkBox);
    }
}

void GiveFromTeacher::on_Save_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE checklabs SET is_issued = ? WHERE name = ?");

    for (int i = 0; i < ui->ListLabs->count(); ++i) {
        QListWidgetItem *item = ui->ListLabs->item(i);
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->ListLabs->itemWidget(item));

        if (checkBox) {
            QString labName = checkBox->text();
            bool isIssued = checkBox->isChecked();

            query.addBindValue(isIssued ? 1 : 0);
            query.addBindValue(labName);
            query.exec();
        }
    }

    QMessageBox::information(this, "Успех", "Состояние лабораторных работ сохранено!");
}

void GiveFromTeacher::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
{
    int w = baseGeometry.width();
    int h = baseGeometry.height();
    int x = baseGeometry.x();
    int y = baseGeometry.y();

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(150);
    animation->setStartValue(QRect(x - (w * (start - 1) / 2),
                                   y - (h * (start - 1) / 2),
                                   w * start,
                                   h * start));
    animation->setEndValue(QRect(x - (w * (end - 1) / 2),
                                 y - (h * (end - 1) / 2),
                                 w * end,
                                 h * end));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

bool GiveFromTeacher::eventFilter(QObject *watched, QEvent *event)
{
    // Только для кнопки Save
    if (watched == ui->Save) {
        if (event->type() == QEvent::Enter) {
            animateButtonScale(ui->Save, 1.0, 1.1, originalGeometry);
            return true;
        } else if (event->type() == QEvent::Leave) {
            animateButtonScale(ui->Save, 1.1, 1.0, originalGeometry);
            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}
