#include "QtExample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtExample w;
    w.show();
    return a.exec();
}
