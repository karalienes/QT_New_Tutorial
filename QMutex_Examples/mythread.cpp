#include "mythread.h"

MyThread::MyThread(QString s, bool b): Stop(b), name(s)
{

}

//run() will be called when a thread starts

void MyThread::run()
{
    qDebug()<< this->name << " "<<this->Stop;

    for(int i =0; i<=5;i++)
    {
        QMutex mutex;
        //prevent other threads from changing the "Stop" value
        mutex.lock();
        if(this->Stop)
            break;
        mutex.unlock();
        qDebug()<<this->name<<" "<<i;
    }
}
