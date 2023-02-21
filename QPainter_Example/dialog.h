#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
/*
 * The common use of QPainter is inside a widget's paint event: Construct and customize (e.g. set the pen or the brush) the painter.
 * QPainter provides highly optimized functions to do most of the drawing GUI programs require.
 * It can draw everything from simple lines to complex shapes like pies and chords. It can also draw aligned text and pixmaps.
 * */
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
protected:
    void paintEvent(QPaintEvent *e);
};
#endif // DIALOG_H
