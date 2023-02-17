#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDebug>
/*
 * The QList class is a template class that provides lists.
   QList<T> is one of Qt's generic container classes. It stores a list of values and provides fast index-based access as well as fast insertions and removals.
   Although it is implemented as an array-list, it provides very fast prepends and appends. For most applications, QList is the best type to use.
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
