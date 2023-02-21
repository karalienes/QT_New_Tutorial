#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Save(filename_obj);
    Load(filename_obj);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Save(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){

        qDebug()<<"Could not open"<<filename;
        return ;
    }

    int MyPass =999;
    QMap<int,QString> map;
    map.insert(1,"Enes");
    map.insert(2,"Karali");
    map[3] = "Linux Embedded";

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    out<<MyPass<<map;

    file.flush();
    file.close();
}

void MainWindow::Load(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){

        qDebug()<<"Could not open"<< filename;
        return ;
    }

    int Mypass;
    QMap<int,QString> map;

    QDataStream in (&file);
    in.setVersion(QDataStream::Qt_5_15);

    in >> Mypass >> map;

    file.close();

    qDebug()<<"Mypass = "<< Mypass;

    foreach(QString item, map.values()){
        qDebug()<<item;
    }
}

