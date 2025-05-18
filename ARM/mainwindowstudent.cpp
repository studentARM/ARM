#include "mainwindowstudent.h"
#include "ui_mainwindowstudent.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidgetItem>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QHeaderView>

extern QString g_userName;

MainWindowStudent::MainWindowStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindowStudent)
    , test(nullptr)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { background-image: url(:/resources/background.png); }");

    connect(ui->StartTest, &QPushButton::clicked, this, &MainWindowStudent::openTest);

    ui->welcomeLabel->setText("Добро пожаловать !");

    originalGeometry = ui->StartTest->geometry();
    ui->StartTest->installEventFilter(this);
    loadStudentData();
}

MainWindowStudent::~MainWindowStudent()
{
    delete ui;
}

void MainWindowStudent::openTest()
{
    test = new Test(this);
    test->show();
    ui->StartTest->setEnabled(false);
    ui->StartTest->setDisabled(true);
    ui->StartTest->setStyleSheet("QPushButton { background-color: #E6E6FA; }");
}

void MainWindowStudent::loadStudentData()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии БД:" << db.lastError().text();
        return;
    }

    // Проверка: прошёл ли студент опрос
    QSqlQuery surveyQuery;
    surveyQuery.prepare("SELECT COUNT(*) FROM survey_results WHERE full_name = :name AND survey_taken = 1");
    surveyQuery.bindValue(":name", g_userName);

    if (surveyQuery.exec() && surveyQuery.next()) {
        int count = surveyQuery.value(0).toInt();
        if (count > 0) {
            ui->StartTest->setEnabled(false);
            ui->StartTest->setDisabled(true);
            ui->StartTest->setStyleSheet("QPushButton { background-color: lightgray; }");
            qDebug() << "Опрос уже пройден, отключаем кнопку.";
        } else {
            qDebug() << "Опрос ещё не пройден.";
        }
    } else {
        qDebug() << "Ошибка запроса survey_results:" << surveyQuery.lastError().text();
    }

    // Таблица лабораторных работ
    ui->labsTable->setColumnCount(4);
    ui->labsTable->setHorizontalHeaderLabels(QStringList() << "Лабораторная работа" << "Отчёт" << "Код" << "UML-диаграмма");
    ui->labsTable->setRowCount(0);
    ui->labsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Устанавливаем режимы изменения размера по колонкам
    ui->labsTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // Первый столбец растягивается
    ui->labsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->labsTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->labsTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    QSqlQuery labQuery;
    labQuery.prepare(R"(
    SELECT
        c.name AS lab_name,
        IFNULL(l.has_report, 0) AS has_report,
        IFNULL(l.has_code, 0) AS has_code,
        IFNULL(l.has_diagram, 0) AS has_diagram
    FROM checklabs c
    LEFT JOIN labs l
        ON c.name = l.lab_name AND l.student_name = :name
    WHERE c.is_issued = 1
)");
    labQuery.bindValue(":name", g_userName);
    if (labQuery.exec()) {
        int row = 0;
        while (labQuery.next()) {
            ui->labsTable->insertRow(row);

            QString labName = labQuery.value(0).toString();
            bool hasReport = labQuery.value(1).toBool();
            bool hasCode = labQuery.value(2).toBool();
            bool hasDiagram = labQuery.value(3).toBool();

            ui->labsTable->setItem(row, 0, new QTableWidgetItem(labName));
            ui->labsTable->setItem(row, 1, createStatusItem(hasReport));
            ui->labsTable->setItem(row, 2, createStatusItem(hasCode));
            ui->labsTable->setItem(row, 3, createStatusItem(hasDiagram));

            // Подсветка строки в зависимости от количества сданных пунктов
            int passedCount = (hasReport ? 1 : 0) + (hasCode ? 1 : 0) + (hasDiagram ? 1 : 0);

            QColor bgColor;
            if (passedCount == 0) {
                bgColor = QColor(255, 0, 0); // красный
            } else if (passedCount < 3) {
                bgColor = QColor(255, 200, 0); // желтый
            } else {
                bgColor = QColor(0, 255, 0); // зеленый
            }

            for (int col = 0; col < 4; ++col) {
                ui->labsTable->item(row, col)->setBackground(bgColor);
            }

            row++;
        }
    }


    // Таблица тестов
    ui->testsTable->setColumnCount(2);
    ui->testsTable->setHorizontalHeaderLabels(QStringList() << "Тема" << "Оценка");
    ui->testsTable->setRowCount(0);
    ui->testsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->testsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery testQuery;
    testQuery.prepare("SELECT test_topic, grade FROM tests WHERE student_name = :name");
    testQuery.bindValue(":name", g_userName);

    if (testQuery.exec()) {
        int row = 0;
        while (testQuery.next()) {
            QString topic = testQuery.value(0).toString();
            QString gradeStr = testQuery.value(1).toString();
            int grade = gradeStr.toInt();  // преобразуем оценку в число

            QTableWidgetItem* topicItem = new QTableWidgetItem(topic);
            QTableWidgetItem* gradeItem = new QTableWidgetItem(gradeStr);

            // Выбор цвета в зависимости от оценки
            QColor bgColor;
            if (grade < 3) {
                bgColor = QColor(255, 0, 0); // красный
            } else if (grade < 5) {
                bgColor = QColor(255, 200, 0); // жёлтый
            } else {
                bgColor = QColor(0, 255, 0); // зелёный
            }

            // Устанавливаем цвет фона обеих ячеек
            topicItem->setBackground(bgColor);
            gradeItem->setBackground(bgColor);

            ui->testsTable->insertRow(row);
            ui->testsTable->setItem(row, 0, topicItem);
            ui->testsTable->setItem(row, 1, gradeItem);
            row++;
        }
    }


    db.close();
}

QTableWidgetItem* MainWindowStudent::createStatusItem(bool done) {
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    if (done) {
        item->setText("✓");
    } else {
        item->setText("✗");
    }
    return item;
}

void MainWindowStudent::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
{
    int w = baseGeometry.width();
    int h = baseGeometry.height();
    int x = baseGeometry.x();
    int y = baseGeometry.y();

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(150);
    animation->setEasingCurve(QEasingCurve::InOutQuad); // Плавная анимация
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

bool MainWindowStudent::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->StartTest && ui->StartTest->isEnabled()) {
        if (event->type() == QEvent::Enter) {
            animateButtonScale(ui->StartTest, 1.0, 1.1, originalGeometry);
            return true;
        } else if (event->type() == QEvent::Leave) {
            animateButtonScale(ui->StartTest, 1.1, 1.0, originalGeometry);
            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}


