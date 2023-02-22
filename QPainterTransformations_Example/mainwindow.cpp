#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QPen pen1(Qt::black);
    pen1.setWidth(5);

    QPen pen2(Qt::red);
    pen2.setWidth(5);

    QPen pen3(Qt::green);
    pen3.setWidth(5);

    QPen pen4(Qt::blue);
    pen4.setWidth(5);

    int x0 = 100;
    int y0 = 100;
    int width = 200;
    int height= 200;
    QRect rect(x0,y0,width,height);

    //original rectangle
    painter.setPen(pen1);
    painter.drawRect(rect);

    //rotation
    //rotate around (0,0) which is top-left
    // rect center(xc,yc)

    int xc = x0+ width/2;
    int yc = y0+ height/2;

    // order of transformation
    // (1) translate to top-left
    // (2) rotate
    // (3) move back to(xc,yc)

    painter.translate(xc,yc);
    painter.rotate(45);
    painter.translate(-xc,-yc);

    painter.setPen(pen2);
    painter.drawRect(rect);

    //scale -> 1/2
    painter.translate(xc,yc);
    painter.scale(0.5,0.5);
    painter.translate(-xc,-yc);

    painter.setPen(pen3);
    painter.drawRect(rect);

    //Back tp the initial state
    // shear

    painter.resetTransform();
    painter.translate(xc,yc);
    painter.shear(0.5,0.5);
    painter.translate(-xc,-yc);

    painter.setPen(pen4);
    painter.drawRect(rect);

    /*
     * Note that when we do a transformation, the operation is performed based on the top-left corner.
     * So, to get the expected result, we need to take the following three steps.

    1-) Translate the object to the top-left corner.
    2-) Do transformation.
    3-) Translate the object back.

    Important:
    Any transformation is a matrix multiplication. Due to this, the order in the code should be reversed as shown in the rotation code.
    */

}
