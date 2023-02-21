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
//QLinkedList stores a list of items. The default constructor creates an empty list. To insert items into the list, we can use operator<<().
void MainWindow::__init__()
{
    QLinkedList<QString> List;
    List<<"A"<<"B"<<"C";
    List.append("D");
    List.append("E");
    List.append("F");

    foreach(QString data, List){
        qDebug()<<data;
    }
}
