#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
