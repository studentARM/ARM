#include "performancegraphwindow.h"
#include "ui_performancegraphwindow.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QDebug>
#include <QSqlError>


PerformanceGraphWindow::PerformanceGraphWindow(const QString &studentName, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::PerformanceGraphWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog { background-image: url(:/resources/background.png); }");

    // Открываем базу, если ещё не открыта
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db"); // путь к базе
    }

    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Не удалось открыть базу данных:" << db.lastError().text();
            return;
        }
    }

    drawGraph(studentName);
    ui->label->setText("Успеваемость студента " + studentName);
}


PerformanceGraphWindow::~PerformanceGraphWindow()
{
    delete ui;
}

void PerformanceGraphWindow::drawGraph(const QString &studentName)
{
    // Очистка контейнера
    QLayout *oldLayout = ui->plotContainer->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout();
    ui->plotContainer->setLayout(layout);
    QCustomPlot *plot = new QCustomPlot(this);
    layout->addWidget(plot);

    QVector<double> x, y;
    QStringList topics;

    QSqlQuery query;
    query.prepare("SELECT test_topic, grade FROM tests WHERE student_name = :name");
    query.bindValue(":name", studentName);

    if (query.exec()) {
        int i = 0;
        int count = 0;
        while (query.next()) {
            QString topic = query.value(0).toString();
            double grade = query.value(1).toDouble();
            topics << topic;
            x << i;
            y << grade;
            ++i;
            ++count;
        }
        qDebug() << "Найдено записей:" << count;
    } else {
        qDebug() << "Ошибка запроса:" << query.lastError().text();
    }

    // Если нет данных, не рисуем график
    if (x.isEmpty())
        return;

    plot->setBackground(QColor("#DDA0DD"));
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::white, 3));
    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8, Qt::white));
    plot->graph(0)->setData(x, y);

    plot->xAxis->setLabel("Тесты");
    plot->yAxis->setLabel("Оценка");

    plot->xAxis->setRange(-1, x.size());
    plot->yAxis->setRange(0, 5);

    QPen axisPen(Qt::white, 3);
    plot->xAxis->setBasePen(axisPen);
    plot->xAxis->setTickPen(axisPen);
    plot->xAxis->setSubTickPen(axisPen);
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->xAxis->setLabelColor(Qt::white);

    plot->yAxis->setBasePen(axisPen);
    plot->yAxis->setTickPen(axisPen);
    plot->yAxis->setSubTickPen(axisPen);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);

    QFont font = plot->xAxis->labelFont();
    font.setPointSize(14);
    font.setBold(true);
    plot->xAxis->setLabelFont(font);
    plot->yAxis->setLabelFont(font);
    plot->xAxis->setTickLabelFont(font);
    plot->yAxis->setTickLabelFont(font);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < topics.size(); ++i)
        textTicker->addTick(i, topics[i]);
    plot->xAxis->setTicker(textTicker);

    plot->xAxis->grid()->setVisible(false);
    plot->yAxis->grid()->setVisible(false);

    plot->replot();
}


