#include "mainwindowteacher.h"
#include "ui_mainwindowteacher.h"
#include "givefromteacher.h"
#include "mainwindowleader.h"
#include "performancegraphwindow.h"
#include "sendemailwindow.h"

#include <QSqlQuery>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QSqlRecord>
#include <QClipboard>
#include <QToolTip>
#include <QPushButton>
#include <QComboBox>
#include <QSet>
#include <QSqlDatabase>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>

MainWindowTeacher::MainWindowTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowTeacher)
{
    ui->setupUi(this);
    this->setStyleSheet("MainWindowTeacher { background-image: url(:/resources/background.png); }");

    stats = ui->stats;
    btnGive = ui->Give;
    btnMaterials = ui->Materials;
    groupFilter = ui->group;

    setupUI();
    populateTable();

    connect(ui->Give, &QPushButton::clicked, this, &MainWindowTeacher::onGiveClicked);
    connect(ui->Materials, &QPushButton::clicked, this, &MainWindowTeacher::onMaterialsClicked);
    connect(ui->group, &QComboBox::currentTextChanged, this, &MainWindowTeacher::onGroupFilterChanged);
    connect(ui->stats, &QTableWidget::cellClicked, this, &MainWindowTeacher::onStudentClicked);
    connect(ui->labs, &QPushButton::clicked, this, &MainWindowTeacher::onLabsClicked);

    originalGeometry1 = ui->Give->geometry();
    originalGeometry2 = ui->Materials->geometry();
    originalGeometry3 = ui->labs->geometry();
    originalGeometrygroup = ui->group->geometry();

    ui->Give->installEventFilter(this);
    ui->Materials->installEventFilter(this);
    ui->labs->installEventFilter(this);
    ui->group->installEventFilter(this);
}

MainWindowTeacher::~MainWindowTeacher()
{
    delete ui;
}

void MainWindowTeacher::onLabsClicked()
{
    MainWindowLeader *leaderWindow = new MainWindowLeader(this);
    leaderWindow->setAttribute(Qt::WA_DeleteOnClose);
    leaderWindow->show();
}

void MainWindowTeacher::setupUI()
{
    stats->setColumnCount(11);
    QStringList headers;
    headers << "ФИО" << "Группа" << "Роль" << "Лабораторные" << "Проверочные"
            << "Кол-во лаб" << "Сумма баллов" << "Результат теста" << "Загруженность (%)" << "Рейтинг" << "";
    stats->setHorizontalHeaderLabels(headers);

    stats->setColumnWidth(0, 200);
    stats->setColumnWidth(1, 80);
    stats->setColumnWidth(2, 70);
    stats->setColumnWidth(3, 170);
    stats->setColumnWidth(4, 200);
    stats->setColumnWidth(5, 90);
    stats->setColumnWidth(6, 95);
    stats->setColumnWidth(7, 100);
    stats->setColumnWidth(8, 120);
    stats->setColumnWidth(9, 60);
    stats->setColumnWidth(10, 32);

    stats->setStyleSheet(
        "QTableWidget { background-color: white; color: black; gridline-color: #d0d0d0; }"
        "QTableWidget::item { color: black; text-align: center; }"
        "QHeaderView::section { background-color: #f0f0f0; color: black; padding: 5px; border: 1px solid #d0d0d0; text-align: center; }"
        "QComboBox { color: black; background-color: white; text-align: center; }"
        );

    stats->setAlternatingRowColors(false);
    stats->setSelectionBehavior(QAbstractItemView::SelectRows);
    stats->setSelectionMode(QAbstractItemView::SingleSelection);
    stats->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
}

