#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void __init__();
    MyThread *mThread;

private slots:
    void on_start_button_clicked();

    void on_stop_button_clicked();
public slots:
    void onValueChanged(int);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
