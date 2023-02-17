#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __init__();
    mkpath_method();
    entryInfoList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::__init__()
{
    // forward slash for directory separator
    QDir dir1("C:/Qt");
    QDir dir2("C:/Qt/test");
    qDebug() << dir1.exists() << dir2.exists();

    //QFileInfoList QDir::drives() returns a list of the root directories on this system.

    QDir dir3;
    foreach(QFileInfo item, dir3.drives() )
    {
        qDebug() << item.absoluteFilePath();
    }
}

void MainWindow::mkpath_method()
{
    QString path = "/home/karali/deneme";

    QDir dir(path);

    if(!dir.exists()){
        qDebug()<<"Creating" << path << " directory";
        dir.mkpath(path);
    }
    else {
        qDebug()<<path<< " already exits";
    }
}

/*
 * QFileInfoList QDir::entryInfoList(const QStringList & nameFilters, Filters filters = NoFilter, SortFlags sort = NoSort)
 * const returns a list of QFileInfo objects for all the files and directories in the directory, ordered according to
 * the name and attribute filters previously set with setNameFilters() and setFilter(), and sorted according to the flags set with setSorting().

   The name filter, file attribute filter, and sorting specification can be overridden using the nameFilters, filters, and sort arguments.

   entryInfoList() returns an empty list if the directory is unreadable, does not exist, or if nothing matches the specification.
   void MainWindow::entryInfoList()
*/
void MainWindow::entryInfoList()
{
    QString path = "/home/karali/WidgetAnimation";
    QDir dir(path);

    foreach(QFileInfo item, dir.entryInfoList() )
    {
        if(item.isDir())
            qDebug() << "Dir: " << item.absoluteFilePath();
        if(item.isFile())
            qDebug() << "File: " << item.absoluteFilePath();
    }
}
