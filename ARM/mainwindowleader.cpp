#include "mainwindowleader.h"
#include "ui_mainwindowleader.h"
#include "global.h"
#include "temperamentdialog.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QListWidget>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QEvent>
#include <QGraphicsScale>
#include <QGraphicsTransform>
#include <QGraphicsProxyWidget>
#include <QGraphicsEffect>
#include <QDialog>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDialogButtonBox>

MainWindowLeader::MainWindowLeader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindowLeader)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        return;
    } else {
        // Создание таблицы labs
        QSqlQuery query;
        QString createLabsTable =
            "CREATE TABLE IF NOT EXISTS labs ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "student_name TEXT, "
            "lab_name TEXT, "
            "has_report INTEGER DEFAULT 0, "
            "has_diagram INTEGER DEFAULT 0, "
            "has_code INTEGER DEFAULT 0, "
            "UNIQUE(student_name, lab_name))";

        query.exec(createLabsTable);

        // Создание таблицы tests
        QString createTestsTable =
            "CREATE TABLE IF NOT EXISTS tests ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "student_name TEXT, "
            "test_topic TEXT, "
            "grade TEXT)";

        query.exec(createTestsTable);
    }

    ui->comboBoxtest->setVisible(false);
    ui->comboBoxtest2->setVisible(false);
    ui->comboBoxtest3->setVisible(false);
    fillStudentComboBox();  //  Заполняем первый комбобокс именами студентов
    fillLabComboBox();      //  Заполняем второй комбобокс лабораторными работами
    connect(ui->comboBoxlab2, QOverload<const QString &>::of(&QComboBox::currentTextChanged),
            this, &MainWindowLeader::onLabSelected);
    fillTestComboBoxes();

    // Сохраняем начальные размеры кнопок
    originalGeometry = ui->btnSave->geometry();
    originalGeometryLab = ui->btnLab->geometry();
    originalGeometryTest = ui->btnTest->geometry();

    // Устанавливаем фильтр событий на кнопки
    ui->btnSave->installEventFilter(this);
    ui->btnLab->installEventFilter(this);
    ui->btnTest->installEventFilter(this);

    // Сохраняем исходные размеры комбобоксов
    originalGeometryComboLab = ui->comboBoxlab->geometry();
    originalGeometryComboLab2 = ui->comboBoxlab2->geometry();
    originalGeometryComboTest1 = ui->comboBoxtest->geometry();
    originalGeometryComboTest2 = ui->comboBoxtest2->geometry();
    originalGeometryComboTest3 = ui->comboBoxtest3->geometry();

    // Устанавливаем фильтр событий для комбобоксов
    ui->comboBoxlab->installEventFilter(this);
    ui->comboBoxlab2->installEventFilter(this);
    ui->comboBoxtest->installEventFilter(this);
    ui->comboBoxtest2->installEventFilter(this);
    ui->comboBoxtest3->installEventFilter(this);

    this->setStyleSheet("MainWindowLeader { background-image: url(:/resources/background.png); }");

    connect(ui->btnShowMatchingTemperament, &QPushButton::clicked,
            this, &MainWindowLeader::on_btnShowMatchingTemperament_clicked);
    ui->btnShowMatchingTemperament->setStyleSheet("");
    ui->btnShowMatchingTemperament->setStyleSheet("background: transparent; border: none;");

}

MainWindowLeader::~MainWindowLeader()
{
    delete ui;
}

void MainWindowLeader::on_btnShowMatchingTemperament_clicked()
{
    QString currentUserName = g_userName;
    if (currentUserName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пользователь не авторизован.");
        return;
    }

    // Получаем темперамент текущего пользователя
    QString currentUserTemperament;
    QSqlQuery query;
    query.prepare("SELECT temperament FROM survey_results WHERE full_name = ?");
    query.addBindValue(currentUserName);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить темперамент пользователя.");
        return;
    }
    currentUserTemperament = query.value(0).toString();

    // Ищем студентов с таким же темпераментом
    query.prepare("SELECT full_name FROM survey_results WHERE temperament = ?");
    query.addBindValue(currentUserTemperament);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при поиске студентов: " + query.lastError().text());
        return;
    }

    QStringList matchingStudents;
    while (query.next()) {
        QString studentName = query.value(0).toString();
        if (studentName != currentUserName)
            matchingStudents << studentName;
    }

    TemperamentDialog dlg(currentUserTemperament, matchingStudents, this);
    dlg.exec();
}


void MainWindowLeader::onLabSelected(const QString &labName)
{
    if (ui->comboBoxlab->currentText().isEmpty() || labName.isEmpty())
        return;

    showCheckboxDialog(ui->comboBoxlab->currentText(), labName);
}

