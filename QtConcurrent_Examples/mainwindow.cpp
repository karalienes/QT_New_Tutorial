#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtconcurrentrun.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __init__();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#ifndef QT_NO_CONCURRENT
void MainWindow::__init__()
{
    /*
     * QtConcurrent::run() - runs a function in another thread.
       QFuture - represents the result of an asynchronous computation.
       Actually, QFuture also offers ways to interact with a runnning computation such as cancel(), pause(), or resume().
       However, we cannot do that in our example because the future was returned by QtConcurrent::run().
       We'll deal with this interaction with the result later section for QtConcurrent::mappedReduced().
    */
    QFuture<void> t1 = QtConcurrent::run(myRunFunction, QString("A"));
    QFuture<void> t2 = QtConcurrent::run(myRunFunction, QString("B"));
    QFuture<void> t3 = QtConcurrent::run(myRunFunction, QString("C"));

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();
}

void MainWindow::myRunFunction(QString name)
{
    for(int i=0; i<=5;i++)
    {
        qDebug()<< name << " "<< i <<
                   "from" << QThread::currentThread();
    }
}

#else
void MainWindow::__init__()
{
    QString text("Qt Concurrent is not yet supported on this platform");

    ui->label->setWordWrap(true);

}

#endif

