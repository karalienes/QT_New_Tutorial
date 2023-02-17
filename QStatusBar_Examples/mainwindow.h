#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
/*
 * The QStatusBar class provides a horizontal bar suitable for presenting status information.
   Temporary - briefly occupies most of the status bar. Used to explain tool tip texts or menu entries.
   Normal - occupies part of the status bar and may be hidden by temporary messages. Used to display the page and line number in a word processor.
   Permanent - is never hidden. Used for important mode indications, for example, some applications put a Caps Lock indicator in the status bar.
   Typically, a request for the status bar functionality occurs in relation to a QMainWindow object. QMainWindow provides a main application window,
   with a menu bar, tool bars, dock widgets and a status bar around a large central widget. The status bar can be retrieved using the QMainWindow::statusBar() function,
   and replaced using the QMainWindow::setStatusBar() function.

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

private slots:
    void on_actionMyMenuAction_triggered();

private:
    Ui::MainWindow *ui;

    //add references to Label and ProgressBar
    QLabel *statusLabel;
    QProgressBar *statusProgressBar;

};
#endif // MAINWINDOW_H
