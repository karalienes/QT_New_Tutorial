#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProgressDialog>
#include "mytask.h"

/*
 * We'll start with Qt Gui Application using QDialog as a launching pad for the two types of QProgressDialogs: Modal and Modeless.
 * The QProgressDialog class provides feedback on the progress of a slow operation.
   A progress dialog is used to give the user an indication of how long an operation is going to take,
   and to demonstrate that the application has not frozen. It can also give the user an opportunity to abort (cancel) the operation.

   A common problem with progress dialogs is that it is difficult to know when to use them; operations take different amounts of time on different hardware.
   QProgressDialog offers a solution to this problem: it estimates the time the operation will take (based on time for steps),
   and only shows itself if that estimate is beyond minimumDuration() (4 seconds by default).

   A modal QProgressDialog is simpler to use for the programmer compared to a modeless QProgressDialog.

   The steps are:

   1-) Do the operation in a loop.
   2-) Call setValue() at intervals.
   3-) Check for cancellation with wasCanceled().
   In our example, the modal QProgressDialog is launched when a modal-button on the lauching dialog is clicked.

*/
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_Modal_button_clicked();

    void on_Modeless_buttn_clicked();

private:
    Ui::Dialog *ui;
    MyTask * myTask;
};
#endif // DIALOG_H
