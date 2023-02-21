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

    QPolygon poly;

    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)\
         << QPoint(0, 85);

    //Qpen: style() width(), brush(), capStyle() and joinStyle()
    QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    painter.setPen(pen);

    //Brush
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::Dense3Pattern);

    //Fill polygon
    QPainterPath path;
    path.addPolygon(poly);

    //Draw polygon
    painter.drawPolygon(poly);
    painter.fillPath(path,brush);

}

