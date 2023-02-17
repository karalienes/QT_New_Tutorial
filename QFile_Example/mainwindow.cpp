#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filename = "/home/karali/Downloads/Qt_Tutorial/QtResourceFiles_Example/doc/doc.txt";
    write(filename);
    read(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::write(QString filename)
{
    QFile file(filename);
    //Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"Could not open file for writing";
        return ;
    }
    // To write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out<< "QFile Example";
    file.flush();
    file.close();

}

void MainWindow::read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug()<<"Could not open the file for reading";
        return ;
    }
    QTextStream in(&file);
    QString text_data = in.readAll();
    qDebug()<<text_data;

    file.close();

}

