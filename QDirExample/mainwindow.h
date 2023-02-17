#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>

/*
 * The QDir class provides access to directory structures and their contents.
   A QDir is used to manipulate path names, access information regarding paths and files, and manipulate the underlying file system. It can also be used to access Qt's resource system.
   Qt uses "/" as a universal directory separator in the same way that "/" is used as a path separator in URLs.
   If you always use "/" as a directory separator, Qt will translate your paths to conform to the underlying operating system.
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
    void __init__();
    void mkpath_method();
    void entryInfoList();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
