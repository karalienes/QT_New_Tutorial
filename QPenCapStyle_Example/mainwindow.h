#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

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
    //We will override QWidget::paintEvent(). That's because whenever there is a paint event, we can draw whatever we want.
    //In other words, we let Qt know what to draw on our dialog box at the paint event.

    void paintEvent(QPaintEvent *e);
};
#endif // MAINWINDOW_H
