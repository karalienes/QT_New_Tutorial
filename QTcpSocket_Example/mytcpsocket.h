#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class MyTcpSocket : public QObject
{
public:
    explicit MyTcpSocket(QObject * parent=0);
    void doConnect();

signals:

public slots:

private:
    QTcpSocket *socket;
};

#endif // MYTCPSOCKET_H