void MainWindowTeacher::populateTable()
{
    stats->setRowCount(0);
    groupFilter->clear();

    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:";
        return;
    }

    QSqlQuery checkLabsQuery("SELECT COUNT(*) FROM checklabs WHERE is_issued = 1");
    int totalLabsCount = 0;
    if (checkLabsQuery.next()) {
        totalLabsCount = checkLabsQuery.value(0).toInt();
    }

    QSqlQuery userQuery("SELECT id, name, groupname, role FROM users WHERE role = 'student' OR role = 'leader'");
    QSet<QString> groups;

    while (userQuery.next()) {
        QString name = userQuery.value("name").toString();
        QString groupname = userQuery.value("groupname").toString();
        QString role = userQuery.value("role").toString();

        groups.insert(groupname);

        QSqlQuery labQuery;
        labQuery.prepare("SELECT lab_name FROM labs WHERE student_name = ?");
        labQuery.addBindValue(name);
        labQuery.exec();

        QStringList labs;
        int completedLabsCount = 0;
        while (labQuery.next()) {
            labs << labQuery.value(0).toString();
            completedLabsCount++;
        }

        int remainingLabs = totalLabsCount - completedLabsCount;

        QSqlQuery testQuery;
        testQuery.prepare("SELECT test_topic, grade FROM tests WHERE student_name = ?");
        testQuery.addBindValue(name);
        testQuery.exec();

        QStringList tests;
        int totalScore = 0;
        int testCount = 0;
        QSet<QString> uniqueTests;

        while (testQuery.next()) {
            QString topic = testQuery.value(0).toString();
            int grade = testQuery.value(1).toInt();
            tests << topic + " (" + QString::number(grade) + ")";
            totalScore += grade;

            if (!uniqueTests.contains(topic)) {
                uniqueTests.insert(topic);
                testCount++;
            }
        }

        int maxTestScore = testCount * 5;
        if (maxTestScore == 0) maxTestScore = 1;

        int load = 100;
        if (totalLabsCount > 0) {
            double labsProgress = (double)completedLabsCount / totalLabsCount * 0.5;
            double testsProgress = (double)totalScore / maxTestScore * 0.5;
            double totalProgress = labsProgress + testsProgress;
            load = 100 - (int)(totalProgress * 100);
            load = qBound(0, load, 100);
        }

        int rating = completedLabsCount + totalScore;

        int row = stats->rowCount();
        stats->insertRow(row);

        auto createCenteredItem = [](const QString& text) {
            QTableWidgetItem* item = new QTableWidgetItem(text);
            item->setTextAlignment(Qt::AlignCenter);
            return item;
        };

        stats->setItem(row, 0, createCenteredItem(name));
        stats->setItem(row, 1, createCenteredItem(groupname));
        stats->setItem(row, 2, createCenteredItem(role));

        auto createCenteredComboBox = [](const QStringList& items) {
            QComboBox* combo = new QComboBox();
            combo->addItems(items);
            combo->setStyleSheet("QComboBox { text-align: center; padding-left: 20px; }"
                                 "QComboBox QAbstractItemView { text-align: center; }");
            return combo;
        };

        stats->setCellWidget(row, 3, createCenteredComboBox(labs));
        stats->setCellWidget(row, 4, createCenteredComboBox(tests));

        QTableWidgetItem* labsCountItem = createCenteredItem(QString::number(completedLabsCount));
        labsCountItem->setFlags(labsCountItem->flags() & ~Qt::ItemIsSelectable);

        if (remainingLabs == 0) labsCountItem->setBackground(QColor(144, 238, 144));
        else if (remainingLabs <= 3) labsCountItem->setBackground(QColor(200, 255, 200));
        else if (remainingLabs <= 6) labsCountItem->setBackground(QColor(255, 165, 0));
        else labsCountItem->setBackground(QColor(255, 99, 71));
        stats->setItem(row, 5, labsCountItem);

        stats->setItem(row, 6, createCenteredItem(QString::number(totalScore)));

        QSqlQuery surveyQuery;
        surveyQuery.prepare("SELECT total_score FROM survey_results WHERE full_name = ? ORDER BY id DESC LIMIT 1");
        surveyQuery.addBindValue(name);
        QString surveyResultText = "—";
        if (surveyQuery.exec() && surveyQuery.next()) {
            int total_score = surveyQuery.value(0).toInt();
            surveyResultText = QString::number(total_score) + " из 15";
        }
        stats->setItem(row, 7, createCenteredItem(surveyResultText));
        stats->setItem(row, 8, createCenteredItem(QString::number(load) + "%"));
        stats->setItem(row, 9, createCenteredItem(QString::number(rating)));

        QPushButton *graphButton = new QPushButton(this);
        graphButton->setIcon(QIcon(":/resources/graph.png"));
        graphButton->setIconSize(QSize(24, 24));
        graphButton->setToolTip("Открыть график");
        graphButton->setFlat(true);
        graphButton->setCursor(Qt::PointingHandCursor);
        graphButton->setStyleSheet("background: transparent; border: none;");

        connect(graphButton, &QPushButton::clicked, [this, name]() {
            openGraphForStudent(name);
        });
        stats->setCellWidget(row, 10, graphButton);
    }

    QStringList groupList = groups.values();
    groupList.sort();
    groupFilter->addItem("Все группы");
    groupFilter->addItems(groupList);

    stats->sortByColumn(9, Qt::DescendingOrder);
    stats->setColumnHidden(9, true);

    db.close();
}

