#ifndef SENDDIALOG_H
#define SENDDIALOG_H

#include <QDialog>

namespace Ui {
class SendDialog;
}

class SendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendDialog(QWidget *parent = nullptr);
    ~SendDialog();

private:
    Ui::SendDialog *ui; // Указатель на сгенерированный UI класс
    void loadLeaders(); // Функция загрузки лидеров из базы данных
    void loadLabFiles(); // Функция загрузки лабораторных файлов

private slots:
    void on_buttonBox_accepted(); // Слот для обработки кнопки OK
};

#endif // SENDDIALOG_H
