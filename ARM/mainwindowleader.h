#ifndef MAINWINDOWLEADER_H
#define MAINWINDOWLEADER_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class MainWindowLeader;  // Предварительное объявление класса UI
}

class MainWindowLeader : public QDialog
{
    Q_OBJECT  // Макрос для поддержки сигналов и слотов Qt

public slots:
    // Слоты для обработки действий пользователя:
    void on_btnLab_clicked();  // Нажатие кнопки лабораторных работ
    void on_btnTest_clicked();  // Нажатие кнопки тестов
    void on_btnSave_clicked();  // Нажатие кнопки сохранения
    void onLabSelected(const QString &labName);  // Выбор лабораторной работы
    void on_btnShowMatchingTemperament_clicked();  // Показать соответствие темпераментов

public:
    explicit MainWindowLeader(QWidget *parent = nullptr);  // Конструктор
    ~MainWindowLeader();  // Деструктор

    // Геометрия виджетов для анимации:
    QRect originalGeometry;  // Основное окно
    QRect originalGeometryLab;  // Кнопка лабораторных
    QRect originalGeometryTest;  // Кнопка тестов
    QRect originalGeometryComboLab;  // Комбобокс лабораторных
    QRect originalGeometryComboLab2;  // Доп. комбобокс лабораторных
    QRect originalGeometryComboTest1;  // Комбобокс тестов 1
    QRect originalGeometryComboTest2;  // Комбобокс тестов 2
    QRect originalGeometryComboTest3;  // Комбобокс тестов 3

private:
    Ui::MainWindowLeader *ui;  // Указатель на UI-форму

    // Вспомогательные методы:
    void fillStudentComboBox();  // Заполнение списка студентов
    void fillLabComboBox();  // Заполнение списка лабораторных
    void fillTestComboBoxes();  // Заполнение списков тестов
    bool eventFilter(QObject *obj, QEvent *event) override;  // Фильтр событий
    // Методы анимации:
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);
    void animateComboBoxScale(QComboBox *comboBox, qreal startScale, qreal endScale, const QRect &originalGeometry);
    void showCheckboxDialog(const QString &studentName, const QString &labName);  // Диалог с чекбоксами
};

#endif // MAINWINDOWLEADER_H
