#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class LoginWindow;  // Предварительное объявление класса UI из пространства имен Ui
}

class LoginWindow : public QDialog
{
    Q_OBJECT  // Макрос для поддержки сигналов и слотов Qt

public slots:
    void on_btnLogin_clicked();  // Слот для обработки нажатия кнопки входа

public:
    // Конструктор с параметрами: роль, родительский виджет и окно ARM (опционально)
    explicit LoginWindow(const QString &role, QWidget *parent = nullptr, QWidget *armWindow = nullptr);
    ~LoginWindow();  // Деструктор

private:
    Ui::LoginWindow *ui;         // Указатель на UI-форму
    QString currentRole;         // Текущая роль пользователя
    void setupUIForRole();       // Настройка UI в зависимости от роли
    QWidget *armWindow;          // Указатель на связанное окно ARM

    QRect originalGeometry;      // Исходная геометрия окна/виджета
    // Фильтр событий для обработки пользовательских событий
    bool eventFilter(QObject *obj, QEvent *event) override;
    // Анимация масштабирования кнопки
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);
};

#endif // LOGINWINDOW_H
