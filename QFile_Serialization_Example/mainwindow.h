#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QMap>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Save(QString filename);
    void Load(QString filename);

private:
    Ui::MainWindow *ui;
    QString filename_obj = "/home/karali/Documents/QT_New_Tutorial/QFile_Serialization_Example/sample.txt";
};
#endif // MAINWINDOW_H
