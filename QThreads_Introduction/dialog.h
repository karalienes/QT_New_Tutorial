#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

/*
 * GUI Thread and Worker Thread

Each program has one thread when it is started. This thread is called the main thread or GUI thread in Qt applications.
The Qt GUI must run in this thread. All widgets and several related classes, for example QPixmap, don't work in secondary threads.
A secondary thread is commonly referred to as a worker thread because it is used to offload processing work from the main thread.

 * Simultaneous Access to Data

If two threads have a pointer to the same object, it is possible that both threads will access that object at the same
time and this can potentially destroy the object's integrity. Simultaneous execution of operations by different threads on one object must be prevented.

 * Use Cases

There are basically two use cases for threads:
    1-) Make processing faster by making use of multicore processors.
    2-) Keep the GUI thread or other time critical threads responsive by offloading long lasting processing or blocking calls to other threads.

 * When to Use Alternatives to Threads

Before creating threads to solve certain problems, possible alternatives should be considered.

    * QEventLoop::processEvents()	--> Calling QEventLoop::processEvents() repeatedly during a time-consuming calculation prevents GUI blocking.
      However, this solution doesn't scale well because the call to processEvents() may occur too often, or not often enough, depending on hardware.
    * QSocketNotifier QNetworkAccessManager QIODevice::readyRead()	--> This is an alternative to having one or multiple threads, each with a blocking
      read on a slow network connection. As long as the calculation in response to a chunk of network data can be executed quickly, this reactive
      design is better than synchronous waiting in threads. Reactive design is less error prone and energy efficient than threading.
      In many cases there are also performance benefits.
    * QTimer --> Background processing can sometimes be done conveniently using a timer to schedule execution of a slot at some point in the future.
      A timer with an interval of 0 will time out as soon as there are no more events to process.

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
