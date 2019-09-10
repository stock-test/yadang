#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("/tmp/screen-shot.png");
    QRect rect(200, 600, pixmap.width(), pixmap.height());
    MainWindow w(rect);
    w.updatePicture();
    w.show();

    return a.exec();
}
