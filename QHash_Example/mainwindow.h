#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QDebug>
/*
 * The QHash class is a template class that provides a hash-table-based dictionary.
   QHash<Key, T> is one of Qt's generic container classes. It stores (key, value) pairs and provides very fast lookup of the value associated with a key.

   QHash provides very similar functionality to QMap. The differences are:

   1-) QHash provides faster lookups than QMap.
   2-) When iterating over a QMap, the items are always sorted by key. With QHash, the items are arbitrarily ordered.
   3-) The key type of a QMap must provide operator<(). The key type of a QHash must provide operator==() and a global hash function called qHash().
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
