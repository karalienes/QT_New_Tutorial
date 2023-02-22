#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
/*
 * The QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
 * QGraphicsView visualizes the contents of a QGraphicsScene in a scrollable viewport. QGraphicsView is part of the Graphics View Framework.
 * The QGraphicsScene class provides a surface for managing a large number of 2D graphical items.
 * The class serves as a container for QGraphicsItems. It is used together with QGraphicsView for visualizing graphical
 * items, such as lines, rectangles, text, or even custom items, on a 2D surface. QGraphicsScene is part of the Graphics View Framework.
*/


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void __init__();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem * ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};
#endif // MAINWINDOW_H
