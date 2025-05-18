#include "sendemailwindow.h"
#include "ui_sendemailwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QPropertyAnimation>
#include <QTextEdit>
#include <QSqlQuery>
#include <QSqlError>

#include "smtp/smtpclient.h"
#include "smtp/emailaddress.h"
#include "smtp/mimemessage.h"
#include "smtp/mimetext.h"
#include "smtp/mimeattachment.h"

SendEmailWindow::SendEmailWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendEmailWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных: " << db.lastError().text();
    } else {
        qDebug() << "База данных подключена";
    }
    setWindowTitle("Отправка материалов");
    this->setStyleSheet("QDialog { background-image: url(:/resources/background.png); }");

    connect(ui->selectFileButton, &QPushButton::clicked, this, &SendEmailWindow::onSelectFile);
    connect(ui->sendButton, &QPushButton::clicked, this, &SendEmailWindow::onSendClicked);

    originalGeometrySend = ui->sendButton->geometry();
    originalGeometrySelect = ui->selectFileButton->geometry();

    ui->sendButton->installEventFilter(this);
    ui->selectFileButton->installEventFilter(this);

    loadLeaders();
}

SendEmailWindow::~SendEmailWindow()
{
    delete ui;
}

void SendEmailWindow::onSelectFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл для отправки");
    if (!filePath.isEmpty()) {
        selectedFilePath = filePath;
        ui->fileLabel->setText("Выбран файл: " + filePath);
    }
}

void SendEmailWindow::onSendClicked()
{
    if (selectedFilePath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не выбран.");
        return;
    }

    int index = ui->studentComboBox->currentIndex();
    if (index < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите студента.");
        return;
    }

    QString email = ui->studentComboBox->itemData(index).toString();
    sendEmail(email, selectedFilePath);
}

void SendEmailWindow::sendEmail(const QString &recipientEmail, const QString &filePath)
{
    SmtpClient smtp("smtp.gmail.com", 587, SmtpClient::TlsConnection);
    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось подключиться к SMTP серверу.");
        return;
    }

    smtp.login("testarmv1@gmail.com", "zqgi nalw yrll jjcn");
    if (!smtp.waitForAuthenticated()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка аутентификации.");
        return;
    }

    MimeMessage message;
    message.setSender(EmailAddress("testarmv1@gmail.com"));
    message.addRecipient(EmailAddress(recipientEmail), MimeMessage::To);
    message.setSubject("Материалы от преподавателя");

    MimeText *text = new MimeText();
    QString userText = ui->Text->toPlainText();
    if (userText.trimmed().isEmpty()) {
        userText = "Здравствуйте!\nВо вложении файл для вас.";
    }
    text->setText(userText);
    message.addPart(text);

    QFile *file = new QFile(filePath);
    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        delete text;
        delete file;
        return;
    }

    MimeAttachment *attachment = new MimeAttachment(file, QFileInfo(filePath).fileName());
    message.addPart(attachment);

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка отправки письма.");
        file->close();
        delete attachment;
        delete file;
        delete text;
        return;
    }

    smtp.quit();
    file->close();

    delete attachment;
    delete file;
    delete text;

    QMessageBox::information(this, "Успех", "Письмо отправлено на " + recipientEmail);
}

bool SendEmailWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->sendButton || watched == ui->selectFileButton) {
        if (event->type() == QEvent::Enter) {
            if (watched == ui->sendButton)
                animateButtonScale(ui->sendButton, 1.0, 1.1, originalGeometrySend);
            else
                animateButtonScale(ui->selectFileButton, 1.0, 1.1, originalGeometrySelect);
            return true;
        } else if (event->type() == QEvent::Leave) {
            if (watched == ui->sendButton)
                animateButtonScale(ui->sendButton, 1.1, 1.0, originalGeometrySend);
            else
                animateButtonScale(ui->selectFileButton, 1.1, 1.0, originalGeometrySelect);
            return true;
        }
    }

    return QObject::eventFilter(watched, event);
}

void SendEmailWindow::animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry)
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

void SendEmailWindow::loadLeaders()
{
    QSqlQuery query;
    if (!query.exec("SELECT name, groupname, email FROM users WHERE role = 'leader'")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить список лидеров: " + query.lastError().text());
        return;
    }

    ui->studentComboBox->clear();
    while (query.next()) {
        QString name = query.value(0).toString();
        QString group = query.value(1).toString();
        QString email = query.value(2).toString();

        QString displayText = QString("%1 (%2)").arg(name, group);
        ui->studentComboBox->addItem(displayText, email);  // email в userData
    }
}
