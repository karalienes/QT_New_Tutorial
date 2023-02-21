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

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    int left = 100;
    int top = 50;
    int width = 200;
    int height = 150;

    //r1 and r2 are same

    QRect r1(left,top,width,height);
    QRect r2(QPoint(left,top),QSize(width,height));

    QBrush brush(Qt::red,Qt::Dense7Pattern);


    painter.setPen(Qt::blue);
    painter.drawRect(r1);
    painter.fillRect(r1,brush);

    //r1 as a bouding box
    painter.drawEllipse(r2);
}
