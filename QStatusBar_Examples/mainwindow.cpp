#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create objects for the label and progress bar
    statusLabel = new QLabel(this);
    statusProgressBar = new QProgressBar(this);

    //Set text for the label
    statusLabel->setText("Status Label");

    //Make progress bar text invisible
    statusProgressBar->setTextVisible(false);

    //add the two controls to the status bar
    ui->statusbar->addPermanentWidget(statusLabel,0);
    ui->statusbar->addPermanentWidget(statusProgressBar,1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionMyMenuAction_triggered()
{
    /*
     * The void QStatusBar::showMessage(const QString & message, int timeout = 0)
     * hides the normal status indications and displays the given message for the specified number of milli-seconds (timeout).
     * If timeout is 0 (default), the message remains displayed until the clearMessage() slot is called or until the showMessage()
     * slot is called again to change the message.
     */
    //showMessage(const QString & message, int timeout=0)
    ui->statusbar->showMessage("Status",2);
    statusProgressBar->setValue(51);
}

