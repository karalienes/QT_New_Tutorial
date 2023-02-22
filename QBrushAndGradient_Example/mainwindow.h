#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>

/*
 * The QGradient class is used in combination with QBrush to specify gradient fills. Qt currently supports three types of gradient fills:

 1-) Linear gradients interpolate colors between start and end points.
 2-) Simple radial gradients interpolate colors between a focal point and end points on a circle surrounding it.
 3-) Extended radial gradients interpolate colors between a center and a focal circle.
 4-) Conical gradients interpolate colors around a center point.
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
