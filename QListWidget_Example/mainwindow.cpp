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
    //populate the items of the list
    for(int i=0;i<10;i++){
        ui->listWidget->addItem("Item: " + QString::number(i));

    }
}


void MainWindow::on_pushButton_clicked()
{
    //Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->listWidget->currentItem();

    //Set the text color and its bacground color using the pointer to the item.
    item->setTextColor(Qt::white);
    item->setBackgroundColor(Qt::green);
}

