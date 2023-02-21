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

//Returning a mimetype for a given QFile
QString MainWindow::mimeReturn(const QFile &file)
{
    QMimeDatabase mimeDatabase;
    QMimeType mimeType;


/*
 * We have two types of methods for QMimeDatabase::mimeTypeForFile(), in this example, we're using the 1st form:

 * QMimeType mimeTypeForFile(const QFileInfo & fileInfo, MatchMode mode = MatchDefault) const
 * QMimeType mimeTypeForFile(const QString & fileName, MatchMode mode = MatchDefault) const
 *
 * The inherit() function:
   bool QMimeType::inherits(const QString & mimeTypeName) const
   returns true if this mimetype is mimeTypeName, or inherits mimeTypeName, or mimeTypeName is an alias for this mimetype.
*/
   mimeType = mimeDatabase.mimeTypeForFile(QFileInfo(file));

    //mp4 mpg4
    if(mimeType.inherits("video/mp4"))
        return "video/mp4";
    //mpeg mpg mpe
    else if(mimeType.inherits("video/mpeg"))
        return "video/mpeg";
    //ogv
    else if(mimeType.inherits("video/ogg"))
        return "video/ogg";
    //qt,mov
    else if(mimeType.inherits("video/quicktime"))
        return "video/quicktime";
    //avi
    else if(mimeType.inherits("video/x-msvideo"))
        return "video/x-msvideo";
    //flv
    else if(mimeType.inherits("video/x-flv"))
        return "video/x-flv";
    //webm
    else if(mimeType.inherits("video/webm"))
        return "video/webm";
    //text
    else if(mimeType.inherits("text/plain"))
        return "text";

    else
        return " ";

}

void MainWindow::__init__()
{
    QStringList List;
    List<<"1.txt"<<"2.mp4"<<"3.webm"<<"4.mov"<<"5.flv";

    foreach(QString item, List){
        qDebug()<<"Item"<<" ===> "<<mimeReturn(item);
    }
}
