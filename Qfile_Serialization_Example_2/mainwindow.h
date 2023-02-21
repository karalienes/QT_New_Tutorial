#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>
/*
 * We want to serialize a class which has two members. But unlike the previous example which is serializing primitive variables,
 * this tutorial is dealing with a class. As we may already know, we cannot do cin or cout directly on an object of a class because
 * it does not know how to input/output from/to a class.
 * Therefore, operators (<< and >>) need be overloaded.
 * This tutorial is almost the same except those operator overloadings:
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
