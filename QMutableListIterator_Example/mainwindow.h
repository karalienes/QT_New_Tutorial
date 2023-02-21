#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 * The QMutableListIterator class provides a Java-style non-const iterator for QList.
   QMutableListIterator<T> allows us to iterate over a QList<<T>> and modify the list.
   If we don't want to modify the list (or have a const QList), use the slightly faster QListIterator<T> instead.
   */
#include <QMainWindow>
#include <QList>
#include <QDebug>
#include <QListIterator>
#include <QMutableListIterator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void init();
};
#endif // MAINWINDOW_H
