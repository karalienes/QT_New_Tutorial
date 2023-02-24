#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>
#include <QString>


class MyThread : public QThread
{
public:

    explicit MyThread(QString s);

    // overriding the QThread's run() method
    void run();

private:
    QString name;
};

#endif // MYTHREAD_H
