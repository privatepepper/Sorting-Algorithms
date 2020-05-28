#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Window w;
    w.setFixedSize(1100, 750);
    Q_INIT_RESOURCE(resources);
    w.show();
    return a.exec();
}
