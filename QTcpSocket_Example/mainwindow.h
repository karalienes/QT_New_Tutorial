#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytcpsocket.h"
/*
In this tutorial, we will learn how to download a file using QTcpSocket. We're taking blocking approach (synchronous).
In other words, we use waitFor...() functions (e.g., QTcpSocket::waitForConnected()) until the operation has completed, instead of connecting to signals.

The QTcpSocket class provides a TCP socket.

TCP (Transmission Control Protocol) is a reliable, stream-oriented, connection-oriented transport protocol.
It is especially well suited for continuous transmission of data.

QTcpSocket is a convenience subclass of QAbstractSocket that allows you to establish a TCP connection and transfer streams of data.
See the QAbstractSocket documentation for details.

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
    MyTcpSocket *tcpsocket_obj;
};
#endif // MAINWINDOW_H
