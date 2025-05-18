#ifndef GIVEFROMTEACHER_H
#define GIVEFROMTEACHER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QListWidgetItem>

namespace Ui {
class GiveFromTeacher;
}

class GiveFromTeacher : public QDialog
{
    Q_OBJECT

private slots:
    void on_Save_clicked();  // Слот для кнопки "Сохранить"


public:
    explicit GiveFromTeacher(QWidget *parent = nullptr);
    ~GiveFromTeacher();

private:
    Ui::GiveFromTeacher *ui;
    QSqlDatabase db;  // Объект базы данных
    void initDB();     // Инициализация БД и создание таблицы
    void loadLabs();   // Загрузка списка лаб из БД в QListWidget
    QRect originalGeometry;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);

};

#endif // GIVEFROMTEACHER_H
