#include "temperamentdialog.h"
#include "ui_temperamentdialog.h"

TemperamentDialog::TemperamentDialog(const QString &temperament, const QStringList &students, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TemperamentDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("TemperamentDialog { background-image: url(:/resources/background.png); }");

    // Устанавливаем заголовок с темпераментом
    ui->labelTitle->setText("Студенты с темпераментом: " + temperament);

    // Заполняем список
    ui->listWidgetStudents->addItems(students);
}

TemperamentDialog::~TemperamentDialog()
{
    delete ui;
}
