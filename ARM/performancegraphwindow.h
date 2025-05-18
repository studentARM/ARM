#ifndef PERFORMANCEGRAPHWINDOW_H
#define PERFORMANCEGRAPHWINDOW_H

#include <QDialog>
#include "qcustomplot.h"  // Библиотека для построения графиков

namespace Ui {
class PerformanceGraphWindow;  // Предварительное объявление класса UI
}

class PerformanceGraphWindow : public QDialog
{
    Q_OBJECT  // Макрос для поддержки сигналов и слотов Qt

public:
    // Конструктор с параметрами:
    // - studentName: имя студента для отображения статистики
    // - parent: родительский виджет (по умолчанию nullptr)
    explicit PerformanceGraphWindow(const QString &studentName, QWidget *parent = nullptr);
    ~PerformanceGraphWindow();  // Деструктор

private:
    Ui::PerformanceGraphWindow *ui;  // Указатель на UI-форму

    // Метод для отрисовки графика успеваемости
    // Принимает имя студента для загрузки соответствующих данных
    void drawGraph(const QString &studentName);
};

#endif // PERFORMANCEGRAPHWINDOW_H
