#include "test.h"
#include "ui_test.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QEvent>
#include <QGraphicsScale>
#include <QGraphicsTransform>
#include <QGraphicsProxyWidget>
#include <QGraphicsEffect>

#include "global.h"

Test::Test(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Test)
{
    ui->setupUi(this);

    // Устанавливаем прогрессбар под количество вопросов
    ui->progressBar->setRange(0, 30); // 15 базовых + 2 ЕГЭ/мотивация + 13 темперамент
    ui->progressBar->setValue(0);

    this->setStyleSheet("QDialog { background-image: url(:/resources/background.png); }");

    // Сохраняем начальные размеры кнопок
    originalGeometry1 = ui->answerButton1->geometry();
    originalGeometry2 = ui->answerButton2->geometry();
    originalGeometry3 = ui->answerButton3->geometry();
    originalGeometry4 = ui->answerButton4->geometry();

    // Устанавливаем фильтр событий на кнопки
    ui->answerButton1->installEventFilter(this);
    ui->answerButton2->installEventFilter(this);
    ui->answerButton3->installEventFilter(this);
    ui->answerButton4->installEventFilter(this);

    // Инициализация переменных
    currentQuestion = 0;
    currentProgress = 0;
    correctAnswersCount = 0;
    egeScore = 0;
    motivationScore = 0;
    sanguine = 0;
    choleric = 0;
    melancholic = 0;
    phlegmatic = 0;

    initializeTestData();
    createTable();

    connect(ui->answerButton1, &QPushButton::clicked, this, &Test::onAnswerButtonClicked);
    connect(ui->answerButton2, &QPushButton::clicked, this, &Test::onAnswerButtonClicked);
    connect(ui->answerButton3, &QPushButton::clicked, this, &Test::onAnswerButtonClicked);
    connect(ui->answerButton4, &QPushButton::clicked, this, &Test::onAnswerButtonClicked);

    updateQuestion();

    ui->FinLabel->hide();
    ui->closeButton->hide();

    connect(ui->closeButton, &QPushButton::clicked, this, &Test::onCloseButtonClicked);
}

void Test::initializeTestData()
{
    testQuestions = {
                     // 15 базовых вопросов
                     {"Вы чувствуете себя неловко в центре внимания?", {"Да", "Нет", "", ""}, 0},
                     {"Вы влияете на других людей?", {"Да", "Нет", "", ""}, 0},
                     {"У вас есть организаторские способности?", {"Да", "Нет", "", ""}, 0},
                     {"Вы тревожитесь, если несете ответственность?", {"Да", "Нет", "", ""}, 1},
                     {"Провал инициативы вас останавливает?", {"Да", "Нет", "", ""}, 1},
                     {"Вы стремитесь к роли лидера?", {"Да", "Нет", "", ""}, 0},
                     {"Вы отстаиваете мнение, даже если против всех?", {"Да", "Нет", "", ""}, 0},
                     {"Вы стремитесь преодолеть трудности?", {"Да", "Нет", "", ""}, 0},
                     {"Вы стесняетесь в компании?", {"Да", "Нет", "", ""}, 1},
                     {"Вы нерешительны?", {"Да", "Нет", "", ""}, 1},
                     {"Вы производите яркое впечатление?", {"Да", "Нет", "", ""}, 0},
                     {"Вы уверены в себе?", {"Да", "Нет", "", ""}, 0},
                     {"Вы быстро принимаете решения?", {"Да", "Нет", "", ""}, 0},
                     {"Вы любите быть в центре внимания?", {"Да", "Нет", "", ""}, 0},
                     {"Вы готовы к ответственности?", {"Да", "Нет", "", ""}, 0},

                     // Вопрос про ЕГЭ
                     {"Сколько баллов ЕГЭ у вас?", {"230-239", "240-249", "250-259", "260-270"}, -1},

                     // Вопрос про мотивацию
                     {"Почему вы поступили в университет?", {"Получить знания", "Потому что все так делают", "Хотел работать и учиться", "Просто поступил"}, -1},

                     // Вопросы про темперамент (13 штук)
                     {"Вы часто быстро реагируете на происходящее?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы любите планировать всё заранее?", {"Да", "Нет", "Иногда", "Редко"}, 1},
                     {"В компании вы обычно тихий наблюдатель?", {"Да", "Нет", "Иногда", "Редко"}, 2},
                     {"В стрессовой ситуации вы сохраняете спокойствие?", {"Да", "Нет", "Иногда", "Редко"}, 3},
                     {"Вы легко заводите новых друзей?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы склонны к перфекционизму?", {"Да", "Нет", "Иногда", "Редко"}, 1},
                     {"Вы быстро принимаете решения?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы эмоциональны и экспрессивны?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы избегаете конфликтов?", {"Да", "Нет", "Иногда", "Редко"}, 3},
                     {"Вам нравится работать в команде?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы склонны к аналитическому мышлению?", {"Да", "Нет", "Иногда", "Редко"}, 1},
                     {"Вы быстро переключаетесь между задачами?", {"Да", "Нет", "Иногда", "Редко"}, 0},
                     {"Вы предпочитаете стабильность и предсказуемость?", {"Да", "Нет", "Иногда", "Редко"}, 3},
                     };
}

void Test::createTable()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS survey_results ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "full_name TEXT, "
                    "total_score INTEGER, "
                    "temperament TEXT, "
                    "survey_completed INTEGER, "
                    "survey_taken INTEGER)"));
}

