#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
/*
The main() starts with only the GUI thread running and it should terminate with only the GUI thread running.
Exiting the program when another thread is still busy is a programming error, and therefore, wait() is called which blocks
the calling thread until the run() method has completed.

bool QThread::wait(unsigned long time = ULONG_MAX)

    *The wait() blocks the thread until either of these conditions is met:

    1-) The thread associated with this QThread object has finished execution (i.e. when it returns from run()).
        This function will return true if the thread has finished. It also returns true if the thread has not been started yet.

    2-) time milliseconds has elapsed. If time is ULONG_MAX (the default), then the wait will never timeout (the thread must return from run()).
        This function will return false if the wait timed out.

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

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
