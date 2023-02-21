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
/* Note that the QMutableListIterator constructor takes a QList as argument.
 * After construction, the iterator is located at the very beginning of the list (before the first item).
 * We used remove() to remove items as we iterate over the list. To modify the value of an item, we used setValue().
 * The toFront() moves the iterator to the front of the container (before the first item).
 * */
void MainWindow::init(){
    QList<int> List;

    for(int i=0;i<10;i++){
        List.append(i);
    }

    // The QMutableListIterator constructor takes a QList
    // as argument. After construction, the iterator
    // is located at the very beginning of the list
    // (before the first item)
    QMutableListIterator<int> mIter(List);

    qDebug()<<"Modifying element while moving forward...";
    while(mIter.hasNext()){
        // The next() function returns the next item
        // in the list and advances the iterator.
        // To remove items as we iterate over the list,
        // we use remove().
        // To modify the value of an item,
        // we use setValue().

        int val = mIter.next();

        //odd:remove, even: negative
        if(val %2 == 1){
            mIter.remove();
        }
        else{
            mIter.setValue(-val);
        }
    }

    qDebug()<<"Start again from front...";
    //toFront() voves the iterator to the  front
    // of the container( before the first item).
    mIter.toFront();

    qDebug()<<"Forward";
    while(mIter.hasNext()){
        qDebug()<<mIter.next();
    }
}

