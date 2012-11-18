#include <QtGui/QApplication>
#include "myfirstgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyFirstGUI w;
    w.show();
    return a.exec();
}

