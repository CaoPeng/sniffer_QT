#include <QtGui/QApplication>
#include "mainwindow.h"
//QString dev;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setWindowIcon(":/images/new.png");
    MainWindow w;
    w.show();
    return app.exec();
}
