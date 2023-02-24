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


    thread1->start();
    thread2->start();
    thread3->start();
}
