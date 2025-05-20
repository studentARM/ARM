#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QVector>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QEvent>

namespace Ui {
class Test;  // Предварительное объявление класса интерфейса
}

class Test : public QDialog {
    Q_OBJECT  // Макрос для работы с сигналами и слотами Qt

public:
    // Конструктор тестового диалога
    explicit Test(QDialog *parent = nullptr);
    // Деструктор
    ~Test();

    // Геометрия элементов для анимации:
    QRect originalGeometry1;  // Позиция и размер первого элемента
    QRect originalGeometry2;  // Позиция и размер второго элемента
    QRect originalGeometry3;  // Позиция и размер третьего элемента
    QRect originalGeometry4;  // Позиция и размер четвертого элемента

signals:
    // Сигнал о завершении теста
    void testCompleted();

private slots:
    // Обработчик нажатия кнопки ответа
    void onAnswerButtonClicked();
    // Обработчик нажатия кнопки закрытия
    void onCloseButtonClicked();

private:
    Ui::Test *ui;  // Указатель на элементы интерфейса

    // Переменные состояния теста:
    int currentProgress = 0;     // Текущий прогресс прохождения
    int currentQuestion = 0;     // Номер текущего вопроса
    int correctAnswersCount = 0; // Количество правильных ответов

    // Баллы по разным шкалам:
    int egeScore = 0;         // Баллы ЕГЭ
    int motivationScore = 0;  // Уровень мотивации

    // Показатели темперамента:
    int sanguine = 0;     // Сангвиник
    int choleric = 0;     // Холерик
    int melancholic = 0;  // Меланхолик
    int phlegmatic = 0;   // Флегматик

    // Структура данных вопроса
    struct QuestionData {
        QString questionText;  // Текст вопроса
        QStringList answers;   // Варианты ответов
        int correctAnswer;     // Индекс правильного ответа
    };

    QVector<QuestionData> testQuestions;  // Вектор всех вопросов теста

    // Методы теста:
    void initializeTestData();  // Инициализация тестовых вопросов
    void updateQuestion();      // Обновление отображаемого вопроса
    void createTable();         // Создание таблицы в БД
    // Сохранение результатов в БД
    void saveResultsToDatabase(const QString& fullName, int correctAnswersCount);

    // Определение типа темперамента
    QString calculateTemperamentType() const;

    // Обработчик событий интерфейса
    bool eventFilter(QObject *obj, QEvent *event) override;
    // Анимация кнопок
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);
    // Показ финального слайда
    void showFinalSlide();
};

#endif // TEST_H
