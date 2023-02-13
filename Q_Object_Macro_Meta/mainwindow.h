#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//The Q_OBJECT macro must appear in the private section of a class definition
//that declares its own signals and slots or that uses other services provided by Qt's meta-object system.
//So, it sounds like we need it to use signal and slot, and probably for other purposes (meta-object related) as well.

//All classes that contain signals or slots must mention Q_OBJECT at the top of their declaration.
//They must also derive (directly or indirectly) from QObject.
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    //Actually, the Q_OBJECT macro is only required if meta-object code has to be produced by the moc tool in order to use the
    //signals and slots mechanism, the run-time type information, the dynamic property system and translating features for internationalization.

    //While it is possible to use QObject as a base class without the Q_OBJECT macro and without meta object code,
    //neither signals and slots nor the other features described here will be available if the Q_OBJECT macro is not used.

    //In general, it seems that all Qt developers have been strongly recommend to use Q_Object for every subclass of
    //QObject whether or not they actually use the features listed above.

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
