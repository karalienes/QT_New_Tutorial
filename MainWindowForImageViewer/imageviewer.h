#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>


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
};

#endif // IMAGEVIEWER_H
