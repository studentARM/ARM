#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindowstudent.h"
#include "mainwindowteacher.h"
#include "mainwindowleader.h"

#include "global.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QPropertyAnimation>

LoginWindow::LoginWindow(const QString &role, QWidget *parent, QWidget *armWindow)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
    , currentRole(role)
    , armWindow(armWindow)  // Получаем указатель на ARM окно
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { background-image: url(:/resources/background.png); }");
    setupUIForRole();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        return;
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "name TEXT, "
                   "password TEXT, "
                   "email TEXT, "
                   "groupname TEXT, "
                   "role TEXT)");
    }

    QSqlQuery checkQuery;
    checkQuery.exec("PRAGMA table_info(users)");
    bool emailExists = false;

    while (checkQuery.next()) {
        if (checkQuery.value(1).toString() == "email") {
            emailExists = true;
            break;
        }
    }

    if (!emailExists) {
        QSqlQuery alterQuery;
        alterQuery.exec("ALTER TABLE users ADD COLUMN email TEXT");
    }

    originalGeometry = ui->btnLogin->geometry();
    ui->btnLogin->installEventFilter(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::setupUIForRole()
{
    if (currentRole == "teacher") {
        ui->group->hide();
        ui->label_3->hide();
        ui->email->setPlaceholderText("Введите ваш рабочий email");
    } else {
        ui->group->show();
        ui->group->addItems({"РИС-24-1б", "РИС-24-2б", "РИС-24-3б", "ИВТ-24-1б", "ИВТ-24-2б"});
        ui->email->setPlaceholderText("Введите ваш email");
    }
}



void LoginWindow::on_btnLogin_clicked()
{
    // Получаем данные из полей ввода
    QString name = ui->name->text().trimmed();
    QString password = ui->password->text();
    QString email = ui->email->text().trimmed(); // Добавляем email
    QString group = ui->group->currentText();

    // Проверка заполнения обязательных полей
    if (name.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля");
        return;
    }

    // Базовая валидация email
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректный email");
        return;
    }

    // Сохраняем данные пользователя в глобальные переменные
    g_userName = name;
    g_userEmail = email;

    QSqlQuery query;
    query.prepare("SELECT id, password, email FROM users WHERE name = :name AND role = :role");
    query.bindValue(":name", name);
    query.bindValue(":role", currentRole);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Пользователь существует - проверяем пароль
        QString storedPassword = query.value("password").toString();
        QString storedEmail = query.value("email").toString();

        if (storedPassword != password) {
            QMessageBox::critical(this, "Ошибка", "Неверный пароль");
            return;
        }

        // Обновляем email если он изменился
        if (storedEmail != email) {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE users SET email = :email WHERE name = :name AND role = :role");
            updateQuery.bindValue(":email", email);
            updateQuery.bindValue(":name", name);
            updateQuery.bindValue(":role", currentRole);
            updateQuery.exec();
        }

        // Успешная авторизация
        QMessageBox::information(this, "Успех", "Добро пожаловать, " + name);

        // Закрываем окно ARM, если оно было передано
        if (armWindow) {
            armWindow->close();
        }

        // Открываем соответствующее окно в зависимости от роли
        if (currentRole == "teacher") {
            MainWindowTeacher *teacherWindow = new MainWindowTeacher();
            teacherWindow->show();
        } else if (currentRole == "student") {
            MainWindowStudent *studentWindow = new MainWindowStudent();
            studentWindow->show();
        } else if (currentRole == "leader") {
            MainWindowLeader *leaderWindow = new MainWindowLeader();
            leaderWindow->show();
        }

        this->close();
    } else {
        // Пользователь не существует - регистрируем нового
        query.prepare("INSERT INTO users (name, password, email, groupname, role) "
                      "VALUES (:name, :password, :email, :group, :role)");
        query.bindValue(":name", name);
        query.bindValue(":password", password);
        query.bindValue(":email", email);
        query.bindValue(":group", (currentRole == "teacher") ? QVariant() : group);
        query.bindValue(":role", currentRole);

        if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка", "Ошибка записи в БД: " + query.lastError().text());
            return;
        }

        QMessageBox::information(this, "Успех", "Пользователь добавлен");

        if (armWindow) {
            armWindow->close();
        }

        if (currentRole == "teacher") {
            MainWindowTeacher *teacherWindow = new MainWindowTeacher();
            teacherWindow->show();
        } else if (currentRole == "student") {
            MainWindowStudent *studentWindow = new MainWindowStudent();
            studentWindow->show();
        } else if (currentRole == "leader") {
            MainWindowLeader *leaderWindow = new MainWindowLeader();
            leaderWindow->show();
        }

        this->close();
    }
}

void LoginWindow::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
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

bool LoginWindow::eventFilter(QObject *watched, QEvent *event)
{
    // Обрабатываем события для кнопок
    if (watched == ui->btnLogin) {
        if (event->type() == QEvent::Enter) {
            // При наведении на кнопку увеличиваем ее размер
            if (watched == ui->btnLogin)
                animateButtonScale(ui->btnLogin, 1.0, 1.1, originalGeometry);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // При уходе курсора с кнопки восстанавливаем ее размер
            if (watched == ui->btnLogin)
                animateButtonScale(ui->btnLogin, 1.1, 1.0, originalGeometry);
            return true;
        }
    }

    return QObject::eventFilter(watched, event);
}
