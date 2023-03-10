#ifndef MYITEM_H
#define MYITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>

class MyItem :public QGraphicsItem
{
public:
    MyItem();

    QRectF boudingRect() const;

    //overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    //item state
    bool Pressed;

protected:

    //overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MYITEM_H
