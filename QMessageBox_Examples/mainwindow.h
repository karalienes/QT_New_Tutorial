#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

/*
 * The QMessageBox class provides a modal dialog for informing the user or for asking the user a question and receiving an answer.
   A message box displays a primary text to alert the user to a situation, an informative text to further explain the alert or to ask the user a question,
   and an optional detailed text to provide even more data if the user requests it.
   A message box can also display an icon and standard buttons for accepting a user response.

   Two APIs for using QMessageBox are provided, the property-based API, and the static functions.
   Calling one of the static functions is the simpler approach, but it is less flexible than using the property-based API,
   and the result is less informative. Using the property-based API is recommended.
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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
