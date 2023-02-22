#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
};
#endif // MAINWINDOW_H
