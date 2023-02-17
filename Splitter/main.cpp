#include "mainwindow.h"

#include <QApplication>
/*
 * The dialog has two PlainTextEdits. We can split the two widgets in two ways: horizontally or vertically.
 *
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
