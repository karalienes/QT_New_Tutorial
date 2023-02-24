#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mythread.h"
/*
The QMutex class provides access serialization between threads.

The purpose of a QMutex is to protect an object, data structure or section of code so that only one thread can access it at a time (synchronized).
It is usually best to use a mutex with a QMutexLocker since this makes it easy to ensure that locking and unlocking are performed consistently.

QMutex::QMutex(RecursionMode mode = NonRecursive)

The QMutex() constructs a new mutex. The mutex is created in an unlocked state. If mode is QMutex::Recursive,
a thread can lock the same mutex multiple times and the mutex won't be unlocked until a corresponding number of unlock() calls have been made.
Otherwise a thread may only lock a mutex once. The default is QMutex::NonRecursive.


Constant                                Value           Description
********                                *****           ***********
QMutex::Recursive                         1             In this mode, a thread can lock the same mutex multiple times and the mutex won't be unlocked until
                                                        a corresponding number of unlock() calls have been made.
QMutex::NonRecursive                      0             In this mode, a thread may only lock a mutex once.

*/
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
};
#endif // MAINWINDOW_H
