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
    ui->button1->setToolTip(
                "<h2><b><font color='red'>MyList</font></b></h2>"
                "<ol>"
                  "<li>First</li>"
                  "<li>Second</li>"
                  "<li>Third</li>"
                "</ol>"
                );
    ui->button2->setToolTip("<img src='::/img/new.png'/> Book");
}