void Test::saveResultsToDatabase(const QString& fullName, int correctAnswersCount)
{
    int surveyTaken = 1;
    QString temperament = calculateTemperamentType();

    int totalScore = correctAnswersCount + egeScore + motivationScore;

    QSqlQuery query;
    query.prepare("INSERT INTO survey_results (full_name, total_score, temperament, survey_completed, survey_taken) "
                  "VALUES (:full_name, :total_score, :temperament, :survey_completed, :survey_taken)");

    query.bindValue(":full_name", fullName);
    query.bindValue(":total_score", totalScore);
    query.bindValue(":temperament", temperament);
    query.bindValue(":survey_completed", 0);
    query.bindValue(":survey_taken", surveyTaken);
}


void Test::onAnswerButtonClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    int selectedIndex = -1;

    if (clickedButton == ui->answerButton1) selectedIndex = 0;
    else if (clickedButton == ui->answerButton2) selectedIndex = 1;
    else if (clickedButton == ui->answerButton3) selectedIndex = 2;
    else if (clickedButton == ui->answerButton4) selectedIndex = 3;

    // Обработка ответов в зависимости от типа вопроса:
    if (currentQuestion < 15) {
        // Базовые вопросы с правильным ответом
        if (testQuestions[currentQuestion].correctAnswer >= 0 && selectedIndex == testQuestions[currentQuestion].correctAnswer) {
            correctAnswersCount++;
        }
    }
    else if (currentQuestion == 15) {
        // Вопрос про ЕГЭ - просто сохраняем выбранный индекс + 1 как балл
        egeScore = selectedIndex + 1;
    }
    else if (currentQuestion == 16) {
        // Вопрос про мотивацию
        motivationScore = selectedIndex + 1;
    }
    else if (currentQuestion > 16) {
        // Вопросы про темперамент
        int temperamentType = testQuestions[currentQuestion].correctAnswer;

        // 2 очка, если выбран ответ 0 (Да), 1 очко, если выбран ответ 2 (Иногда), иначе 0
        int points = (selectedIndex == 0) ? 2 : ((selectedIndex == 2) ? 1 : 0);

        switch (temperamentType) {
        case 0: sanguine += points; break;
        case 1: choleric += points; break;
        case 2: melancholic += points; break;
        case 3: phlegmatic += points; break;
        }
    }

    currentQuestion++;
    currentProgress++;
    ui->progressBar->setValue(currentProgress);

    if (currentQuestion >= testQuestions.size()) {
        saveResultsToDatabase(g_userName, correctAnswersCount);
        emit testCompleted();
        showFinalSlide();
        return;
    }

    updateQuestion();
}

void Test::showFinalSlide()
{
    ui->questionLabel->hide();
    ui->answerButton1->hide();
    ui->answerButton2->hide();
    ui->answerButton3->hide();
    ui->answerButton4->hide();

    ui->FinLabel->setText("Тест завершён! Спасибо за участие.");
    ui->FinLabel->show();

    ui->closeButton->show();
}
void Test::updateQuestion()
{
    if (currentQuestion < testQuestions.size()) {
        const QuestionData& qData = testQuestions[currentQuestion];
        ui->questionLabel->setText(qData.questionText);

        ui->answerButton1->setText(qData.answers[0]);
        ui->answerButton2->setText(qData.answers[1]);
        ui->answerButton3->setText(qData.answers[2]);
        ui->answerButton4->setText(qData.answers[3]);

        if (qData.answers[2].isEmpty() && qData.answers[3].isEmpty()) {
            ui->answerButton3->hide();
            ui->answerButton4->hide();
        } else if (qData.answers[3].isEmpty()) {
            ui->answerButton3->show();
            ui->answerButton4->hide();
        } else {
            ui->answerButton3->show();
            ui->answerButton4->show();
        }

        ui->answerButton1->show();
        ui->answerButton2->show();
    }
}

void Test::onCloseButtonClicked()
{
    this->close();
}

bool Test::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->answerButton1 || watched == ui->answerButton2 || watched == ui->answerButton3 || watched == ui->answerButton4) {
        if (event->type() == QEvent::Enter) {
            if (watched == ui->answerButton1)
                animateButtonScale(ui->answerButton1, 1.0, 1.1, originalGeometry1);
            else if (watched == ui->answerButton2)
                animateButtonScale(ui->answerButton2, 1.0, 1.1, originalGeometry2);
            else if (watched == ui->answerButton3)
                animateButtonScale(ui->answerButton3, 1.0, 1.1, originalGeometry3);
            else if (watched == ui->answerButton4)
                animateButtonScale(ui->answerButton4, 1.0, 1.1, originalGeometry4);
            return true;
        } else if (event->type() == QEvent::Leave) {
            if (watched == ui->answerButton1)
                animateButtonScale(ui->answerButton1, 1.1, 1.0, originalGeometry1);
            else if (watched == ui->answerButton2)
                animateButtonScale(ui->answerButton2, 1.1, 1.0, originalGeometry2);
            else if (watched == ui->answerButton3)
                animateButtonScale(ui->answerButton3, 1.1, 1.0, originalGeometry3);
            else if (watched == ui->answerButton4)
                animateButtonScale(ui->answerButton4, 1.1, 1.0, originalGeometry4);
            return true;
        }
    }

    return QObject::eventFilter(watched, event);
}

void Test::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
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

QString Test::calculateTemperamentType() const
{
    // Определяем темперамент с максимальным баллом
    int maxScore = sanguine;
    QString temperament = "Сангвиник";

    if (choleric > maxScore) {
        maxScore = choleric;
        temperament = "Холерик";
    }
    if (melancholic > maxScore) {
        maxScore = melancholic;
        temperament = "Меланхолик";
    }
    if (phlegmatic > maxScore) {
        maxScore = phlegmatic;
        temperament = "Флегматик";
    }

    return temperament;
}

Test::~Test()
{
    delete ui;
    QSqlDatabase::database().close();
}