void MainWindowLeader::showCheckboxDialog(const QString &studentName, const QString &labName)
{
    if (studentName.isEmpty() || labName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Не указаны студент или работа!");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Детали лабораторной работы");

    QCheckBox *reportCheck = new QCheckBox("Наличие отчета", &dialog);
    QCheckBox *diagramCheck = new QCheckBox("Наличие диаграммы классов", &dialog);
    QCheckBox *codeCheck = new QCheckBox("Наличие кода программы", &dialog);

    // Загрузка текущих значений
    QSqlQuery loadQuery;
    loadQuery.prepare("SELECT has_report, has_diagram, has_code FROM labs "
                      "WHERE student_name = ? AND lab_name = ?");
    loadQuery.addBindValue(studentName);
    loadQuery.addBindValue(labName);

    if (loadQuery.exec() && loadQuery.next()) {
        reportCheck->setChecked(loadQuery.value(0).toBool());
        diagramCheck->setChecked(loadQuery.value(1).toBool());
        codeCheck->setChecked(loadQuery.value(2).toBool());
    }

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(reportCheck);
    layout->addWidget(diagramCheck);
    layout->addWidget(codeCheck);

    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QSqlQuery saveQuery;
        saveQuery.prepare("INSERT OR REPLACE INTO labs "
                          "(student_name, lab_name, has_report, has_diagram, has_code) "
                          "VALUES (?, ?, ?, ?, ?)");
        saveQuery.addBindValue(studentName);
        saveQuery.addBindValue(labName);
        saveQuery.addBindValue(reportCheck->isChecked() ? 1 : 0);
        saveQuery.addBindValue(diagramCheck->isChecked() ? 1 : 0);
        saveQuery.addBindValue(codeCheck->isChecked() ? 1 : 0);

        if (!saveQuery.exec()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные");
        }
    }
}


void MainWindowLeader::on_btnLab_clicked()
{
    // Показываем комбобоксы для лабораторной
    ui->comboBoxlab->setVisible(true);
    ui->comboBoxlab2->setVisible(true);

    // Скрываем комбобоксы для проверочной
    ui->comboBoxtest->setVisible(false);
    ui->comboBoxtest2->setVisible(false);
    ui->comboBoxtest3->setVisible(false);

    ui->label->setText("Отметьте лабораторную работу");
    // Показываем кнопку сохранения
    ui->btnSave->setVisible(true);
}

void MainWindowLeader::on_btnTest_clicked()
{
    // Показываем комбобоксы для проверочной
    ui->comboBoxtest->setVisible(true);
    ui->comboBoxtest2->setVisible(true);
    ui->comboBoxtest3->setVisible(true);

    // Скрываем комбобоксы для лабораторной
    ui->comboBoxlab->setVisible(false);
    ui->comboBoxlab2->setVisible(false);

    ui->label->setText("Отметьте проверочную работу");
    // Показываем кнопку сохранения
    ui->btnSave->setVisible(true);
}

void MainWindowLeader::fillStudentComboBox()
{
    QSqlQuery query;
    query.prepare("SELECT name FROM users WHERE role = 'student' OR role = 'leader'");

    if (query.exec()) {
        while (query.next()) {
            QString studentName = query.value(0).toString();
            ui->comboBoxlab->addItem(studentName);  // Добавляем имя студента в первый комбобокс
        }
    }
}

// Заполнение комбобокса с лабораторными работами
void MainWindowLeader::fillLabComboBox()
{
    QStringList labs;
    for (int i = 1; i <= 13; ++i) {
        labs.append("Лабораторная " + QString::number(i));
    }
    for (int i = 1; i <= 13; ++i) {
        labs.append("ООП Лабораторная " + QString::number(i));
    }

    ui->comboBoxlab2->addItems(labs);  // Добавляем лабораторные работы в второй комбобокс
}

void MainWindowLeader::fillTestComboBoxes()
{
    // Заполнение студентов
    QSqlQuery query;
    query.prepare("SELECT name FROM users WHERE role = 'student' OR role = 'leader'");
    if (query.exec()) {
        while (query.next()) {
            QString studentName = query.value(0).toString();
            ui->comboBoxtest->addItem(studentName);
        }
    }

    // Заполнение тем проверочных работ
    QStringList topics;
    for (int i = 1; i <= 10; ++i) {
        topics.append("Тема " + QString::number(i));
    }
    ui->comboBoxtest2->addItems(topics);

    // Заполнение оценок
    QStringList grades = {"2", "3", "4", "5"};
    ui->comboBoxtest3->addItems(grades);
}

