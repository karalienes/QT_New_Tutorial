#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>
#include <QDebug>
/*
 * Multipurpose Internet Mail Extensions (MIME) is an Internet standard that extends the format of email. MIME's use, however,
 * has grown beyond describing the content of email and now is often used to describe content type in general including
 * for the web (see Internet media type) and as a storage for rich content in some commercial products.
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
    QString mimeReturn(const QFile& file);
    void __init__();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
