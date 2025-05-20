#ifndef TEMPERAMENTDIALOG_H
#define TEMPERAMENTDIALOG_H

#include <QDialog>

namespace Ui {
class TemperamentDialog;
}

class TemperamentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TemperamentDialog(const QString &temperament, const QStringList &students, QWidget *parent = nullptr);
    ~TemperamentDialog();

private:
    Ui::TemperamentDialog *ui;
};

#endif // TEMPERAMENTDIALOG_H
