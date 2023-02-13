#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objMyDialogActionDemo2 = new MyDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ActionDemo_triggered()
{
    //modded state
    MyDialog objMyDialog;
    objMyDialog.setModal(false);
    objMyDialog.exec();

    //modeless state
    //objMyDialog.show();
    //But it disappears as soon as it is created. That's because unlike modal type dialog, modaless gives control to the main app,
    //the stack variable goes away when it gets out of on_ActionDemo_triggered().
    //So, we need to set a pointer as a member of the MainWindow class:

}


void MainWindow::on_ActionDemo2_triggered()
{
    //So, we need to set a pointer as a member
    objMyDialogActionDemo2->show();
}

