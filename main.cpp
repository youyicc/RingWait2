#include "RingWait2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RingWait2 mainWidget;
    mainWidget.show();
    return a.exec();
}
