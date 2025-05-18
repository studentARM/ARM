#ifndef GIVELABS_H
#define GIVELABS_H

#include <QDialog>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QVector>
#include <QScrollArea>

namespace Ui {
class GiveLabs;
}

class GiveLabs : public QDialog
{
    Q_OBJECT


public slots:
    void onGiveClicked();

public:
    explicit GiveLabs(QWidget *parent = nullptr);
    ~GiveLabs();
     QStringList selectedLabs() const;

private:
    Ui::GiveLabs *ui;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
    QMap<int, QCheckBox*> labCheckBoxes;

    void loadLabs();
    void updateLabsInDb();
    void createLabsDatabase();
    void fillLabsDatabase();
};

#endif // GIVELABS_H
