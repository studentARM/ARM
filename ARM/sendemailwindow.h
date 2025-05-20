#ifndef SENDEMAILWINDOW_H
#define SENDEMAILWINDOW_H

#include <QDialog>
#include <QRect>

namespace Ui {
class SendEmailWindow;  // Предварительное объявление класса UI
}

class SendEmailWindow : public QDialog
{
    Q_OBJECT  // Включение системы мета-объектов Qt

public:
    // Конструктор - создает диалоговое окно отправки email
    explicit SendEmailWindow(QWidget *parent = nullptr);

    // Деструктор - освобождает ресурсы
    ~SendEmailWindow();

protected:
    // Фильтр событий для обработки пользовательских взаимодействий
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    // Слот для обработки нажатия кнопки выбора файла
    void onSelectFile();

    // Слот для обработки нажатия кнопки отправки
    void onSendClicked();

private:
    // Основная функция отправки email
    void sendEmail(const QString &recipientEmail, const QString &filePath);

    // Вспомогательная функция для анимации кнопок
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);

    // Загрузка списка руководителей/получателей
    void loadLeaders();

private:
    Ui::SendEmailWindow *ui;           // Указатель на элементы интерфейса
    QString selectedFilePath;          // Путь к прикрепленному файлу
    QRect originalGeometrySend;        // Исходная геометрия кнопки отправки (для анимации)
    QRect originalGeometrySelect;      // Исходная геометрия кнопки выбора (для анимации)
};

#endif // SENDEMAILWINDOW_H
