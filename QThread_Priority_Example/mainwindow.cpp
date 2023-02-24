#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::__init__()
{
    thread1 = new MyThread("A");
    thread2 = new MyThread("B");
    thread3 = new MyThread("C");
    thread4 = new MyThread("D");
    thread5 = new MyThread("E");

    thread1->start(/*QThread::IdlePriority*/);
    thread2->start(QThread::LowestPriority);
    thread3->start(/*QThread::NormalPriority*/);
    thread4->start(QThread::HighestPriority);
    thread5->start(/*QThread::QThread::InheritPriority*/);

}
