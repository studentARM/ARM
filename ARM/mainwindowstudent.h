#ifndef MAINWINDOWSTUDENT_H
#define MAINWINDOWSTUDENT_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QRect>
#include "test.h"  // Включаем заголовочный файл класса Test

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowStudent;  // Предварительное объявление класса UI
}
QT_END_NAMESPACE

class MainWindowStudent : public QDialog
{
    Q_OBJECT  // Макрос для поддержки сигналов и слотов Qt

public:
    explicit MainWindowStudent(QWidget *parent = nullptr);  // Конструктор
    ~MainWindowStudent();  // Деструктор

protected:
    // Фильтр событий для обработки пользовательских взаимодействий
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void openTest();  // Слот для открытия теста

private:
    Ui::MainWindowStudent *ui;  // Указатель на UI-форму
    Test *test;  // Указатель на объект теста
    QRect originalGeometry;  // Исходная геометрия для анимации

    // Создает элемент таблицы с иконкой статуса (выполнено/не выполнено)
    QTableWidgetItem* createStatusItem(bool done);

    // Загружает данные студента
    void loadStudentData();

    // Анимирует масштабирование кнопки
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);
};

#endif // MAINWINDOWSTUDENT_H
