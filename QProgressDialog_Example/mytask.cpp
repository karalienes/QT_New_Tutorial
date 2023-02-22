#include "mytask.h"

MyTask::MyTask(QObject *parent)
    : QObject{parent}, steps(0)
{
    __init__();
}

void MyTask::__init__()
{
    pd = new QProgressDialog("Task in progress.","Cancel",0,1000000);
    connect(pd, SIGNAL(canceled()), this, SLOT(cancel()));

    t = new QTimer(this);
    connect(t,SIGNAL(timeout()), this, SLOT(perform()));
    t->start(0);

}

void MyTask::perform()
{
    pd->setValue(steps);
    //.. perform one percent of the operation
    steps++;

    if(steps>pd->maximum())
        t->stop();
}

void MyTask::cancel()
{
    t->stop();
}
