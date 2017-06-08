#include "vlcproj.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VLCProj w;
    w.show();

    return a.exec();
}
