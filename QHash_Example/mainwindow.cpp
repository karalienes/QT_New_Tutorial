#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::__init__()
{
    QHash<int,QString> Hash;

    Hash.insert(1,"A");
    Hash.insert(2,"B");
    Hash[3]= "C";

    foreach(int i, Hash.keys()){
        qDebug()<<Hash[i];
    }

    QHashIterator<int,QString> iter(Hash);

    //If we want to navigate through all the (key, value) pairs stored in a QHash, we can use an iterator.
    //QHash provides both Java-style iterators (QHashIterator and QMutableHashIterator) and
    //STL-style iterators (QHash::const_iterator and QHash::iterator). The example above shows how to iterate over a QHash<QString, int> using a Java-style iterator:
    while(iter.hasNext()){
        iter.next();

        qDebug()<<iter.key()<<" : "<<iter.value();
    }
}
