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


void MainWindow::on_start_button_clicked()
{
    mThread->start(QThread::HighPriority);
}


void MainWindow::on_stop_button_clicked()
{
    mThread->Stop = true;
}

void MainWindow::onValueChanged(int count)
{
    ui->count_label->setText(QString::number(count));
}
void MainWindow::__init__()
{
    // create an instance of MyThread
    mThread = new MyThread(this);

    // connect signal/slot

    connect(mThread,SIGNAL(valueChanged(int)), this, SLOT(onValueChanged(int)));
}
