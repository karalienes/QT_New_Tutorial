#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*

Most of the codes are the same as in the QThreads - Creating Threads except the portion that sets the thread priority.
The priority is set by the parameter passed into the start() method:
Its definition looks like this:

*** void QThread::start(Priority priority = InheritPriority)

The start() begins execution of the thread by calling run().
The operating system will schedule the thread according to the priority parameter. If the thread is already running, this function does nothing.
The effect of the priority parameter is dependent on the operating system's scheduling policy.
In particular, the priority will be ignored on systems that do not support thread priorities.

Constant                                Value           Description
********                                *****           ***********
QThread::IdlePriority                     0             scheduled only when no other threads are running.
QThread::LowestPriority                   1             scheduled less often than LowPriority.
QThread::NormalPriority                   3             the default priority of the operating system.
QThread::HighestPriority                  5             scheduled more often than HighPriority.
QThread::QThread::InheritPriority         7             use the same priority as the creating thread. This is the default.
*/
#include <QMainWindow>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void __init__();

private:
    Ui::MainWindow *ui;
    MyThread *thread1;
    MyThread *thread2;
    MyThread *thread3;
    MyThread *thread4;
    MyThread *thread5;


};
#endif // MAINWINDOW_H