void MainWindowTeacher::sortByRating()
{
    stats->sortItems(4, Qt::AscendingOrder);
}

void MainWindowTeacher::applyGroupFilter()
{
    QString selectedGroup = groupFilter->currentText();

    for (int row = 0; row < stats->rowCount(); ++row) {
        QTableWidgetItem *item = stats->item(row, 1);
        stats->setRowHidden(row, !(selectedGroup == "Все группы" || item->text() == selectedGroup));
    }
}

void MainWindowTeacher::onGiveClicked()
{
    GiveFromTeacher giveDialog(this);
    giveDialog.setModal(true);
    giveDialog.exec();
}

void MainWindowTeacher::onMaterialsClicked()
{
    SendEmailWindow dialog(this);
    dialog.exec();
}

void MainWindowTeacher::onGroupFilterChanged()
{
    applyGroupFilter();
}

bool MainWindowTeacher::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
        qreal start = (event->type() == QEvent::Enter) ? 1.0 : 1.05;
        qreal end = (event->type() == QEvent::Enter) ? 1.05 : 1.0;

        if (watched == ui->Give) animateButtonScale(ui->Give, start, end, originalGeometry1);
        else if (watched == ui->Materials) animateButtonScale(ui->Materials, start, end, originalGeometry2);
        else if (watched == ui->labs) animateButtonScale(ui->labs, start, end, originalGeometry3);
        else if (watched == ui->group) animateComboBoxScale(ui->group, start, end, originalGeometrygroup);
    }
    return QDialog::eventFilter(watched, event);
}

void MainWindowTeacher::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
{
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(200);
    animation->setStartValue(baseGeometry);
    animation->setEndValue(QRect(baseGeometry.x() - (end - 1.0) * baseGeometry.width() / 2,
                                 baseGeometry.y() - (end - 1.0) * baseGeometry.height() / 2,
                                 baseGeometry.width() * end,
                                 baseGeometry.height() * end));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindowTeacher::animateComboBoxScale(QComboBox *comboBox, qreal startScale, qreal endScale, const QRect &originalGeometry)
{
    animateButtonScale(comboBox, startScale, endScale, originalGeometry);
}

void MainWindowTeacher::onStudentClicked(int row, int column)
{
    QString studentName = stats->item(row, 0)->text();

    if (column == 10) {
        openGraphForStudent(studentName);
        return;
    }

    if (column != 0) return;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть базу данных");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT email FROM users WHERE name = ?");
    query.addBindValue(studentName);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка выполнения запроса");
        db.close();
        return;
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация о студенте");

    if (query.next()) {
        QString email = query.value(0).toString();
        msgBox.setText(QString("Студент: %1\nEmail: %2").arg(studentName, email));
        QPushButton *copyButton = msgBox.addButton("Копировать email", QMessageBox::ActionRole);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();

        if (msgBox.clickedButton() == copyButton) {
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(email);
            QToolTip::showText(msgBox.pos(), "Email скопирован!", &msgBox);
        }
    } else {
        msgBox.setText(QString("Студент: %1\nEmail не найден").arg(studentName));
        msgBox.exec();
    }

    db.close();
}

void MainWindowTeacher::openGraphForStudent(const QString &studentName)
{
    PerformanceGraphWindow *window = new PerformanceGraphWindow(studentName, this);
    window->exec();
}
