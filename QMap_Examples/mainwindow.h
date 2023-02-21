#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QDebug>

/*
 * The QMap class is a template class that provides a red-black-tree-based dictionary.
 * QMap<Key, T> is one of Qt's generic container classes. It stores (key, value) pairs and provides fast lookup of the value associated with a key.
 * */
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
