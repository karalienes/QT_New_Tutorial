#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QList<int> List;

    for(int i=0;i<10;i++){
        List.append(i);
    }

    // The QListIterator constructor takes a QList
    // as argument. After construction, the iterator
    // is located at the very beginning of the list
    // (before the first item)
    QListIterator<int> iter(List);

    qDebug()<<"Forward...";
    //The hasNext() returns true if there is at least one item ahead of the iterator, i.e. the iterator is not at the back of the container; otherwise returns false.
    while(iter.hasNext()){
        // The next() function returns the next item
        // in the list and advances the iterator.
        /*
          The next() function returns the next item in the list and advances the iterator. Unlike STL-style iterators,
          Java-style iterators point between items rather than directly at items.
          The first call to next() advances the iterator to the position between the first and second item,
          and returns the first item; the second call to next() advances the iterator to the position between the second and third item,
          and returns the second item; and so on.
          */
        qDebug() << iter.next();
    }

    qDebug()<<"Backward...";
    //The hasPrevious() returns true if there is at least one item behind the iterator, i.e. the iterator is not at the front of the container; otherwise returns false.
    while(iter.hasPrevious()){
        //The next() function returns the next item
        //in the list and advances the iterator.
        //The previous() returns the previous item and moves the iterator back by one position.
        //Calling this function on an iterator located at the front of the container leads to undefined results.

        qDebug()<<iter.previous();
    }
    peekNext_method(iter);
}

void MainWindow::peekNext_method(QListIterator<int> data)
{
    qDebug() << "Forward while peeking...";

    //The peekNext() Returns the next item without moving the iterator. Calling this function on an iterator located at the back of the container
    //leads to undefined results.
    while(data.hasNext())
    {
        qDebug() << "peek next ..." << data.peekNext();
        qDebug() << data.next();
    }
}
