#include "arm.h"
#include "ui_arm.h"
#include "loginwindow.h"

#include <QPropertyAnimation>
ARM::ARM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ARM)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow { background-image: url(:/resources/background.png); }");

    // Сохраняем начальную геометрию кнопок
    originalGeometryStudent = ui->btnStudent->geometry();
    originalGeometryLeader = ui->btnLeader->geometry();
    originalGeometryTeacher = ui->btnTeacher->geometry();

    // Устанавливаем фильтры событий для кнопок
    ui->btnStudent->installEventFilter(this);
    ui->btnLeader->installEventFilter(this);
    ui->btnTeacher->installEventFilter(this);
}

ARM::~ARM()
{
    delete ui;
}

void ARM::on_btnStudent_clicked()
{
    LoginWindow *login = new LoginWindow("student", this, this);
    login->exec();
}

void ARM::on_btnLeader_clicked()
{
    LoginWindow *login = new LoginWindow("leader", this, this);
    login->exec();
}

void ARM::on_btnTeacher_clicked()
{
    LoginWindow *login = new LoginWindow("teacher", this, this);
    login->exec();
}

void ARM::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
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

bool ARM::eventFilter(QObject *watched, QEvent *event)
{
    // Обрабатываем события для кнопок
    if (watched == ui->btnLeader|| watched == ui->btnStudent || watched == ui->btnTeacher) {
        if (event->type() == QEvent::Enter) {
            // При наведении на кнопку увеличиваем ее размер
            if (watched == ui->btnLeader)
                animateButtonScale(ui->btnLeader, 1.0, 1.1, originalGeometryLeader);
            else if (watched == ui->btnStudent)
                animateButtonScale(ui->btnStudent, 1.0, 1.1, originalGeometryStudent);
            else if (watched == ui->btnTeacher)
                animateButtonScale(ui->btnTeacher, 1.0, 1.1, originalGeometryTeacher);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // При уходе курсора с кнопки восстанавливаем ее размер
            if (watched == ui->btnLeader)
                animateButtonScale(ui->btnLeader, 1.1, 1.0, originalGeometryLeader);
            else if (watched == ui->btnStudent)
                animateButtonScale(ui->btnStudent, 1.1, 1.0, originalGeometryStudent);
            else if (watched == ui->btnTeacher)
                animateButtonScale(ui->btnTeacher, 1.1, 1.0, originalGeometryTeacher);
            return true;
        }
    }

    return QObject::eventFilter(watched, event);
}