void MainWindowLeader::on_btnSave_clicked()
{
    QString studentName;
    QSqlQuery query;

    if (ui->comboBoxlab->isVisible()) {
        studentName = ui->comboBoxlab->currentText();
        QString labName = ui->comboBoxlab2->currentText();

        QMessageBox::information(this, "Сохранение", "Данные лабораторной работы сохранены!");
        return;
    }

    if (ui->comboBoxtest->isVisible()) {
        studentName = ui->comboBoxtest->currentText();
        QString testTopic = ui->comboBoxtest2->currentText();
        QString grade = ui->comboBoxtest3->currentText();

        query.prepare("INSERT INTO tests (student_name, test_topic, grade) VALUES (:student, :topic, :grade)");
        query.bindValue(":student", studentName);
        query.bindValue(":topic", testTopic);
        query.bindValue(":grade", grade);

        if (query.exec()) {
            QMessageBox::information(this, "Сохранение", "Данные проверочной работы сохранены!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка при сохранении: " + query.lastError().text());
        }
    }
}

bool MainWindowLeader::eventFilter(QObject *watched, QEvent *event)
{
    // Обрабатываем события для комбобоксов
    if (watched == ui->comboBoxlab || watched == ui->comboBoxlab2 || watched == ui->comboBoxtest || watched == ui->comboBoxtest2 || watched == ui->comboBoxtest3) {
        if (event->type() == QEvent::Enter) {
            // При наведении на комбобокс увеличиваем его размер
            if (watched == ui->comboBoxlab)
                animateComboBoxScale(ui->comboBoxlab, 1.0, 1.05 , originalGeometryComboLab);
            else if (watched == ui->comboBoxlab2)
                animateComboBoxScale(ui->comboBoxlab2, 1.0, 1.05 , originalGeometryComboLab2);
            else if (watched == ui->comboBoxtest)
                animateComboBoxScale(ui->comboBoxtest, 1.0, 1.05 , originalGeometryComboTest1);
            else if (watched == ui->comboBoxtest2)
                animateComboBoxScale(ui->comboBoxtest2, 1.0, 1.05 , originalGeometryComboTest2);
            else if (watched == ui->comboBoxtest3)
                animateComboBoxScale(ui->comboBoxtest3, 1.0, 1.05 , originalGeometryComboTest3);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // При уходе курсора с комбобокса восстанавливаем его размер
            if (watched == ui->comboBoxlab)
                animateComboBoxScale(ui->comboBoxlab, 1.05 , 1.0, originalGeometryComboLab);
            else if (watched == ui->comboBoxlab2)
                animateComboBoxScale(ui->comboBoxlab2, 1.05 , 1.0, originalGeometryComboLab2);
            else if (watched == ui->comboBoxtest)
                animateComboBoxScale(ui->comboBoxtest, 1.05 , 1.0, originalGeometryComboTest1);
            else if (watched == ui->comboBoxtest2)
                animateComboBoxScale(ui->comboBoxtest2, 1.05 , 1.0, originalGeometryComboTest2);
            else if (watched == ui->comboBoxtest3)
                animateComboBoxScale(ui->comboBoxtest3, 1.05 , 1.0, originalGeometryComboTest3);
            return true;
        }
    }

    // Обрабатываем события для кнопок
    if (watched == ui->btnSave || watched == ui->btnLab || watched == ui->btnTest) {
        if (event->type() == QEvent::Enter) {
            // При наведении на кнопку увеличиваем ее размер
            if (watched == ui->btnSave)
                animateButtonScale(ui->btnSave, 1.0, 1.1, originalGeometry);
            else if (watched == ui->btnLab)
                animateButtonScale(ui->btnLab, 1.0, 1.1, originalGeometryLab);
            else if (watched == ui->btnTest)
                animateButtonScale(ui->btnTest, 1.0, 1.1, originalGeometryTest);
            return true;
        } else if (event->type() == QEvent::Leave) {
            // При уходе курсора с кнопки восстанавливаем ее размер
            if (watched == ui->btnSave)
                animateButtonScale(ui->btnSave, 1.1, 1.0, originalGeometry);
            else if (watched == ui->btnLab)
                animateButtonScale(ui->btnLab, 1.1, 1.0, originalGeometryLab);
            else if (watched == ui->btnTest)
                animateButtonScale(ui->btnTest, 1.1, 1.0, originalGeometryTest);
            return true;
        }
    }

    return QObject::eventFilter(watched, event);
}

void MainWindowLeader::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
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

void MainWindowLeader::animateComboBoxScale(QComboBox *comboBox, qreal startScale, qreal endScale, const QRect &originalGeometry)
{
    // Создаем анимацию для изменения масштаба комбобокса
    QPropertyAnimation *animation = new QPropertyAnimation(comboBox, "geometry");
    animation->setDuration(200); // Время анимации в миллисекундах

    // Начальные и конечные размеры для анимации
    QRect startRect = originalGeometry;
    QRect endRect = originalGeometry.adjusted(-originalGeometry.width() * (endScale - startScale) / 2,
                                              -originalGeometry.height() * (endScale - startScale) / 2,
                                              originalGeometry.width() * (endScale - startScale) / 2,
                                              originalGeometry.height() * (endScale - startScale) / 2);

    animation->setStartValue(startRect);
    animation->setEndValue(endRect);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
