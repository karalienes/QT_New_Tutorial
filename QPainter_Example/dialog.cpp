#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//In the paintEvent(), we created QPainter object. Then, we the pen color, font type, font size, and the text itself with alignment.
void Dialog::paintEvent(QPaintEvent *e)
{

    //Example-1
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial",120));
    painter.drawText(rect(),Qt::AlignCenter,"Enes");

    //Example-2
    QPainter MyPainter(this);

    QPen PointPen(Qt::red);
    PointPen.setWidth(5);

    QPen LinePen(Qt::green);
    LinePen.setWidth(2);

    QPoint p1;
    p1.setX(100);
    p1.setY(100);

    QPoint p2;
    p2.setX(300);
    p2.setY(300);

    MyPainter.setPen(PointPen);
    MyPainter.drawPoint(p1);
    MyPainter.drawPoint(p2);

    MyPainter.setPen(LinePen);
    MyPainter.drawLine(p1,p2);

    QPen LinePen2(Qt::black);
    LinePen2.setStyle(Qt::DashDotLine);
    LinePen2.setWidth(3);

    MyPainter.setPen(LinePen2);
    MyPainter.drawLine(QPoint(300,100),QPoint(100,200));
}

