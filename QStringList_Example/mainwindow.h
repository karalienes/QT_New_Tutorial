#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QStringList>
/*
    QStringList inherits from QList<QString>. Like QList, QStringList is implicitly shared.
    It provides fast index-based access as well as fast insertions and removals. Passing string lists as value parameters is both fast and safe.

    All of QList's functionality also applies to QStringList. For example, you can use isEmpty() to test whether the list is empty,
    and you can call functions like append(), prepend(), insert(), replace(), removeAll(), removeAt(), removeFirst(), removeLast(), and removeOne()
    to modify a QStringList. In addition, QStringList provides a few convenience functions that make handling lists of strings easier.
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
