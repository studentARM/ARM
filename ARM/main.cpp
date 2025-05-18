#include "arm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ARM w;
    w.show();
    return a.exec();
}
