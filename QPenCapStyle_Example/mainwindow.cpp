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
    QPen pen(Qt::black);
    pen.setWidth(20);

    QPoint start(50,50);
    QPoint end(350,50);

    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.drawLine(start,end);

    start.setY(100);
    end.setY(100);
    pen.setCapStyle(Qt::SquareCap);
    painter.setPen(pen);
    painter.drawLine(start,end);

    start.setY(150);
    end.setY(150);
    pen.setCapStyle(Qt::RoundCap);
    painter.setPen(pen);
    painter.drawLine(start,end);
}
