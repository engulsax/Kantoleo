#include "kompsitor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Kompsitor w;
    w.show();

    return a.exec();
}
