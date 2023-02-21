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
    //We can store multiple values per key by using insertMulti() instead of insert().
    QMap <int,QString> Map;
    Map.insert(1,"A");
    Map.insert(2,"B");
    Map[3]= "C";

    //traversing array with foreach
    foreach(int i , Map.keys()){
        qDebug()<<Map[i];
    }
    QMapIterator<int,QString> iter(Map);

    //If we want to navigate through all the (key, value) pairs stored in a QMap, we can use an iterator.
    //QMap provides both Java-style iterators (QMapIterator and QMutableMapIterator) and STL-style iterators
    //(QMap::const_iterator and QMap::iterator). The example above shows how to iterate over a QMap<QString, int> using a Java-style iterator:
    while(iter.hasNext()){
        iter.next();
        qDebug()<<iter.key()<<" : "<<iter.value();

    }
}
