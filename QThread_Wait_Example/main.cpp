#include "dialog.h"
#include "mythread.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyThread mThread;
    qDebug()<<"GUI thread before MyThread start()"
            <<a.thread()->currentThread();

    mThread.start();

    qDebug() << "GUI thread after start()"
             << a.thread()->currentThread();

    mThread.wait();

    qDebug()<< "GUI thread after wait()"
            << a.thread()->currentThread();
    Dialog w;
    w.show();
    return a.exec();
}
