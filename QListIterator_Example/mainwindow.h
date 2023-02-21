#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QListIterator>
#include <QDebug>
/*
QList has both Java-style iterators and STL-style iterators. The Java-style iterators are more high-level
and easier to use than the STL-style iterators; on the other hand, they are slightly less efficient.

The QListIterator class provides a Java-style const iterator for QList.

QListIterator<T> allows us to iterate over a QList<T>. If we want to modify the list as we iterate over it, use QMutableListIterator<T> instead.
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
    void init();
    void peekNext_method(QListIterator<int> data);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
