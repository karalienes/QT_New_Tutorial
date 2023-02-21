#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPolygon>
#include <QPainterPath>
#include <QBrush>
/*
 * The QPainterPath class provides a container for painting operations, enabling graphical shapes to be constructed and reused.

   A painter path is an object composed of a number of graphical building blocks, such as rectangles, ellipses, lines, and curves.
   Building blocks can be joined in closed subpaths, for example as a rectangle or an ellipse.
   A closed path has coinciding start and end points. Or they can exist independently as unclosed subpaths, such as lines and curves.
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

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *e);
};
#endif // MAINWINDOW_H
