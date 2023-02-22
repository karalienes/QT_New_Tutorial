#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "myitem.h"
/*
 * The QGraphicsItems class is the base class for all graphical items in a QGraphicsScene

   It provides a light-weight foundation for writing your own custom items.
   This includes defining the item's geometry, collision detection, its painting implementation and item interaction through its event handlers.
   QGraphicsItem is part of the Graphics View Framework.

   Qt provides a set of standard graphics items for the most common shapes. These are:

   QGraphicsEllipseItem provides an ellipse item
   QGraphicsLineItem provides a line item
   QGraphicsPathItem provides an arbitrary path item
   QGraphicsPixmapItem provides a pixmap item
   QGraphicsPolygonItem provides a polygon item
   QGraphicsRectItem provides a rectangular item
   QGraphicsSimpleTextItem provides a simple text label item
   QGraphicsTextItem provides an advanced text browser item
*/
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QGraphicsScene * scene;
    MyItem * item;

};
#endif // DIALOG_H


