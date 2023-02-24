#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtConcurrent>
/*
In the previous example of creating thread from QThread is not a recommended way of using thread in Qt as we can see from the Qt5 document below:

The QtConcurrent namespace provides high-level APIs that make it possible to write multi-threaded programs without using low-level
threading primitives such as mutexes, read-write locks, wait conditions, or semaphores.

Programs written with QtConcurrent automatically adjust the number of threads used according to the number of processor cores available.
This means that applications written today will continue to scale when deployed on multi-core systems in the future.
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
    static void myRunFunction(QString name );

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
