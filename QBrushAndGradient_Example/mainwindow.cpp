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

    // Gradient used with QBrush

    QLinearGradient linearGrad(QPointF(100,100),QPointF(200,200));
    linearGrad.setColorAt(0,Qt::white);
    linearGrad.setColorAt(0.5,Qt::green);
    linearGrad.setColorAt(1,Qt::black);

    QRect rect_linear(50,50,200,200);
    painter.fillRect(rect_linear,linearGrad);

    //QRadialGradient(const QPointF &center, qreal radius);
    QRadialGradient radialGrad(QPointF(400,150),20);
    radialGrad.setColorAt(0,Qt::white);
    radialGrad.setColorAt(0.5,Qt::green);
    radialGrad.setColorAt(1,Qt::black);

    QRect rect_radial(300,50,200,200);
    painter.fillRect(rect_radial,radialGrad);

    // QConicalGradient(const QPointF &center, qreal startAngle);
    QConicalGradient conicalGrad(QPointF(650,150),180);
    conicalGrad.setColorAt(0,Qt::white);
    conicalGrad.setColorAt(0.5,Qt::green);
    conicalGrad.setColorAt(1,Qt::black);

    QRect rect_conical(550,50,200,200);
    painter.fillRect(rect_conical, conicalGrad);

}
