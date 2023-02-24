#include "mythread.h"

MyThread::MyThread(QObject * parent) :
    QThread(parent)
{

}

// We overrides the QThread's run() method here
// run() will be called when a thread starts
// the code will be shared by all threads

void MyThread::run()
{
    for(int i=0;i<=5;i++)
    {
        qDebug()<<"i";

        //slowdown the count change, msec
        this->msleep(500);
    }
}
