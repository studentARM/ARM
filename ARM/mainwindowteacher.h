#ifndef MAINWINDOWTEACHER_H
#define MAINWINDOWTEACHER_H

#include <QDialog>
#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QPushButton>
#include <QStringList>
#include <QList>

namespace Ui {
class MainWindowTeacher;  // Предварительное объявление класса UI
}

class MainWindowTeacher : public QDialog
{
    Q_OBJECT  // Макрос для поддержки сигналов и слотов Qt

public:
    explicit MainWindowTeacher(QWidget *parent = nullptr);  // Конструктор
    ~MainWindowTeacher();  // Деструктор

private:
    // Элементы интерфейса
    Ui::MainWindowTeacher *ui;  // Основной UI
    QTableWidget *stats;        // Таблица для отображения статистики студентов
    QPushButton *btnGive;       // Кнопка выдачи лабораторных работ
    QPushButton *btnMaterials;  // Кнопка выдачи учебных материалов
    QComboBox *groupFilter;     // Комбобокс для фильтрации по группам

    // Геометрия элементов для анимации
    QRect originalGeometry1;    // Геометрия первого элемента
    QRect originalGeometry2;    // Геометрия второго элемента
    QRect originalGeometry3;    // Геометрия третьего элемента
    QRect originalGeometrygroup; // Геометрия комбобокса групп

    // Методы инициализации
    void setupUI();             // Настройка пользовательского интерфейса
    void populateTable();       // Заполнение таблицы данными студентов
    void applyGroupFilter();    // Фильтрация студентов по группе
    void sortByRating();        // Сортировка студентов по рейтингу

    // Методы обработки событий
    bool eventFilter(QObject *obj, QEvent *event) override;  // Фильтр событий
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);  // Анимация кнопок
    void animateComboBoxScale(QComboBox *comboBox, qreal startScale, qreal endScale, const QRect &originalGeometry);  // Анимация комбобоксов

private slots:
    // Слоты для обработки действий
    void onGiveClicked();           // Обработка выдачи лабораторных
    void onMaterialsClicked();      // Обработка выдачи материалов
    void onGroupFilterChanged();    // Обработка изменения фильтра группы
    void onStudentClicked(int row, int column);  // Обработка клика по студенту
    void onLabsClicked();           // Обработка действий с лабораторными
    void openGraphForStudent(const QString &studentName);  // Открытие графика успеваемости
};

#endif // MAINWINDOWTEACHER_H
