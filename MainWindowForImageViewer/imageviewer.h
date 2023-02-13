#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "qlabel.h"
#include "qscrollarea.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QScrollBar>


//The example demonstrates how QLabel's ability to scale its contents (QLabel::scaledContents),
//and QScrollArea's ability to automatically resize its contents (QScrollArea::widgetResizable),
//can be used to implement zooming and scaling features. In addition the example shows how to use QPainter to print an image.


// QLabel::sclaedContents --> QLabel is ability to scale it's contensç.
// QScrollArea::widgetResizable --> QScrollArea is ability to automatically resize it's contents.

/*
 * QLabel is typically used for displaying text, but it can also display an image.
 * QScrollArea provides a scrolling view around another widget. If the child widget exceeds the size of the frame, QScrollArea automatically provides scroll bars.
*/
namespace Ui {
class ImageViewer;
}

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

private:
    Ui::ImageViewer *ui;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QAction *openAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    double scaleFactor;


public slots:
    void open();
    void print();
    void close();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();
    void aboutQt();
};

#endif // IMAGEVIEWER_H
