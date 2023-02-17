#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
/*
 * The Qt resource system is a platform-independent mechanism for storing binary files in the application's executable.
 * This is useful if our application always needs a certain set of files (icons, translation files, etc.) and we don't want to run the risk of losing the files.
   The resource system is based on tight cooperation between qmake, rcc (Qt's resource compiler), and QFile.
   The resources associated with an application are specified in a .qrc file, an XML-based file
   format that lists files on the disk and optionally assigns them a resource name that the application must use to access the resource.
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
    void write(QString filename);
    void read(QString filename);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
