#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QDebug>
#include <QFile>

/*
    The QTextStream class provides a convenient interface for reading and writing text.

    QTextStream can operate on a QIODevice, a QByteArray or a QString. Using QTextStream's streaming operators,
    you can conveniently read and write words, lines and numbers.
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
    void read(QString filename);
    void write(QString filename);


private:
    Ui::MainWindow *ui;
    QString filename_obj = "/home/karali/Downloads/Qt_Tutorial/QTextStream_Example/simple.txt";
};
#endif // MAINWINDOW_H
