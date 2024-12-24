#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include "SystemItem.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if( ! SystemItem::instance()->loadConfig() ) {
        qDebug() << "Restart After Configuration complete";
        return -1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
