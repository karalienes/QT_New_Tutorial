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
    //A string create
    QString str = "A,B,C,D,E,F,G";

    qDebug()<<"QString str = "<< str;

    QStringList List;
    qDebug()<< "Split str using ',' as a delimeter";

    //To break up a string into a string list, we used the QString::split() function. The argument to split can be a single character, a string, or a QRegExp.
    List = str.split(",");

    foreach(QString item, List){
        qDebug()<<"List items = "<<item;
    }

    qDebug()<< "Replace one of the List item";

    //To concatenate all the strings in a string list into a single string (with an optional separator), we used the join() function.
    List.replaceInStrings("C","CCCC");
    qDebug()<<"List = "<<List;

    qDebug()<<"Join all items in the List";

    //The replaceInStrings() function calls QString::replace() on each string in the string list in turn.
    QString joinedString = List.join(", ");
    qDebug()<<"joined string = "<<joinedString;

}
