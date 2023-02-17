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
     QList<int> List;
     for(int i = 0; i < 6; i++) List.append(i);
     List.removeOne(4);
     foreach(int n, List) qDebug() << n;
}

