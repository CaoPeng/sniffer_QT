#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"
//QString dev;
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QApplication app(argc, argv);
    //app.setWindowIcon(":/images/new.png");
    MainWindow w;
    w.show();
    return app.exec();
}
