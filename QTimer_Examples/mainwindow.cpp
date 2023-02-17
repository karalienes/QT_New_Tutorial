#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create a timer
    timer = new QTimer(this);

    //setup signal and slot
    connect(timer,SIGNAL(timeout()),this,SLOT(MyTimerSlot()));

    //msec
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MyTimerSlot()
{
    qDebug()<<"Timer";;
}

