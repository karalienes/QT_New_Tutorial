#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    write(filename_obj);
    read(filename_obj);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read(QString filename)
{
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //We're going to streaming the file
        // to the QString
        //It's also common to use QTextStream to read console input and write console output.
        //QTextStream is locale aware, and will automatically decode standard input using the correct codec.
        QTextStream stream(&file);

        QString line;

        do {
            line = stream.readLine();
            qDebug()<<line;

        }while(!line.isNull());

        file.close();
        qDebug()<< "Reading finished";
    }
}

void MainWindow::write(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        //We're going to streaming text to the file

        QTextStream stream(&file);

        stream << "Enes\n";
        stream << "KARALI";

        file.close();
        qDebug()<<"Writing finished";
    }
}

