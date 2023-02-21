#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLinkedList>
#include <QDebug>
#include <QString>
/*
 * The QLinkedList class is a template class that provides linked lists.
 * QLinkedList<T> is one of Qt's generic container classes. It stores a list of values and provides iterator-based access
 * as well as constant time insertions and removals.
*/
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void __init__();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
