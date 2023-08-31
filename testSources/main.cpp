#include "widget.h"
#include <QApplication>

#include <QString>
#include <QSplashScreen>
#include <QPixmap>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;


    w.show();

    return a.exec();
}
