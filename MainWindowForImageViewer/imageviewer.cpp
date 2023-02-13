#include "imageviewer.h"
#include "ui_imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    //inheritance
    openAct = ui->actionOpen;
    printAct = ui->actionPrint;
    exitAct = ui->actionExit;
    zoomInAct = ui->actionZoomIn;
    zoomOutAct = ui->actionZoom_Out;
    normalSizeAct = ui->actionNormalSize;
    fitToWindowAct = ui->actionNormalSize;
    aboutAct = ui->actionAbout;
    aboutQtAct = ui->actionAbout_Qt;

    //Qt SignalAndSlot
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));
    connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

//    QImage image(":/qrc/logo1332.png");
//    ui->image_label->setPixmap(QPixmap::fromImage(image));

    imageLabel = new QLabel(this);
/*
 * The setBackgroundRole() method let us use a color role for the background, which means one of the predefined color
 * of the style applied to the widget.
*/
    imageLabel->setBackgroundRole(QPalette::Base);

/*
 * The setSizePolicy() sets the size policy to policy.
 * The size policy describes how the item should grow horizontally and vertically when arranged in a layout.
 * We set imageLabel's size policy to ignored, making the users able to scale the image to whatever
 * size they want when the Fit to Window option is turned on. Otherwise,
 * the default size policy (preferred) will make scroll bars appear when the scroll area becomes smaller than the label's minimum size hint.
*/
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
/*
 * The setScaledContents(bool) decides whether the label will scale its contents to fill all available space.
 * When enabled and the label shows a pixmap, it will scale the pixmap to fill the available space.
 * This property's default is false. Here, we ensure that the label will scale its contents to fill all available space,
 * to enable the image to scale properly when zooming. If we omitted to set the imageLabel's scaledContents property,
 * zooming in would enlarge the QLabel, but leave the pixmap at its original size, exposing the QLabel's background.
 */
    imageLabel->setScaledContents(true);


    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

///The setCentralWidget(ui->scrollArea) make the scrollArea as a central widget of MainWindow.
    setCentralWidget(scrollArea);

    setWindowTitle(tr("Image Viewer"));
    resize(500,500);

}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *=factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor< 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));

    scrollBar->setValue(int(factor * scrollBar->value()));
}

void ImageViewer::open()
{
    /*
     * "All files (*.*);;BMP (*.bmp);;CUR (*.cur);;GIF (*.gif);;ICNS (*.icns);;ICO (*.ico);;JPEG (*.jpeg);;
     * JPG (*.jpg);;PBM (*.pbm);;PGM (*.pgm);;PNG (*.png);;PPM (*.ppm);;SVG (*.svg);;SVGZ (*.svgz);;TGA (*.tga);;TIF (*.tif);;
     * TIFF (*.tiff);;WBMP (*.wbmp);;WEBP (*.webp);;XBM (*.xbm);;XPM (*.xpm)"
     */
    qDebug()<<"Open()";
    QString selfilter = tr("JPEG (*.jpg *.jpeg)");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),
                                                    tr("JPEG (*.jpg *.jpeg);; PNG (*.png);; BMP (*.bmp);; All files (*.*)"),&selfilter);

    if(!fileName.isEmpty()){
        QImage image(fileName);
        if(image.isNull()){
            QMessageBox::information(this,tr("Image Viewer"),tr("Cannot load %1. (%2.)")
                                     .arg(fileName).arg(QDateTime::currentDateTime().toString()));
            return ;
        }
        imageLabel->setPixmap(QPixmap::fromImage(image));
        scaleFactor = 1.0;

        printAct->setEnabled(true);
        fitToWindowAct->setEnabled(true);

        if(!fitToWindowAct->isChecked()){
            /*
             * Adjusts the size of the widget to fit its contents.
               This function uses sizeHint() if it is valid, i.e., the size hint's width and height are >= 0.
               Otherwise, it sets the size to the children rectangle that covers all child widgets (the union of all child widget rectangles).
             */
            imageLabel->adjustSize();
        }
    }
}

void ImageViewer::print()
{

}

void ImageViewer::close()
{

}

void ImageViewer::zoomIn()
{
    scaleImage(1.25);

}

void ImageViewer::zoomOut()
{
    scaleImage(0.8);

}

void ImageViewer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageViewer::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        normalSize();
    }
    updateActions();
}

void ImageViewer::about()
{

}

void ImageViewer::aboutQt()
{

}
