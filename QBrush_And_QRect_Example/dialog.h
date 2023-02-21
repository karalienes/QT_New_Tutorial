#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QRect>
#include <QBrush>
/*
 * The QBrush class defines the fill pattern of shapes drawn by QPainter. A brush has a style, a color, a gradient and a texture.


   Example
 * A QRect can be constructed with a set of left, top, width and height integers:
   QRect::QRect(int x, int y, int width, int height)

   or from a QPoint and a QSize:
   QRect::QRect(const QPoint & topLeft, const QSize & size)

   The following code creates two identical rectangles.
   QRect r1(100, 200, 11, 16);
   QRect r2(QPoint(100, 200), QSize(11, 16));
*/
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *e);
};
#endif // DIALOG_H
