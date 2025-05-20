#ifndef ARM_H
#define ARM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ARM;
}
QT_END_NAMESPACE

class ARM : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_btnStudent_clicked();
    void on_btnLeader_clicked();
    void on_btnTeacher_clicked();

public:
    ARM(QWidget *parent = nullptr);
    ~ARM();

    QRect originalGeometryLeader;
    QRect originalGeometryStudent;
    QRect originalGeometryTeacher;

    bool eventFilter(QObject *obj, QEvent *event) override;
    void animateButtonScale(QWidget *widget, qreal start, qreal end, const QRect &baseGeometry);

private:
    Ui::ARM *ui;
};
#endif // ARM_H
