#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    __init__();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::__init__()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addRect(100,0,80,100,outlinePen, blueBrush);

    //addEllipse(x,y,w,h,pen,brush)
    ellipse = scene->addEllipse(0,-100,300,60,outlinePen,greenBrush);

    text = scene->addText("github.com/karalienes",QFont("Arial",20));
    //movable text
    text->setFlag(QGraphicsItem::ItemIsMovable);
}
