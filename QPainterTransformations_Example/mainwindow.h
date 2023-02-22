#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

/*
 * We will learn how Transformations influence the way that QPainter renders graphics primitives.
 * Normally, the QPainter operates on the associated device's own coordinate system, but it also has good support for coordinate transformations.

   The default coordinate system of a paint device has its origin at the top-left corner.
   The x values increase to the right and the y values increase downwards. You can scale the coordinate system by a given offset using the QPainter::scale() function,
   you can rotate it clockwise using the QPainter::rotate() function and you can translate it (i.e. adding a given offset to the points)
   using the QPainter::translate() function. You can also twist the coordinate system around the origin (called shearing) using the QPainter::shear() function.
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
