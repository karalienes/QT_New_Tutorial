#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ActionDemo_triggered();

    void on_ActionDemo2_triggered();

private:
    Ui::MainWindow *ui;
    MyDialog *objMyDialogActionDemo2;
};
#endif // MAINWINDOW_H
